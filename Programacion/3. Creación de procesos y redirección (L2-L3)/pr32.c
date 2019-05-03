#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/// Nombre: Francisco Jesús Beltrán Moreno
/// Login: franciscojesus.beltran750

main() {
  printf("Soy pr32 y mi pid es: %i.\n", getpid());
  
  int hijo_pid1 = fork();
  
  if (hijo_pid1 == 0)
    execl("pr33","pr33",NULL);
  else {
    sleep(2);
    printf("Fin de pr32.\n");  
  }
}