#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

int pidpr54;

void mensaje2() {
    printf("Proceso pr52 con pid %i. Mensaje 2.\n",getpid());
}

void main() {
    signal(12, mensaje2);
    pause();

    pidpr54 = fork();

    if(pidpr54 == 0) {
        execl("pr54","pr54",NULL);
    }

    write(2,&pidpr54,sizeof(pidpr54));      // ESCRITURA EN LA PIPE
    wait();                                 // ESPERAMOS MUERTE HIJO
}