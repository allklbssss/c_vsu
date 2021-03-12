/**********************************************
*File: task2.c
*Description: создание копии самой себя и вывод идентификаторов
*Created: 12.03.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	switch (fork()) {
		case 0:
		printf("Hello from child, my PID is: %d\n", getpid());
		break;
		default:
		printf("Hello from child, my PID is: %d\n", getpid());
		break;
	}
	return 0;
}