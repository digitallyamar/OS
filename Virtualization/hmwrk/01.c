/*
 * Author: digitallyamar
 * 
 * Comment: Write a program that calls fork().
 * Before calling fork(), have the main process access a variable (e.g., x) 
 * and set its value to something (e.g., 100).
 * What value is the variable in the child process? What happens to the 
 * variable when both the child and parent change the value of x?
 * 
 * Run Cmd: ./01
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int child;

    child = fork();

    if (child < 0) {
        printf("Error: Fork failed");
        exit(1);
    }

    if (child == 0) {
        x = 50;
        printf("Child process pid = %d and x = %d\n", getpid(), x);
        sleep(2);
    }
    else {
        x = 20;
        int chwait = wait(NULL);
        printf("Parent pid = %d and x = %d\n", getpid(), x);
        
    }

    return 0;
}