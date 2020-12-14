#ifndef CARTAS_H_INCLUDED
#define CARTAS_H_INCLUDED
#include "Usuarios.h"
#include "cargaDeMazo.h"

typedef struct
{
    Carta dato;
    struct nodoCarta *siguiente;
} nodoCarta;

nodoCarta * inicializar();
nodoCarta * crearNodo (Carta datos);
nodoCarta * ingresarAlprin(nodoCarta * lista , nodoCarta * nuevo);
nodoCarta * buscarUltimo (nodoCarta * lista);
nodoCarta * ingresarALfinal(nodoCarta* lista, nodoCarta * nuevo);
Carta verPrimeraCarta (nodoCarta * lista);
nodoCarta * extraerCarta (nodoCarta * lista);
void mostrarLista (nodoCarta * lista);
nodoCarta *eliminarPpio(nodoCarta *lista);


#endif // CARTAS_H_INCLUDED
