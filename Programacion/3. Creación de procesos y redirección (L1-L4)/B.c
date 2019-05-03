#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main() {

    printf("Proceso B...\n");
    printf("PID B: %i. PID A: %i\n", getpid(), getppid());
}