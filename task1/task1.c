/**********************************************
*File: task1.c
*Description: вывод идентификаторов текущего и родительского процесса
*Created: 12.03.2021
*Copyright:(C) Alina Kolbasova 
*Author: Alina Kolbasova
*Email: none 
***********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
printf("Current PID is: %d\nParent PID is: %d\n", getpid(), getppid());
return 0;
}


