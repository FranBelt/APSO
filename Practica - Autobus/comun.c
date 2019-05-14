#include <stdio.h>
#include <stdlib.h>
#include "comun.h"

/*********** FUNCION: crea_cola ********************************************************/ 
/*********** Obtiene acceso a la cola de mensajes con el id que se pasa ****************/
int crea_cola(key_t clave)
{
 int identificador;
 if(clave == (key_t) -1) 
 {
   printf("Error al obtener clave para cola mensajes\n");
   exit(-1);
 }

 identificador = msgget(clave, 0600 | IPC_CREAT);
 if (identificador == -1)
 {
   printf("Error al obtener identificador para cola mensajes\n");
   perror("msgget");
   exit (-1);
 }
 
 return identificador;
}


