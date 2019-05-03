#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <time.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

struct Mensaje2 {
    long Id_Mensaje;
    int Dato_numerico;
};

void main() {
    key_t Clave1;
    int Id_Cola_Mensajes, i, value;
    struct Mensaje2 Mensaje_p2;

    Mensaje_p2.Id_Mensaje = 2;

    Clave1 = ftok("./Makefile", 2007);

    if(Clave1 == (key_t)-1) {
        printf("Error al obtener clave para cola de mensajes.\n");
    }

    Id_Cola_Mensajes = msgget(Clave1, 0600 | IPC_CREAT);

    if(Id_Cola_Mensajes == -1) {
        printf("Error al obtener identificador para cola mensajes.\n");
    }

    srand(getpid());
    
    for(i=0; i<10; i++) {
        value = (rand() % 3 + 1);   // ORIGINAL 10 + 3
        sleep(value);
        Mensaje_p2.Dato_numerico = (rand() % 100);
        msgsnd(Id_Cola_Mensajes, (struct msgbuf *)&Mensaje_p2, sizeof(Mensaje_p2)-sizeof(long), 0);
    }
}