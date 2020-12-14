#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

void inicPila(nodoCarta **pila){
    (*pila) = inicializar();
}

int pilaVacia(nodoCarta **pila){
    return ((*pila) == NULL);
}

nodoCarta *tope(nodoCarta **pila){
    return (*pila);
}

Carta desapilar(nodoCarta **pila){
    Carta rta = (*pila)->dato;
    (*pila) = eliminarPpio((*pila));
    return rta;
}

void apilar(nodoCarta **pilita, Carta dato){
    (*pilita) = ingresarAlprin((*pilita), crearNodo(dato));
}

void archivoCartasToPila(char cartas[], Pila *aux){
    FILE *archi = fopen(cartas, "rb");

    if(archi != NULL){
        Carta aux2;
        while(fread(&aux2, sizeof(Carta), 1, archi)>0)
            apilar(aux, aux2);
        if(fclose(archi) != 0){
            printf("Error al cerrar el archivo");
            Sleep(5000);
            exit(-1);
        }
    }
    else{
        printf("Error al abrir el archivo");
            Sleep(5000);
            exit(-1);
    }
}

void borrarDatosPila(Pila *aux){
    Carta aux2;
    while(!pilaVacia(aux))
        aux2 = desapilar(aux);
}
