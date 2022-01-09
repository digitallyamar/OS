/*
 * Author: digitallyamar
 * 
 * Comment: Write a program that opens a file (with the open() system call)
 * and then calls fork() to create a new process. Can both the child
 * and parent access the file descriptor returned by open()? What
 * happens when they are writing to the file concurrently, i.e., at the
 * same time?
 * 
 * Run Cmd: ./02
 * 
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int child, f, fw;
    char buff[10] = {'A', 'B', 'C'};

    f = open("Makefile", O_RDONLY);
    fw = open("./dummy.out", O_RDWR | O_CREAT| O_TRUNC, S_IRWXU);

    child = fork();

    if (child < 0) {
        printf("Error forking!\n");
        exit(1);
    }

    if (child == 0) {
        printf("Child process pid = %d, f = %d\n", getpid(), f);
        read(f, buff, 3);
        printf("Child buff[0] = %c, buff[1] = %c, "
        "buff[2] = %c\n", buff[0], buff[1], buff[2]);

        // Write to a file
        write(fw, "Hello ", 6);
    }

    else {
        printf("Parent process pid = %d, f = %d\n", getpid(), f);
        read(f, buff, 3);
        printf("Parent buff[0] = %c, buff[1] = %c, "
        "buff[2] = %c\n", buff[0], buff[1], buff[2]);
 
         // Write to a file
        write(fw, "World!\n", 9);

    }

    return 0;
}