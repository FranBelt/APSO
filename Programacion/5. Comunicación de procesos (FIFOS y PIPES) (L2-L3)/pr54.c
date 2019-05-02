#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

int pidpr51;
int tub1;

void mensaje4() {
    printf("Proceso pr54 con pid %i. Mensaje 4.\n",getpid());
}

void main() {
    signal(12, mensaje4);
    pause();

    if((tub1 = open("f1", O_RDWR)) != -1) {
        read(tub1,&pidpr51, sizeof(int));
    }

    kill(pidpr51, 12);
    close(tub1);        // CERRAMOS FICHERO
}