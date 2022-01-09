/*
 * Author: digitallyamar
 * 
 * Comment: Write another program using fork(). The child process should
 * print “hello”; the parent process should print “goodbye”. You should
 * try to ensure that the child process always prints first; can you do
 * this without calling wait() in the parent?
 * 
 * Run Cmd: ./03
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int child;

    child = fork();

    if (child < 0) {
        printf("Error forking!\n");
        exit(1);
    }
    else if (child == 0) {
        printf("hello\n");
    }
    else {
        printf("goodbye\n");
    }

    return 0;
}

// Note: You cannot ensure parent prints first without wait, unless you use
// sync mechanisms like semaphores and mutexes.