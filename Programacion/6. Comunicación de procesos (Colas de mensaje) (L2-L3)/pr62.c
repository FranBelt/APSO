#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <time.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

struct Mensaje1 {
    long Id_Mensaje;
    char Dato_caracter;
};

void main() {
    key_t Clave1;
    int Id_Cola_Mensajes, i, value;
    struct Mensaje1 Mensaje_p1;

    Mensaje_p1.Id_Mensaje = 1;

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
        value = (rand() % 3 + 1); // ORIGINAL 8 + 8
        sleep(value);
        Mensaje_p1.Dato_caracter = ('a' + rand() % (('z' - 'a') + 1));
        msgsnd(Id_Cola_Mensajes, (struct msgbuf *)&Mensaje_p1, sizeof(Mensaje_p1)-sizeof(long),0);
    }
}