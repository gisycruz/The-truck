#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "CeldaMazo.h"
#include "Cartas.h"

nodoJugador *generarBot(){
    char bots[30]={"Bots.dat"}; ///Ruta de los bots
    FILE *archi = fopen(bots, "rb");
    srand(time(NULL));
    nodoJugador *aux = NULL;

    if(archi != NULL){
        int num=rand()%10;
        fseek(archi, sizeof(Jugador)*num, SEEK_SET);
        Jugador aux2;
        fread(&aux2, sizeof(Jugador)-sizeof(int), 1, archi);
        aux = crearNodoJugador(aux2);
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
    return aux;
}
void agregarCeldas(CeldaMazo celdas[], nodoJugador *jug){
    nodoJugador *bot = generarBot();
    celdas[0].puntos = 0;
    celdas[0].jug = bot;
    inicPila(&celdas[0].cartas);

    celdas[1].puntos = 0;
    celdas[1].jug = jug;
    inicPila(&celdas[1].cartas);
}

void eliminarPosArregloCartas(Carta cartas[], int validos, int pos){
    for(int i=pos; i<validos; i++){
        cartas[i] = cartas[i+1];
    }
}

void repartirCartas(CeldaMazo jugadores[], char cartasArchivo[]){
    Pila mazo;
    inicPila(&mazo);

    archivoCartasToPila(cartasArchivo, &mazo);
    mezclarCartas(&mazo);

    for(int i=0; i<3; i++){
        apilar(&jugadores[1].cartas, desapilar(&mazo));
        apilar(&jugadores[0].cartas, desapilar(&mazo));
    }

    while(!pilaVacia(&mazo))
        desapilar(&mazo);
}

Carta desapilarPorPosicion(Pila *pilita, int pos){
    Pila aux;
    inicPila(&aux);
    Carta aux2;

    while(!pilaVacia(pilita))
        apilar(&aux, desapilar(pilita));

    int i = 0;
    while(i<pos){
        apilar(pilita, desapilar(&aux));
        i++;
    }
    aux2 = desapilar(pilita);

    while(!pilaVacia(&aux))
        apilar(pilita, desapilar(&aux));

    return aux2;
}

void mezclarCartas(Pila *mazo){
    Pila aux;
    inicPila(&aux);

    while(!pilaVacia(mazo))
        apilar(&aux, desapilar(mazo));

    srand(time(NULL));
    while(!pilaVacia(&aux)){
        int num=1+rand()%cantElementosPila(aux);
        Carta aux2 = desapilarPorPosicion(&aux, num);
        apilar(mazo, aux2);
    }
}

int cantElementosPila(Pila aux){
    Pila aux2;
    inicPila(&aux2);
    int i=0;
    while(!pilaVacia(&aux)){
        apilar(&aux2, desapilar(&aux));
        i++;
    }

    while(!pilaVacia(&aux2))
        apilar(&aux, desapilar(&aux2));
    return i;
}

Carta mayor(Pila *pilita){
    Pila aux, aux2;
    inicPila(&aux);
    inicPila(&aux2);

    apilar(&aux2, desapilar(pilita));

    while(!pilaVacia(pilita)){
        if(tope(pilita)->dato.clase > tope(&aux2)->dato.clase){
            apilar(&aux, desapilar(&aux2));
            apilar(&aux2, desapilar(pilita));
        }
        else
            apilar(&aux, desapilar(pilita));
    }

    while(!pilaVacia(&aux))
        apilar(pilita, desapilar(&aux));
    return desapilar(&aux2);
}

void crearCopiaParaElTanto(Pila *copia, Pila *dada){
    Pila aux;
    inicPila(&aux);

    while(!pilaVacia(dada)){
        apilar(&aux, desapilar(dada));
    }

    while(!pilaVacia(&aux)){
        Carta cartaAux = tope(&aux)->dato;
        if(cartaAux.num > 9)
            cartaAux.num = 0;
        apilar(copia, cartaAux);
        apilar(dada, desapilar(&aux));
    }
}

int tanto(Pila dada){
    int puntos = 0;
    Pila copia, aux, aux2;
    inicPila(&copia);
    inicPila(&aux);
    inicPila(&aux2);
    crearCopiaParaElTanto(&copia, &dada);

    apilar(&aux, desapilar(&copia));
    if(strcmpi(tope(&aux)->dato.clase, tope(&copia)->dato.clase) == 0)
        puntos = tope(&aux)->dato.num + tope(&copia)->dato.num;

    apilar(&aux2, desapilar(&copia));
    if(strcmpi(tope(&aux2)->dato.clase, tope(&copia)->dato.clase) == 0)
        if(puntos < tope(&aux2)->dato.num + tope(&copia)->dato.num)
            puntos = tope(&aux2)->dato.num + tope(&copia)->dato.num;

    if(strcmpi(tope(&copia)->dato.clase, tope(&aux)->dato.clase) == 0)
       if(puntos < tope(&copia)->dato.num + tope(&aux)->dato.num)
            puntos = tope(&copia)->dato.num + tope(&aux)->dato.num;

    if(puntos > 0)
        puntos += 20;
    return puntos;
}

int envidoBot(){
    return quieroNoQuiero(1);
}

int pedirTrucoBot(){
    quieroNoQuiero(2);
}
