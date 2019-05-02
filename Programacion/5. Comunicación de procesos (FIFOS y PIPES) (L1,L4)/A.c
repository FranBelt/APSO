#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int pidB, pidC, tubo[2];

void ultimomensaje() {
    printf("Ultimo Mensaje. PID: %i.\n", getpid());
}

void main() {
    signal(12, ultimomensaje);
    
    printf("Primer Mensaje. PID: %i.\n", getpid());

    mkfifo("f1", 0666); // FIFO B -> C
    pipe(tubo);         // PIPE A -> B

    pidB = fork();      // PROCESO C

    // PROCESO PR53 //
    if(pidB == 0) {
        close(2);
        dup(tubo[0]);
        execl("B", "B", NULL);
    }
    else {
        pidC = fork();

        if(pidC == 0)
            execl("C", "C", NULL);
    }

    sleep(1);
    write(tubo[1], &pidC, sizeof(pidC));
    kill(pidB, 12);
    pause();
    unlink("f1");
    wait();
    wait();
}