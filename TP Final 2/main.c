#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <pthread.h>
#include "Usuarios.h"
#include "Visual.h"
#include "Cartas.h"
#include "CeldaMazo.h"
#include"Administrador.h"

int main()
{
    int puntos = 0, mano, mano2, cantCartasMesa, puntosMesaJug=0, puntosMesaBot=0, salir = 0, enfrentamiento = 0, tantoBot, tantoJug, huboTanto=0, truco=0;
    Pila mazo, mesaJug, mesaBot;
    inicPila(&mazo);
    inicPila(&mesaJug);
    inicPila(&mesaBot);
    char archivoUsuarios[20] = {"ArchivoUsuarios.dat"};
    char archivoCartas[20] = {"trickMazo.dat"};
    nodoJugador *lista = iniclista();
    lista=archivoToLista(archivoUsuarios);
    nodoArbol * Arbol = inicArbol();
    Arbol=PasaArchivoUsuarioToArbol(Arbol,archivoUsuarios);
    nodoJugador *jugador = iniclista();
    CeldaMazo jugadores[2];
    srand(time(NULL));
    color(4);
    color(15);
    marcoMenu(0);
    textoTheTrick();

    do{
        salir = 0;
        switch(menu1()){
        case 1:
            borrarOpciones();
            menu2();
            iniciarSesionAdmin();
            system("cls");
            menu3(Arbol, lista);
            break;

        case 2:
            borrarOpciones();
            menu2();
            jugador = iniciarSesionUsuario(lista);
            do{
                switch(menuDentroDelJuego())
                {
                case 1:
                    system("cls");
                    marcoMenu(0);
                    buscarPartida();
                    marcoMenu(1);
                    marcosTableros();
                    agregarCeldas(jugadores, jugador);
                    mano2 = 0;
                    mano = mano2;
                    mostrarNombres(jugadores);

                    do{
                        borrarCartasMesa();
                        repartirCartas(jugadores, archivoCartas);
                        cantCartasMesa = 1;
                        mostrarPuntos(jugadores);
                        puntos = 1;
                        puntosMesaBot = 0;
                        puntosMesaJug = 0;
                        tantoBot = tanto(jugadores[0].cartas);
                        tantoJug = tanto(jugadores[1].cartas);
                        enfrentamiento = 1;
                        huboTanto=0;
                        truco=0;

                        do{
                            ///------------------------------------------------------- BOT
                            mostrarCartasJugador1(jugadores);
                            if(mano2 == 0){
                                if(truco == 0 && enfrentamiento > 1){
                                    int cantarOnoTruco = rand()%2;
                                    if(cantarOnoTruco == 1){
                                        switch(quieroNoQuiero(2)){
                                        case 1:
                                            puntos+=1;
                                            break;
                                        case 2:
                                            jugadores[0].puntos+=1;
                                            break;
                                        }
                                        borrarOpcionesPartida();
                                        truco++;
                                    }
                                }
                                apilar(&mesaBot, mayor(&jugadores[0].cartas));
                                mostrarCartaMesa(tope(&mesaBot)->dato, cantCartasMesa);
                                cantCartasMesa++;
                                if(enfrentamiento == 1){
                                    if(tantoBot > 20){
                                        int cantarOnoTruco = rand()%2;
                                        if(cantarOnoTruco == 1){
                                            color(15);
                                            gotoxy(95, 31); printf("*Nota: Tanto mas alto de tus cartas");
                                            gotoxy(95, 32); printf("                 %i", tantoJug);
                                            int envido = envidoBot();
                                            if(envido == 1 && tantoBot > tantoJug){
                                                jugadores[0].puntos += 2;
                                                huboTanto++;
                                            }
                                            else if(envido == 1 && tantoBot < tantoJug){
                                                jugadores[1].puntos += 2;
                                                huboTanto++;
                                            }
                                            else{
                                                jugadores[0].puntos += 1;
                                                huboTanto = 0;
                                            }
                                            borrarOpcionesPartida();
                                            enfrentamiento++;
                                        }
                                    }
                                }///-------------------------------------------------------


                                ///-------------------------------------------------------- JUGADOR
                                if(enfrentamiento == 1){
                                    int siOno = rand()%2;
                                    switch(elegirOpcionCantar(1)){
                                    case 1:
                                        if(siOno == 1){
                                            mostrarQuieroNoQuieroBot(1);
                                            if(tantoBot < tantoJug)
                                                jugadores[1].puntos+=2;
                                            else
                                                jugadores[0].puntos+=2;
                                            huboTanto++;
                                            }
                                        else{
                                            mostrarQuieroNoQuieroBot(2);
                                            jugadores[1].puntos+=1;
                                            huboTanto = 0;
                                        }
                                        enfrentamiento++;
                                        getch();
                                        break;
                                    case 2:
                                        if(siOno == 1)
                                            puntos+=1;
                                        else
                                            jugadores[1].puntos+=1;
                                        truco++;
                                        mostrarQuieroNoQuieroBot(siOno+1);
                                        getch();
                                        break;
                                    }
                                }
                                else if(truco == 0){
                                    int siOno = rand()%2;
                                    switch(elegirOpcionCantar(2)){
                                    case 1:
                                        if(siOno == 1){
                                            puntos+=1;
                                            mostrarQuieroNoQuieroBot(1);
                                        }
                                        else{
                                            jugadores[1].puntos+=1;
                                            mostrarQuieroNoQuieroBot(2);
                                        }
                                        truco++;
                                        getch();
                                        break;
                                    }
                                }
                                enfrentamiento++;
                                borrarOpcionesPartida();
                                apilar(&mesaJug, desapilarPorPosicion(&jugadores[1].cartas, elegirCarta(cantElementosPila(jugadores[1].cartas))));
                                mostrarCartaMesa(tope(&mesaJug)->dato, cantCartasMesa);
                                cantCartasMesa++;
                                ///-------------------------------------------------------
                            }
                            else{
                                ///------------------------------------------------------- JUGADOR
                                apilar(&mesaJug, desapilarPorPosicion(&jugadores[1].cartas, elegirCarta(cantElementosPila(jugadores[1].cartas))));
                                borrarCartasJugVisual(cantElementosPila(jugadores[1].cartas)+1);
                                mostrarCartasJugador1(jugadores);
                                mostrarCartaMesa(tope(&mesaJug)->dato, cantCartasMesa);
                                cantCartasMesa++;

                                if(enfrentamiento == 1){
                                    int siOno = rand()%2;
                                    switch(elegirOpcionCantar(1)){
                                    case 1:
                                        if(siOno == 1){
                                            if(tantoBot < tantoJug)
                                                jugadores[1].puntos+=2;
                                            else
                                                jugadores[0].puntos+=2;
                                            huboTanto++;
                                            mostrarQuieroNoQuieroBot(1);
                                            }
                                        else{
                                            jugadores[1].puntos+=1;
                                            huboTanto = 0;
                                            mostrarQuieroNoQuieroBot(2);
                                        }
                                        enfrentamiento++;
                                        getch();
                                        break;
                                    case 2:
                                        if(siOno == 1){
                                            puntos+=1;
                                            mostrarQuieroNoQuieroBot(1);
                                        }
                                        else{
                                            jugadores[1].puntos+=1;
                                            mostrarQuieroNoQuieroBot(1);
                                        }
                                        truco++;
                                        getch();
                                        break;
                                    }
                                }
                                else if(truco == 0){
                                    int siOno = rand()%2;
                                    switch(elegirOpcionCantar(2)){
                                    case 1:
                                        if(siOno == 1){
                                            puntos+=1;
                                            mostrarQuieroNoQuieroBot(1);
                                        }
                                        else{
                                            jugadores[1].puntos+=1;
                                            mostrarQuieroNoQuieroBot(2);
                                        }
                                        truco++;
                                        getch();
                                        break;
                                    }
                                }
                                borrarOpcionesPartida();
                                ///-------------------------------------------------------


                                ///------------------------------------------------------- BOT
                                if(enfrentamiento == 1){
                                    if(tantoBot > 20){
                                        color(15);
                                        gotoxy(95, 31); printf("*Nota: Tanto mas alto de tus cartas");
                                        gotoxy(95, 32); printf("                 %i", tantoJug);
                                        int envido = envidoBot();
                                        if(envido == 1 && tantoBot > tantoJug){
                                            jugadores[0].puntos += 2;
                                            huboTanto++;
                                        }
                                        else if(envido == 1 && tantoBot < tantoJug){
                                            jugadores[1].puntos += 2;
                                            huboTanto++;
                                        }
                                        else
                                            jugadores[0].puntos += 1;
                                        borrarOpcionesPartida();
                                        enfrentamiento++;
                                    }
                                }
                                if(truco == 0 && enfrentamiento > 1){
                                    int cantarOnoTruco = rand()%2;
                                    if(cantarOnoTruco == 1){
                                        switch(quieroNoQuiero(2)){
                                        case 1:
                                            puntos+=1;
                                            break;
                                        case 2:
                                            jugadores[0].puntos+=1;
                                            break;
                                        }
                                        borrarOpcionesPartida();
                                        truco++;
                                    }
                                }
                                apilar(&mesaBot, mayor(&jugadores[0].cartas));
                                mostrarCartaMesa(tope(&mesaBot)->dato, cantCartasMesa);
                                cantCartasMesa++;
                                ///-------------------------------------------------------
                            }
                            borrarCartasJugVisual(cantElementosPila(jugadores[1].cartas)+1);

                            if(tope(&mesaBot)->dato.nivel < tope(&mesaJug)->dato.nivel){
                                mano2 = 1;
                                puntosMesaJug++;
                            }
                            else if(tope(&mesaBot)->dato.nivel > tope(&mesaJug)->dato.nivel){
                                mano2 = 0;
                                puntosMesaBot++;
                            }
                            else{
                                if(mano2 == 1){
                                    mano2 = 1;
                                    puntosMesaJug++;
                                }
                                else{
                                    mano2 = 0;
                                    puntosMesaBot++;
                                }
                            }
                            enfrentamiento++;
                        }while(!pilaVacia(&jugadores[0].cartas) && truco != -1);
                        borrarDatosPila(&mesaBot);
                        borrarDatosPila(&mesaJug);
                        if(puntosMesaJug > puntosMesaBot)
                            jugadores[1].puntos += puntos;
                        else
                            jugadores[0].puntos += puntos;

                        if(mano == 1){
                            mano = 0;
                            mano2 = 0;
                        }
                        else{
                            mano = 1;
                            mano2 = 1;
                        }
                        if(huboTanto)
                            mostrarTantos(jugadores, tantoJug, tantoBot);
                        getch();
                        borrarOpcionesPartida();
                    }while(jugadores[1].puntos < 15 && jugadores[0].puntos < 15);
                    if(jugadores[0].puntos < jugadores[1].puntos)
                        jugadores[1].jug->dato.puntosHistorial++;
                    break;
                case 2:
                    borrarOpciones();
                    mostrarPerfil(jugador->dato);
                    borrarOpciones();
                    break;
                case 3:
                    borrarOpciones();
                    switch(elegirOpcionConfiguracion()){
                    case 1:
                        cambiarNombreUsuario(jugador);
                        break;
                    case 2:
                        cambiarContrasenia(jugador);
                        break;
                    }
                    borrarOpciones();
                    break;
                case 4:
                    salir++;
                    break;
                }
            }while(salir == 0);
            salir = 0;
             break;

        case 3:
            borrarOpciones();
            menu2();
            lista = agregarUsuario(lista);
            borrarOpciones();
            break;
        case 4:
            system("cls");
            salir++;
            break;
        }
    }while(salir == 0);
    lista = listaToArchivo(archivoUsuarios, lista);

    return 0;
}
