#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/// Nombre: Francisco Jesús Beltrán Moreno
/// Login: franciscojesus.beltran750

void vacio() {}

int pid_hijo, pid_hijo2;

void main() {
    printf("Proceso pr41 con PID: %i. Mensaje 1.\n", getpid());
    signal(12,vacio);
    signal(10, vacio);

    pid_hijo = fork();

    if(pid_hijo == 0)
        execl("pr42", "pr42", NULL);
    else {
        pid_hijo2 = fork();

        if(pid_hijo2 == 0)
            execl("pr43", "pr43", NULL);
    }

    sleep(1);
    kill(pid_hijo, 10);
    pause();
    kill(pid_hijo2, 10);
    pause();

    kill(pid_hijo, 9);
    kill(pid_hijo2, 9);
    printf("Proceso pr41 con PID: %i. Mensaje 5.\n", getpid());
}