#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int pidB, fifo;

void mensaje3() {
    printf("Tercer Mensaje. PID: %i.\n", getpid());
}

void mensaje4() {
    printf("Cuarto Mensaje. PID: %i.\n", getpid());
}

void main() {
    signal(12, mensaje3);       // LLAMADA MENSAJE 3
    signal(10, mensaje4);       // LLAMADA MENSAJE 4
    pause();

    if((fifo = open("f1", O_RDWR)) != -1) {
        read(fifo, &pidB, sizeof(pidB));
    }

    sleep(3);
    kill(pidB, 8);
    pause();
    kill(pidB, 10);
    kill(pidB, 14);
    close(fifo);
}