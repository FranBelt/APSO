#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

int pidpr54;

void mensaje3() {
    printf("Proceso pr53 con pid %i. Mensaje 3.\n",getpid());
}

void main() {
    read(2,&pidpr54, sizeof(pidpr54));      // LECTURA PIPE
    mensaje3();
    sleep(1);
    kill(pidpr54, 12);
}