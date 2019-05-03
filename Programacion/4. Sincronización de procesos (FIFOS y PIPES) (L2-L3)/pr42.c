#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/// Nombre: Francisco Jesús Beltrán Moreno
/// Login: franciscojesus.beltran750

void mensaje2() {
    printf("Proceso pr42 con PID: %i. Mensaje 2.\n", getpid());
}

void vacio() {}

void main() {
    struct sigaction s1;
    s1.sa_flags = 0;
    s1.sa_handler = mensaje2;
    sigaction(10, &s1, NULL);

    pause();
    kill(getppid(), 12);
    pause();
}