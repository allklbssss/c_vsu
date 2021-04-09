/**********************************************
*File: task.c
*Description: none
*Created: 07.04.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

double calculate(double x, double y, char operation) {

	double result;

	switch (operation) {
		case '+': {
			result = x + y;
			break;
		}
		case '-': {
			result = x - y;
			break;
		}
		case '/': {
			if(y != 0) 
				result = x / y;
			else
				result = 0;
			break;
		}
		case '*': {
			result = x * y;
			break;
		}
	}
	return result;
}

int main(int argc, char *argv[]) {

	int fd[2];

	if(pipe(fd) == -1) {
		printf("An error occured with opening the pipe\n");
		return 1;
	}

	int pid = fork();

	if(pid == -1) {
		printf("An error occured with fork\n");
		return 2;
	}

	if(pid == 0) {

		close(fd[0]);
		
		double a, b; operation;

		printf("First number: ");
		scanf("%1f", &a);

		printf("Second number: ");
		scanf("%1f", &b);

		printf("Operation: ");
		scanf(" %c", &operation);

		if(write(fd[1], &a, sizeof(double)) == -1) {
			printf("An error occured with writing to the pipe\n");
			return 3;
		}

		if(write(fd[1], &b, sizeof(double)) == -1) {
			printf("An error occured with writing to the pipe\n");
			return 4;
		}

		if(write(fd[1], &operation, sizeof(char)) == -1) {
			printf("An error occured with writing to the pipe\n");
			return 5;
		}

		close(fd[1]);

	} else {

		close(fd[1]);

		double x, y;
		char rec_op;

		if (read(fd[0], &x, sizeof(double)) == -1) {
			printf("An error occured with reading from the pipe\n");
			return 6;
		}

		if (read(fd[0], &y, sizeof(double)) == -1) {
			printf("An error occured with reading from the pipe\n");
			return 7;
		}

		if (read(fd[0], &rec_op, sizeof(double)) == -1) {
			printf("An error occured with reading from the pipe\n");
			return 8;
		}

		close(fd[0]);
		printf("%.21f %c %.21f = %.21f\n", x, rec_op, y, calculate(x, y, rec_op))
	}
}