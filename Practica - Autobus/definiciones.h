/**** DECLARACION DE CONSTANTES ********************/

#define MAXCLIENTES 50 //Limite del array para casa parada
#define MAXPARADAS 8 // la 0 será el autobus - MAXIMO 6 PARA EL BUS Y LA 7 LA ACERA

#define ALTO 25
#define ANCHO 6

#define COLOR_PARADAIN 1
#define COLOR_PARADAOUT 2
#define COLOR_BUS 3
#define COLOR_FONDO 4
#define COLOR_DIBUJOBUS 5
#define COLOR_ACERA 6


//informacion que se almacena de cada cliente
struct cliente{
 int elpid;
 int destino;
}; 


