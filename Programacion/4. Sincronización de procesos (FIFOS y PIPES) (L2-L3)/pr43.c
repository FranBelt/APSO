#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/// Nombre: Francisco Jesús Beltrán Moreno
/// Login: franciscojesus.beltran750

void vacio() {}

void mensaje3() {
    printf("Proceso pr43 con PID: %i. Mensaje 3.\n", getpid());
}

void mensaje_alarma() {
    printf("Proceso pr43 con PID: %i. Ha saltado el alarm. Mensaje 4.\n", getpid());
}

void main() {
    struct sigaction accion1;
    accion1.sa_flags = 0;
    accion1.sa_handler = mensaje3;
    sigaction(10, &accion1, NULL);
    signal(SIGALRM, mensaje_alarma);

    pause();
    alarm(10);
    pause();
    kill(getppid(),10);
    pause();
}