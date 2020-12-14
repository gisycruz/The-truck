#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "AdministradorArbol.h"
#include "Usuarios.h"

void iniciarSesionAdmin();
void textoAdministrador();
void printOpcionesAdministrador();
void opcionesMenu3(int opcion, int color2);
int moverCursorAdministrador();
void marcoMenu3(int linea);
void OpcionBuscarUsuario ();
int menu3(nodoArbol * arbol, nodoJugador* lista);

#endif // ADMINISTRADOR_H_INCLUDED
