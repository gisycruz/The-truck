#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define Pila nodoCarta*
#include "Cartas.h"

void inicPila(nodoCarta **pila);
int pilaVacia(nodoCarta **pila);
nodoCarta *tope(nodoCarta **pila);
Carta desapilar(nodoCarta **pila);
void apilar(nodoCarta **pilita, Carta dato);
void archivoCartasToPila(char cartas[], Pila *aux);

#endif // PILA_H_INCLUDED
