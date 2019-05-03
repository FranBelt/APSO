#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

int pidpr62, pidpr63;

struct Mensaje1 {
    long Id_Mensaje;
    char Dato_caracter;
};

struct Mensaje2 {
    long Id_Mensaje;
    int Dato_numerico;
};

void main() {
    key_t Clave1;
    int Id_Cola_Mensajes, i;
    struct Mensaje1 Mensaje_p1;
    struct Mensaje2 Mensaje_p2;

    Mensaje_p1.Id_Mensaje = 1;
    Mensaje_p2.Id_Mensaje = 2;

    Clave1 = ftok("./Makefile", 2007);

    if(Clave1 == (key_t)-1) {
        printf("Error al obtener clave para cola de mensajes.\n");
    }

    Id_Cola_Mensajes = msgget(Clave1, 0600 | IPC_CREAT);

    if(Id_Cola_Mensajes == -1) {
        printf("Error al obtener identificador para cola mensajes.\n");
    }

    pidpr62 = fork();

    if(pidpr62 == 0) {
        execl("pr62", "pr62", NULL);
    }
    else {
        pidpr63 = fork();

        if(pidpr63 == 0)
            execl("pr63","pr63", NULL);
    }

    sleep(1);
    
    for(i=0; i<10; i++) {
        msgrcv(Id_Cola_Mensajes, (struct msgbuf *)&Mensaje_p2, sizeof(Mensaje_p2)-sizeof(long),2,0);
        printf("%i ", Mensaje_p2.Dato_numerico);
        msgrcv(Id_Cola_Mensajes, (struct msgbuf *)&Mensaje_p1, sizeof(Mensaje_p1)-sizeof(long),1,0);
        printf("%c\n", Mensaje_p1.Dato_caracter);
    }

    wait();
    wait();
    msgctl(Id_Cola_Mensajes, IPC_RMID, (struct msqid_ds *)NULL);
}