#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Nombre: Francisco Jesús Beltrán Moreno
// Login: franciscojesus.beltran750

int pidpr52, pidpr53, fifo1, tub1[2], mipid;

void mensaje5() {
    printf("Proceso pr51 con pid %i. Mensaje 5.\n", getpid());
}

void main() {
    // PREPARACION SEÑAL 12 //
    signal(12, mensaje5);
    printf("Proceso pr51 con pid %i. Mensaje 1.\n", getpid());

    // FIFO Y TUBERIA //
    mkfifo("f1", 0666);
    pipe(tub1);

    mipid=getpid();

    // ESCRITURA PID PR51 EN FIFO //
    if((fifo1 = open("f1", O_RDWR)) != -1) {
        write(fifo1, &mipid, sizeof(mipid));
    }
    else
        printf("Fallo al crear la fifo.");

    pidpr52 = fork();

    // COPIA PR51 PARA LLAMAR A PR52 //
    if(pidpr52 == 0) {
        close(2); // SALIDA DE ERRORES
        dup(tub1[1]); // RELLENAMOS LA TABLA PARA ESCRITURA
        execl("pr52", "pr52", NULL);
    }
    else {
        // COPIA PR51 PARA LLAMAR A PR53 //
        pidpr53 = fork();

        if(pidpr53 == 0) {
            close(2); // SALIDA DE ERRORES
            dup(tub1[0]); // RELLENAMOS LA TABLA PARA LECTURA
            execl("pr53", "pr53", NULL);
        }
    }

    sleep(1);
    kill(pidpr52, 12);  // SEÑAL 12 PR52
    pause();
    close(fifo1);       // CERRAMOS FIFO
    unlink("f1");       // LIMPIAMOS LA FIFO
    wait();             // ESPERAMOS A LA MUERTE DE NUESTRO HIJO
    wait();             // ESPERAMOS A LA MUERTE DE NUESTRO HIJO
}