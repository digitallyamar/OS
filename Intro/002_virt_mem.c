/*
 * Author: digitallyamar
 * Comment: Demo to show memory virtualization
 * Sometimes, address returned by malloc can be same for 2 or more 
 * instances of the same program. This is due to memory virtualization.
 * Run Cmd: ./002_virt_mem &./002_virt_mem ./002_virt_mem ./002_virt_mem
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(void)
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);

    *p = 0;

    while (1) {
        *p += 1;
        printf("[%d] *p(%p) = %d\n", getpid(), p, *p);
        sleep(1);
    }

    return 0;
}