#ifndef CELDAMAZO_H_INCLUDED
#define CELDAMAZO_H_INCLUDED
#include "Usuarios.h"
#include "Cartas.h"
#include "Pila.h"

typedef struct{
    int puntos;
    nodoJugador *jug;
    Pila cartas;
}CeldaMazo;

nodoJugador *generarBot();
void agregarCeldas(CeldaMazo celdas[], nodoJugador *jug);
void eliminarPosArregloCartas(Carta cartas[], int validos, int pos);
void generarMazoMezclado(Pila *aux, Carta cartas[]);
void repartirCartas(CeldaMazo jugadores[], char cartasArchivo[]);
Carta mayor(Pila *pilita);
Carta desapilarPorPosicion(Pila *pilita, int pos);

#endif // CELDAMAZO_H_INCLUDED
