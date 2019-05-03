#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int pidB, pidC;

void ultimomensaje() {
    printf("Ultimo Mensaje.\n");
}

void vacio() {}

void main() {
    struct sigaction signal12;
    signal12.sa_flags = 0;
    signal12.sa_handler = vacio;
    sigaction(12, &signal12, NULL);

    signal(10, ultimomensaje);
    printf("Primer Mensaje.\n");
    pidB = fork();

    if(pidB == 0) {
        execl("B", "B", NULL);
    }
    else {
        pidC = fork();

        if(pidC == 0) {
            execl("C", "C", NULL);
        }
    }

    sleep(1);
    kill(pidB, 12);
    pause();
    kill(pidC, 10);
    pause();
    kill(pidB, 10);
    wait();
    wait();
}