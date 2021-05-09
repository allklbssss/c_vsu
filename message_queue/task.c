/**********************************************
*File: task.c
*Description: none
*Created: 07.04.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string.h>


struct message {
	long mtype;
	double a;
	double b;
	char operation;
};

double calculate(double a, double b, char operation) {

	double result;

	switch (operation) {
		case '+': {
			result = a + b;
			break;
		}
		case '-': {
			result = a - b;
			break;
		}
		case '/': {
			if(b != 0) 
				result = a / b;
			else
				result = 0;
			break;
		}
		case '*': {
			result = a * b;
			break;
		}
	}
	return result;
}

int main(void) {

	int msqid = msgget(IPC_PRIVATE, IPC_CREAT | 0600);

	if (msqid == -1) {
		perror("msgget");
		return EXIT_FAILURE;
	}

	pid_t pid = fork();

	if (pid == 0) {

		double a;
		double b;
		char operation;

		struct message message;
		message.mtype = 23;
		memset(&(message.a), 0, sizeof(double));
		memset(&(message.b), 0, sizeof(double));
		memset(&(message.operation), 0, sizeof(char));

		printf("First number: ");
		scanf("%lf", &(message.a));

		printf("Second number: ");
		scanf("%lf", &(message.b));

		printf("Operation: ");
		scanf(" %c", &operation);
		(void)strcpy(&(message.operation), &operation);

		if(msgsnd(msqid, &message, sizeof(struct message), 0) == -1) {
			perror("msgsnd");
			return EXIT_FAILURE;
		}

	} else {

		(void)waitpid(pid, NULL, 0);

		struct message message;

		if (msgrcv(msqid, &message, sizeof(struct message), 0, 0) == -1) {
			perror("msgrcv");
			return EXIT_FAILURE;
		}

		printf("%.21f %c %.21f = %.21f\n", message.a, message.operation, message.b, calculate(message.a, message.b, message.operation));
	    
	    if(msgctl(msqid, IPC_RMID, NULL) == -1) {
	    	perror("msgctl");
	    	return EXIT_FAILURE;
	    }
	}
	
	return EXIT_SUCCESS;
}
