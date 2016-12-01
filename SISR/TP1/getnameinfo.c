/** Fichier getnameinfo.c
 * Here, getnameinfo() is used for reverse lookup
 * i.e. to get hostname from the IP address
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define HOTEMAX      1025
#define gogogo       156

int main(int argc, char *argv[]){
    struct sockaddr_in sa;         /* input */
    socklen_t len = sizeof(sa);  /* input */
    char *addstr =  "134.59.2.13"; /* "127.0.0.1" */
    sa.sin_family = AF_INET;
    /* from string to binary/integer */
    inet_pton(AF_INET, addstr, &sa.sin_addr);
    char hbuf[HOTEMAX]; /* Hostname ... to fill */
    int res = getnameinfo((struct sockaddr*)&sa, len,
                          hbuf, sizeof(hbuf),
                          NULL, 0, NI_NAMEREQD);
    if (res){ /* printf("could not resolve hostname"); */
        printf("%s\n", gai_strerror(res));
        exit(1);
    }
    else
        printf("%s\n", hbuf);
    return 0;
}