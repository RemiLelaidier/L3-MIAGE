/** Fichier server.c
 *  Cree un serveur pour communiquer avec un ou des clients
 *  V1 : Client unique
 *  V2 : Client multiples */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Permet de calculer
void calc(char *operande, int cnb1, int cnb2, char* out){
    int res = 0;
    switch(*operande){
        case '+':
            res = cnb1 + cnb2;
            break;
        case '-':
            res = cnb1 - cnb2;
            break;
        case '/':
            res = cnb1 / cnb2;
            break;
        case '*':
            res = cnb1 * cnb2;
            break;
    }
    sprintf(out, "%d", res);
}

// Represente une variable
struct variable{
    char nom[5];
    int valeur;
};

// Fonction pour recuperer la position d'une variable en fonction de son nom
int getPosByName(char *nom, struct variable *listeVar, int taille){
    int i = 0;
    while(i < taille){
        if(strcmp(listeVar[i].nom, nom) == 0){
            return i;
        }
        i++;
    }
    return -1;
}

// Fonction pour recuperer une variable en fonction de son nom
struct variable getStructByName(char *nom, struct variable *listeVar, int taille){
    int i = 0;
    while(i < taille){
        if(strcmp(listeVar[i].nom, nom) == 0){
            return listeVar[i];
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    int looptime = 0;                                                           /* Numero de la boucle */
    socklen_t ls = sizeof(struct sockaddr_in);                                  /* Taille des adresses */

    /*---- Caracterisation de la socket d'émission ----------*/
    int sd0;                                                                    /* Descripteur  */
    int ps0 = 0;                                                             /* Port         */
    struct sockaddr_in adr0, *padr0 = &adr0;                                    /* Adresse  */

    /*---- Buffers pour Messages -------------------------------*/
    char msg_in[30] = "0";                                                       /* Message recu de "0" a "99" */
    char msg_out[30] = "0";                                                      /* Message a envoyer "0" a "99" */



    /*---- (0) - Verifications de base ----*/
    if (argc != 2) {
        fprintf(stderr, "Syntaxe d'appel : server <port> \n");
        exit(2);
    }
    ps0 = atoi(argv[1]);

    /*---- (1) Concernant la socket d'émission ----
        ---- (a) Creation du socket : Domaine AF_INET, type DGRAM, proto. par defaut ----*/
    if ((sd0 = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
        perror("[SOCK_DGRAM, AF_INET, 0]");
    else
        printf("socket [SOCK_DGRAM, AF_INET, 0] creee\n");

    /*  ---- (b) Preparation de l'adresse d'attachement ----*/
    adr0.sin_family = AF_INET;
    adr0.sin_addr.s_addr = htonl(INADDR_ANY);                                   /* Format reseau */
    adr0.sin_port = htons(ps0);                                          /* Format reseau */

    /*  ---- (c) Demande d'attachement de la socket (specifique serveur)----*/
    if (bind(sd0, (struct sockaddr *) (padr0), ls) == -1) {
        perror("Attachement de la socket impossible");
        close(sd0);                                                             /* Fermeture de la socket */
        exit(2);                                                                /* Le processus se termine anormalement.*/
    }

    /*  ---- (d) Recuperation de l'adresse effective d'attachement ----*/
    getsockname(sd0, (struct sockaddr *) padr0, &ls);

    printf("Le serveur ecoute sur le port %d\n", ntohs(padr0->sin_port));

    // Initialisation des variables
    int taille = 3;
    struct variable listeVar[taille];
    int nbMaxVar = 0;

    /*---- (3) Boucle emission-reception type serveur----*/
    for (;;) {
        char res[30];
        /*--- Calcul -----------------------------------------*/
        char cnb1[5], cnb2[5], operande[2];

        printf("\n------------------\n");

        /*---- (a) Reception ----*/
        printf("Attente de reception ... ");
        if (recvfrom(sd0, msg_in, sizeof(msg_in), 0, (struct sockaddr *) padr0, &ls) == -1)
            printf("inachevee : %s !\n", msg_in);
        else {
            printf("recue : valeur = %s !\nRecu de %s sur le port %d", msg_in, inet_ntoa(padr0->sin_addr),
                   ntohs(padr0->sin_port));

            /*---- (b) Traitement ----*/
            sscanf(msg_in, "%s %s %s", cnb1, operande, cnb2);

            // 1er cas - Si on fait une assignation de variable
            int pos1 = 0;
            int pos2 = 0;
            if(strcmp(operande, "=") == 0){
                // Si le premier parametre est une variable connue
                if(pos1 = getPosByName(cnb1, listeVar, taille) != -1){
                        listeVar[pos1].valeur = atoi(cnb2);
                        strcpy(res, "Variable redefinie");
                }
                    // Sinon on l'assigne
                else if(nbMaxVar != taille){
                    strcpy(listeVar[nbMaxVar].nom, cnb1);
                    listeVar[nbMaxVar].valeur = atoi(cnb2);
                    nbMaxVar++;
                    strcpy(res, "Nouvelle variable definie\0");
                }
                    // Si on a trop de variable
                else{
                    strcpy(res,"Erreur, trop de var\0");
                }
            }
            // 2eme Cas - Si on fait un calcul ou on veut connaitre la valeur d'une variable
            else{
                pos1 = getPosByName(cnb1, listeVar, taille);
                pos2 = getPosByName(cnb2, listeVar, taille);
                // Si on veut connaitre la valeur d'un parametre
                if((pos1 != -1) && (pos2 != -1)){
                    calc(operande, listeVar[pos1].valeur, listeVar[pos2].valeur, res);
                }
                else if(pos1 != -1){
                    calc(operande, listeVar[pos1].valeur, atoi(cnb2), res);
                }
                else if(pos2 != -1){
                    calc(operande, atoi(cnb1), listeVar[pos2].valeur, res);
                }
                else{
                    calc(operande, atoi(cnb1), atoi(cnb2), res);
                }
            }

            strcpy(msg_out, res);

            /*---- (c) Emission ----*/
            printf("\n\nEnvoi(%d) ... ", looptime);
            if (sendto(sd0, msg_out, sizeof(msg_out), 0, (struct sockaddr *) padr0, ls) > 0)
                printf("termine : message/valeur = %s !\n", msg_out);
            else
                printf("inacheve : %s !\n", msg_out);
            looptime++;
        }
    }
}