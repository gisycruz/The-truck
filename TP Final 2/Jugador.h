#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idUsuario;
    char nombreDeUsuario[30];
    char contrasenia[30];
    int puntosHistorial;
    int bajado;
}Jugador;

void ingresarNombreUsuario(char c[]);
void ingresarContrasenia(char c[]);
void intentos(int flag, int usuarioOcontrasenia);
void mostrarJugador (Jugador datos);
#endif // JUGADOR_H_INCLUDED
