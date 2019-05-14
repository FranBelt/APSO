#include <stdio.h>
#include <unistd.h>

#include "comun.h"

int llega10 = 0;

void visualiza (int cola, int parada, int inout, int pintaborra, int destino);

void R10() {
	llega10 = 1;
}

void R12() {
	printf("Error. La resolución no es la correcta.\n");
	exit(-1);
}

void main() {
    signal(10, R10);
    signal(12, R12);
}

void visualiza (int cola, int parada, int inout, int pintaborra, int destino) {
    struct tipo_elemento peticion;    

    // Tipo persona //
    peticion.tipo = 2;
    peticion.pid = getpid();
    peticion.parada = parada;
    peticion.inout = inout;
    peticion.pintaborra = pintaborra;
    peticion.destino = destino;

    msgsnd(cola, (struct msgbuf *)&peticion, sizeof(peticion)-sizeof(long), 0);

    if(pintaborra == PINTAR)
        if(!llega10) pause();
            llega10 = 0;
    
}