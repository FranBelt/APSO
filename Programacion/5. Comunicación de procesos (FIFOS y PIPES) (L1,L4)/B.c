#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int fifo, pidC;

void mensaje2() {
    printf("Segundo Mensaje. PID: %i.\n", getpid());
}

void mensaje5() {
    printf("Quinto Mensaje. PID: %i.\n", getpid());
}

void llamada() {
    kill(pidC, 10);
}

void salida() {
    kill(getppid(), 12);
}

void main() {
    int mipid=getpid();
    signal(14, salida);         // LLAMADA A
    signal(12, mensaje2);       // LLAMADA MENSAJE 2
    signal(10, mensaje5);       // LLAMADA MENSAJE 5
    signal(8, llamada);         // LLAMADA A C DE NUEVO PARA MENSAJE 4
    pause();

    read(2, &pidC, sizeof(pidC));
    
    if((fifo = open("f1", O_RDWR)) != -1) {
        write(fifo, &mipid, sizeof(mipid));
    }

    kill(pidC, 12);
    pause();
    kill(pidC, 10);
    pause();
    close(fifo);
}