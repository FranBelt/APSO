#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int pidB, pidC;

void main() {

    printf("Bienvenido...\n");
    printf("PID A: %i.\n", getpid());

    pidB = fork();

    if(pidB == 0)
        execl("B", "B", NULL);
    else {
        pidC = fork();

        if(pidC == 0) {
            close(1);                               // REDIRECCIONAMOS LA SALIDA
            open("infoc", O_WRONLY | O_CREAT);      // ALMACENAMOS LA SALIDA EN INFOC
            execl("C", "C", NULL);
        }
    }

    wait();
    wait();
}