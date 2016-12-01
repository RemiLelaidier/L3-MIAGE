//
// Created by leetspeakv2 on 29/09/16.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//*******************************
// Fonction de Parite
//*******************************
int make_bit_parite(char caractere){
    int lettreBit = (int) caractere;
    int count = 0;
    // On fait la somme des bits representant notre char
    while (lettreBit != 0 && lettreBit != 1) {
        count += lettreBit % 2;
        lettreBit = lettreBit/2;
    }
    return count+lettreBit;
}

//*******************************
// Fonction de generation du message
//*******************************
char* make_msg(int nb, int taille_info, int* size_msg){
    // nb ne depasse pas 9999
    nb = nb%10000;

    // variable de test de la parite
    int paire = 0;

    // Allocation dynamique du message
    char* msg = malloc(5+taille_info+3 * sizeof(char));

    // Declaration tableau de caractere
    char caractere[taille_info];
    sprintf(msg, "%04d-", nb);

    // Generation des caracteres aleatoires et de leur parite
    for ( int i = 0; i <= taille_info; i++) {
        caractere[i] = 'A' + (rand() %26);
        paire += make_bit_parite(caractere[i]);
    }

    // On teste la parite
    // Si paire
    if(paire%2 == 0)
        paire = 0;
    // Si impair
    else if(paire%2 == 1)
        paire = 1;

    // Creation du message
    strcat(msg, caractere);
    sprintf(msg + strlen(msg),"-%d", paire);

    return msg;
}

//*******************************
// Fonction de creation du fichier
//*******************************
void create_msg_file(char* fname, int n, int taille_info){
    // Pointeur sur le fichier
    int fichier;

    int size_msg;

    // Ouverture du fichier en mode ecriture seule
    fichier = open(fname, O_WRONLY | O_CREAT,  S_IRWXU | S_IRGRP | S_IROTH);

    // On teste si le fichier s'est bien ouvert
    if(fichier == -1){
        printf("Erreur fichier\n");
        exit(0);
    }

    // Boucle d'ecriture
    for (int i = 0; i < n; i++) {
        // Generation du message
        char* buffer = make_msg(i, taille_info, &size_msg);
        // Ajout du saut a la ligne
        sprintf(buffer + strlen(buffer), "\n");
        // Ecriture et verification de la reussite de l'operation
        if(write(fichier, buffer, strlen(buffer)) == -1){
            printf("Erreur ecriture fichier\n");
            exit(0);
        }
        free(buffer);
    }
    printf("Creation reussie\n");
    close(fichier);
}

//*******************************
// Main
//*******************************
int main(int argc, char* argv[]){
    int nb_msg = 12;
    int size_info = 5;
    int size_msg;
    for (int i = 0; i < nb_msg; i++) {
        char *m = make_msg(i, size_info, &size_msg);
        puts(m);
        free(m);
    }
    create_msg_file("Messages.txt" ,nb_msg, size_info);
    fflush(stdout);
    return EXIT_SUCCESS;
}

