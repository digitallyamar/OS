/*
 * Author: digitallyamar
 * Comment: Demo to show CPU virtualization
 * Run Cmd: ./001_virt_cpu A &./001_virt_cpu B ./001_virt_cpu C ./001_virt_cpu D
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char *cpu_id = argv[1];

    if (argc != 2) {
        printf("Usage: ./001_virt_cpu <ID>\n");
        printf("Eg: ./001_virt_cpu A\n");
        exit(0);
    }

    while (1) {
        printf("cpu ID = %s\n", cpu_id);
        sleep(1);
    }


    return 0;
}