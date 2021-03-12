/**********************************************
*File: child.c
*Description: вызов exec
*Created: 12.03.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("Hello from child.c\n");
	printf("PID of new process is: %d\n", getpid());
	return 0;
}