#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PINTAR 1
#define BORRAR 0
#define IN 1
#define OUT 0

#define RETARDO 200000 // Nanosegundos que se retrasa el pintado

int crea_cola(key_t clave);

// informacion que se lee de peticiones de escritura
struct tipo_elemento{
 long tipo; //obligatorio para la cola de mensajes
 int pid;
 int parada; // 0 ES EL BUS Y 7 LA ACERA. DE 1 A 6 SON LAS PARADAS NORMALES
 int inout;  // 1 in 0 out. LA ACERA DEBE PONERLA OUT. 
 int pintaborra; // 1 pinta 0 borra.
 int destino; //parada de destino.
};

 

