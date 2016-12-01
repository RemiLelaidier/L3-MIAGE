/** Fichier orphelin.c : Faire mourir le pere avant le fils */
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
int main (int argc, char *argv[]){ 
	int pid;
	switch(pid = fork()) { 
		case -1: /* Pb ... */
			perror("Erreur du fork");
			exit(1);
		case 0: /* Ce code s'execute chez le fils */
			printf("Je suis le fils (%d) et le PID de mon pere est (%d)\n", getpid(), getppid());
			printf("Vous avez 15 sec pour lancer un ""ps -e -f"" !\n");
			/* Il s'agit de montrer le pere et le fils en cours d'execution */ sleep(60);
			printf("\nJe suis le fils (%d) et le PID de mon pere est (%d)\n",
			getpid(), getppid()); if (getppid() == 1)
			printf("Je suis donc devenu orphelin !\n"); break;
		default: /* Ce code s'execute chez le pere */
			printf("Je suis le pere (%d) \n",getpid());
			sleep(15); /* Pour laisser le temps au fils d'afficher le premier ppid */ printf("Je suis le pere (%d) et je meurs AVANT mon fils (%d)\n",getpid(),pid);
	}
	printf("Fin \n"); exit(0);
}
