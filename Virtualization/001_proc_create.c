/*
 * Author: digitallyamar
 * Comment: Demo to show process creation
 * Run Cmd: ./001_proc_create
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int child;

    // printf("[%s]: pid = %d\n", __func__, getpid());

    child = fork();
    if (child < 0) {
        printf("[%s]:ERROR - Forking failed!\n", __func__);
        exit(1);
    }

    else if (child == 0) {
        printf("[%s]: pid = %d, returning from fork in CHILD process\n", 
            __func__, getpid());
        printf("[%s]: pid = %d will sleep for 5 sec\n", __func__, getpid());
        sleep(1);
        printf("[%s]: pid = %d Done sleeping\n", __func__, getpid());
        printf("[%s]: pid = %d will take screenshot\n", __func__, getpid());

        char *myargs[3];
        myargs[0] = strdup("gnome-screenshot");
        myargs[1] = NULL;
        myargs[2] = NULL;

        // We will close stdout and instead redirect output to a file form this point
        close(STDOUT_FILENO);

        open("Output_001.out", O_CREAT | O_WRONLY| O_TRUNC, S_IRWXU);

        printf("This print msg will appear in the output file\n");

        execvp(myargs[0], myargs);
        printf("This line will never print if execv succeeds\n");
    }
    else {
        int child_wait = 0;
        
        // child_wait = wait(NULL);
        printf("[%s]: pid = %d, returning from fork in PARENT process "
            "with child pid = %d after waiting on child with " 
            "wait value = %d\n", __func__, getpid(), child, child_wait);
    }


    return 0;
}