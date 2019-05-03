#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void mensaje3() {
    printf("Tercer Mensaje.\n");
}

void mensaje4() {
    printf("Cuarto Mensaje.\n");
}

void main() {
    struct sigaction signal1;
    signal1.sa_flags = 0;
    signal1.sa_handler = mensaje3;

    sigaction(10, &signal1, NULL);
    signal(SIGALRM, mensaje4);

    pause();
    alarm(3);
    pause();
    kill(getppid(), 12);
}