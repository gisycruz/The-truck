#ifndef ADMINISTRADORARBOL_H_INCLUDED
#define ADMINISTRADORARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Jugador.h"

typedef struct _nodoArbol
{
    Jugador dato;
    struct _nodoArbol * izq;
    struct _nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol ();
nodoArbol * crearnodoArbol(Jugador datos);
nodoArbol * insertarDatoArbol(nodoArbol * arbol , Jugador datos);
nodoArbol * buscasDatoArbol(nodoArbol * arbol , int idUsuario);
nodoArbol * buscarxNombre (nodoArbol * arbol ,char nombre []);
void Inorden (nodoArbol * arbol);
void mostrarNodoArbol(nodoArbol * arbol );
nodoArbol * masCercaIsq (nodoArbol * arbol);
nodoArbol * masCercaDer (nodoArbol * arbol);
nodoArbol * borrarNodoArbol (nodoArbol * arbol, int idusuario);
nodoArbol * PasaArchivoUsuarioToArbol (nodoArbol * arbol , char archiUsuario []);

#endif // ADMINISTRADORARBOL_H_INCLUDED
