#ifndef VISUAL_H_INCLUDED
#define VISUAL_H_INCLUDED
#include "CeldaMazo.h"
#include "Cartas.h"

void marcoMenu(int linea);
void textTheTrick();
int moverCursor(int X, int Y, int arriba, int abajo, int saltos, int menu);
void printOpcionesMenu1();
void opcionesMenu1(int opcion, int color);
int menu1();
int menuDentroDelJuego();
void menu2();
void buscarPartida();
void marcosTableros();
void cartasAbajo(int de, int hasta, nodoCarta *carta, int numCarta);
void mostrarCartasJugador1(CeldaMazo celdas[]);
void marcoSeleccionCarta(int carta, int eliminar);
int elegirCarta(int cant);

#endif // VISUAL_H_INCLUDED
