/**********************************************
*File: prg2.c
*Description: none
*Created: 12.03.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc == 3) {
		if ((strcmp(argv[2], "SIGUSR1") == 0) || (strcmp(argv[2], "SIGUSR2") == 0)) {

			int pid = atoi(argv[1]);
			int sig;
			
		if ((strcmp(argv[2], "SIGUSR1") == 0)) {	
			sig = 10;
		} else {
			sig = 12;
		}
		kill(pid, sig);
		printf("Signal sended.\n");
	} else {
		printf("Arguments error.\n");
	}
} else if (argc > 3) {
	printf("Too many arguments supplied.\n");
} else {
	printf("Arguments error.\n");
}
