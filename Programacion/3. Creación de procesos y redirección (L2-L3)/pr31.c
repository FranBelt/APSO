#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/// Nombre: Francisco Jesús Beltrán Moreno
/// Login: franciscojesus.beltran750

int hijo_pid1, hijo_pid2;

main() {
  printf("Proceso pr31 y mi pid es: %i\n", getpid());
  
  hijo_pid1 = fork();
  
  if (hijo_pid1 == 0) {
    printf("Soy la copia de pr31 y mi pid es %i.\n", getpid());
  }
  else{
    hijo_pid2 = fork();
    
    if (hijo_pid2 == 0) {
      execl("pr32","pr32",NULL);
      sleep(1);
    }
    else {
      sleep(3);
      printf("Fin de la copia de pr31.\n");
    }

  sleep(1);
  printf("Fin de la pr31 original.\n");  
  }
}