/* protoent.c:
 *  Linux Socket Programming by Example - Warren Gray
 * Example getprotoent(3) program:
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

int  main(int argc,char **argv) {
    int x;
    struct protoent *pp;
    // Pour affichage proto 6
    struct protoent *pSix;

    for (;;) {

        errno = 0;
        if ( !(pp = getprotoent()) )
            break;

        printf("%s:\n"
                       "\tProtocol: %d\n"
                       "\tAliases:  ",
               pp->p_name,
               pp->p_proto);

        for ( x=0; pp->p_aliases[x] != NULL; ++x )
            printf("%s ",pp->p_aliases[x]);
        putchar('\n');
    }

    // Affichage du nom du protocole numero 6
    printf("Affichage du protocole numero 6\n");
    pSix = getprotobynumber(6);
    printf("Le protocole numero 6 est %s\n", pSix->p_name);

    /* Ce qui suit un peu pointu ... pour savoir pourquoi il
       faudrait regarde dans la reference citee dans le
       prologue.
       Donc pour l'instant on ignore ce qui suit ...
    */
    if ( errno != 0 && errno != ENOENT ) /* For RH-6.0 */
        fprintf(stderr, "%s: getprotoent(3) %d\n",
                strerror(errno),errno);

    return 0;
}