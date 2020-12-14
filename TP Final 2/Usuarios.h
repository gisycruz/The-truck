#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"


typedef struct _nodo{
    Jugador dato;
    struct _nodo *siguiente;
}nodoJugador;
nodoJugador * iniclista();
nodoJugador *crearNodoJugador(Jugador jug);
nodoJugador *agregarAlFinal(nodoJugador *lista, nodoJugador *insertar);
nodoJugador *borrarLista(nodoJugador *lista);
nodoJugador *buscarJugador(nodoJugador *lista, char nombreDeUsuario[]);
nodoJugador *agregarUsuario(nodoJugador *lista);
void lTF(FILE *fi, nodoJugador *lista);
nodoJugador *fTL(FILE *fi);
nodoJugador *listaToArchivo(char f[], nodoJugador *lista);
nodoJugador *archivoToLista(char archivoJugadores[]);
nodoJugador *iniciarSesionUsuario(nodoJugador *lista);

#endif // USUARIOS_H_INCLUDED
