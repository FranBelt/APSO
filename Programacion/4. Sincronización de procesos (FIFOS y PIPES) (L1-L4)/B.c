#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void mensaje2() {
    printf("Segundo Mensaje.\n");
}

void mensaje5() {
    printf("Quinto Mensaje.\n");
}

void main() {
    signal(12, mensaje2);
    signal(10, mensaje5);

    pause();
    kill(getppid(), 12);
    pause();
    kill(getppid(), 10);
}