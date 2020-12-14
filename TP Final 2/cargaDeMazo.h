#ifndef CARGAMAZO_H_INCLUDED
#define CARGAMAZO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define archTrick "trickMazo.dat"


typedef struct
{
    int num;
    char clase[10];
    int nivel;
}Carta;

void mostrarMazo (Carta a);
void mostrarArchivoMazo (char archivo []);
int cantRegistros(char archivo[]);


#endif // CARGAMAZO_H_INCLUDED
