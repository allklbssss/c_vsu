/**********************************************
*File: prg1.c
*Description: none
*Created: 12.03.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char str[40] = "I,m waiting signal..\n";

// обработка сигнала
void signalHandler(int signalCode) {
	switch (signalCode) {
		case SIGUSR1:
		printf("SIGUSR1 recieved\n");
		strcpy(str, "Last recieved signal is: SIGUSR1\n");
		break;
		case SIGUSR2:
		printf("SIGUSR2 recieved\n");
		strcpy(str, "Last recieved signal is: SIGUSR2\n");
		break;
	}
}

int main() {

	// регистрируем сигнал
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);

	printf("[ PID: %d }: Started...\n", getpid());

	while(1) {
		printf("%s", str);
		sleep(2);
	}
return 0;
}