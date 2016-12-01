/**  Fichier : test_creation.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Factorisation du code
void affProto(int AF, int SOCK, int PROTO){
    int sd; // Socket
    if(sd = socket(AF, SOCK, PROTO) == -1)
        perror("\t\tEchec\n");
    else
        printf("\t\tSocket creee\n");
}

int main(int argc, char *argv[]){
    int sd;
    /* Domaine Unix, virtual circuit (connection oriented), protocole
       TCP */
    printf("[AF_UNIX, SOCK_STREAM, IPPROTO_TCP] : \n");
    affProto(AF_UNIX, SOCK_STREAM, IPPROTO_TCP);

    /* Domaine Internet, virtual circuit (connection oriented),
       protocole TCP */
    printf("[AF_INET, SOCK_STREAM, IPPROTO_TCP] : \n");
    affProto(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    /* Domaine Internet, datagram (connectionless oriented), protocole
       par defaut */
    printf("[AF_INET, SOCK_DGRAM, 0] : \n");
    affProto(AF_INET, SOCK_DGRAM, 0);

    /* Domaine Internet, datagram (niveau IP), protocole UDP */
    printf("[AF_INET, SOCK_RAW, IPPROTO_UDP] : \n");
    affProto(AF_INET, SOCK_RAW, IPPROTO_UDP);

    /* Domaine XEROX_NS, datagram (improved connection oriented),
       protocole par defaut */
    printf("[AF_X25, SOCK_SEQPACKET, 0] : \n");
    affProto(AF_X25, SOCK_SEQPACKET, 0);

    /* Domaine Internet, datagram (improved connectionless oriented),
       protocole par defaut */
    printf("[AF_INET, SOCK_RDM, 0] : \n ");
    affProto(AF_INET, SOCK_RDM, 0);
}