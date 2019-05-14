#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#include "comun.h"
//#include "definiciones.h"

int llega10 = 0;

int creaproceso(const char *);
int creaservigraf(int);
void R10();
void R12();

void main() {
	key_t clave;
	int Id_cola, pservidorgraf, i;
	struct tipo_elemento info;
	
	// PREPARACION SEÑALES
	signal(10, R10);
	signal(12, R12);

	// INICIALIZACION SEMILLA
	srand(getpid());

	// CREACION SERVIDOR GRAFICO
	pservidorgraf = creaservigraf(5);

	if(!llega10)
		pause();

	for(i=1; i<=2; i++) {
		creaproceso("cliente");
		sleep(rand()%5 +1);
	}

	for(i=1; i<=2; i++)
		wait(NULL);

	kill(pservidorgraf, 12);
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