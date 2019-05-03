#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main() {

    printf("Proceso C...\n");
    printf("PID C: %i. PID A: %i\n", getpid(), getppid());
}