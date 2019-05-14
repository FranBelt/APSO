#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#include "comun.h"
#define MAX_CLIENTES 4
#define MAX_ESPERA 4
#define NUM_PARADAS 5

int llega10 = 0;

int creaproceso(const char * nombre);
int creaservigraf(int ultimaparada);
void R10();
void R12();

void main() {
	key_t clave;
	int Id_cola, pservidorgraf, i;
	
	// PREPARACION SEÑALES
	signal(10, R10);
	signal(12, R12);

	// INICIALIZACION SEMILLA
	srand(getpid());

	// CREACION SERVIDOR GRAFICO
	pservidorgraf = creaservigraf(NUM_PARADAS);

	if(!llega10)
		pause();

	llega10 = 0;

	for(i=1; i<=MAX_CLIENTES; i++) {
		creaproceso("cliente");
		sleep(rand()%MAX_ESPERA +1);
	}

	for(i=1; i<=MAX_CLIENTES; i++)
		wait(NULL);

	kill(pservidorgraf, 12);
	
	msgctl(Id_cola, IPC_RMID, (struct msqid_ds *)NULL);
}

// FUNCIÓN AUXILIAR PARA GENERAR PROCESOS //
int creaproceso(const char nombre []) {
	int vpid;
	vpid = fork();

	if(vpid == 0) {
		execl(nombre, nombre, NULL);
		perror("Error en el execl\n");
		exit(-1);
	}
	else if (vpid == -1) {
		perror("Error en el fork\n");
		exit(-1);
	}

	return vpid;
}

// FUNCIÓN AUXILIAR PARA GENERAR EL SERVIDOR GRÁFICO //
int creaservigraf(int ultimaparada) {
	int vpid;
	char cadparada[10];
	sprintf(cadparada, "%d", ultimaparada);

	vpid = fork();

	if(vpid == 0) {
		execl("servidor_ncurses", "servidor_ncurses", cadparada, NULL);
		perror("Error en el execl\n");
		exit(-1);
	}
	else if (vpid == -1) {
		perror("Error en el fork\n");
		exit(-1);
	}

	return vpid;
}

void R10() {
	llega10 = 1;
}

void R12() {
	printf("Error. La resolución no es la correcta.\n");
	exit(-1);
}