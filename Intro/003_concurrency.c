/*
 * Author: digitallyamar
 * Comment: Demo to show concurrency issue
 * Sometimes, same memory address access by multiple apps can 
 * result in inconsistent data value. This is due to concurrency issue.
 * Run Cmd: ./003_concurrency 10000
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int counter = 0;
int loops;

void *worker(void *arg)
{
    while (loops) {
        loops--;
        counter++;
    }
}

int main(int argc, char **argv)
{
    pthread_t p1, p2;

    if (argc != 2) {
        printf("Usage: ./002_concurrency <count>\n");
        exit(0);
    }

    loops = atoi(argv[1]);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final value of counter = %d\n", counter);

    return 0;
}