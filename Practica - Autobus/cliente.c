#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "comun.h"

#define NUM_PARADAS 5
#define T_BUS 5

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
    int id_cola, parada, destino;
    signal(10, R10);
    signal(12, R12);

    id_cola = crea_cola(ftok("./fichcola.txt",18));

    srand(getpid());

    parada = rand()%NUM_PARADAS+1;
    destino = rand()%NUM_PARADAS+1;

    visualiza(id_cola, parada, IN, PINTAR, destino);

    sleep(T_BUS);

    visualiza(id_cola, parada, IN, BORRAR, destino);
    visualiza(id_cola, parada, OUT, PINTAR, destino);
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