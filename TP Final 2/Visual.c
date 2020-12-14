#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Cartas.h"
#include "Pila.h"
#include "CeldaMazo.h"
#include "gotoxy.h"

void marcoMenu(int linea){
    int x, y;
    color(5);

    /// Cuadrado Lineas
    for(y=1; y<144; y++){
        gotoxy(y, 0); printf("%c", 205);
    }
    for(x=0; x<34; x++){
        gotoxy(144, x); printf("%c", 186);
    }
    for(x=1; x<34; x++){
        gotoxy(1, x); printf("%c", 186);
    }
    for(y=1; y<144; y++){
        gotoxy(y, 34); printf("%c", 205);
    }
    /// Esquinas
    gotoxy(1, 0); printf("%c", 201);
    gotoxy(144, 0); printf("%c", 187);
    gotoxy(1, 34); printf("%c", 200);
    gotoxy(144, 34); printf("%c", 188);

    if(linea == 1){
        for(int i=17; i<34; i++){
            gotoxy(83, i);
            printf("%c", 186);
        }
        for(int i=83; i<144; i++){
            gotoxy(i, 17);
            printf("%c", 205);
        }
        gotoxy(144, 17); printf("%c", 185);
        gotoxy(83, 17); printf("%c", 201);
        gotoxy(83, 34); printf("%c", 202);

        color(5);
        gotoxy(83, 21); printf("%c", 204);

        gotoxy(113, 17); printf("%c", 203);
        for(int i=84; i<144; i++){
            if(i == 113){
                for(int j = 18; j<21; j++){
                    gotoxy(i, j); printf("%c", 186);
                }
            }
            gotoxy(i, 21); printf("%c", 205);
        }
        gotoxy(113, 21); printf("%c", 202);
    }
    color(15);
}

void textoTheTrick(){

gotoxy(45, 5); puts(" _______ _              _______    _       _     ");
gotoxy(45, 6); puts("(_______) |            (_______)  (_)     | |    ");
gotoxy(45, 7); puts("    _   | |__  _____       _  ____ _  ____| |  _ ");
gotoxy(45, 8); puts("   | |  |  _ \\| ___ |     | |/ ___) |/ ___) |_/ )");
gotoxy(45, 9); puts("   | |  | | | | ____|     | | |   | ( (___|  _ ( ");
gotoxy(45, 10); puts("   |_|  |_| |_|_____)     |_|_|   |_|\\____)_| \\_)");
}

int moverCursor(int X, int Y, int arriba, int abajo, int saltos, int menu){
    int x=X, y=Y, opcion=1;
    char control;

    hidecursor(0);
    switch(menu){
    case 1:
        printOpcionesMenu1();
        break;
    case 2:
        printOpcionesDentroDelJuego();
    }

    do{
        control = getch();
        if(control !=13){
            if(control == 80 && x < abajo){
                x+=saltos;
                opcion++;
            }
            else if(control == 72 && x > arriba){
                x-=saltos;
                opcion--;
            }
            else if(control == 80 && x == abajo+1){
                x-=saltos;
                opcion--;
            }
            else if(control == 72 && x == arriba-1){
                x+=saltos;
                opcion++;
            }

            if(control == 80){
                switch(menu){
                case 1:
                    opcionesMenu1(opcion-1, 0);
                    opcionesMenu1(opcion, 1);
                    break;
                case 2:
                    opcionesMenuDentroDelJuego(opcion-1, 0);
                    opcionesMenuDentroDelJuego(opcion, 1);
                    break;
                }
            }
            else if(control == 72){
                switch(menu){
                case 1:
                    opcionesMenu1(opcion+1, 0);
                    opcionesMenu1(opcion, 1);
                    break;
                case 2:
                    opcionesMenuDentroDelJuego(opcion+1, 0);
                    opcionesMenuDentroDelJuego(opcion, 1);
                    break;
                }
            }
        }
    }while(control != 13);
    color(15);
    gotoxy(y, x); printf(" ");

    return opcion;
}

void printOpcionesMenu1(){
    color(240);
    gotoxy(59, 20); puts(" Iniciar como Admin   ");
    color(15);
    gotoxy(59, 21); puts(" Iniciar como Usuario ");
    gotoxy(59, 22); puts(" Registrarse          ");
    gotoxy(59, 23); puts(" Salir                ");
}

void printOpcionesDentroDelJuego(){
    color(240);
    gotoxy(59, 20); puts(" Jugar una partida    ");
    color(15);
    gotoxy(59, 21); puts(" Ver perfil           ");
    gotoxy(59, 22); puts(" Configuracion        ");
    gotoxy(59, 23); puts(" Cerrar sesion        ");
}


void opcionesMenu1(int opcion, int color2){
    switch(opcion){
    case 1:
        if(color2 == 1){
            color(240);
            gotoxy(59, 20); puts(" Iniciar como Admin   ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 20); puts(" Iniciar como Admin   ");
        }
        break;
    case 2:
        if(color2 == 1){
            color(240);
            gotoxy(59, 21); puts(" Iniciar como Usuario ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 21); puts(" Iniciar como Usuario ");
        }
        break;
    case 3:
        if(color2 == 1){
            color(240);
            gotoxy(59, 22); puts(" Registrarse          ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 22); puts(" Registrarse          ");
        }
        break;
    case 4:
        if(color2 == 1){
            color(240);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        break;
    }
}

void opcionesMenuDentroDelJuego(int opcion, int color2){
    switch(opcion){
    case 1:
        if(color2 == 1){
            color(240);
            gotoxy(59, 20); puts(" Jugar una partida    ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 20); puts(" Jugar una partida    ");
            color(15);
        }
        break;
    case 2:
        if(color2 == 1){
            color(240);
            gotoxy(59, 21); puts(" Ver perfil           ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 21); puts(" Ver perfil           ");
            color(15);
        }
        break;
    case 3:
        if(color2 == 1){
            color(240);
            gotoxy(59, 22); puts(" Configuracion        ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 22); puts(" Configuracion        ");
            color(15);
        }
        break;
    case 4:
        if(color2 == 1){
            color(240);
            gotoxy(59, 23); puts(" Cerrar sesion        ");
            color(15);

        }
        else{
            color(15);
            gotoxy(59, 23); puts(" Cerrar sesion        ");
            color(15);

        }
        break;
    }
}

int menu1(){
    int opcion;

    marcoMenu(0);
    textoTheTrick();
    opcion = moverCursor(20, 58, 20, 23, 1, 1);

    return opcion;
}

int menuDentroDelJuego(){
    int opcion;

    color(15);
    gotoxy(59, 24); puts("                        ");
    marcoMenu(0);
    textoTheTrick();
    opcion = moverCursor(20, 58, 20, 23, 1, 2);

    return opcion;
}

void menu2(){
    color(15);
    gotoxy(60, 20); puts("Nombre de usuario");
    color(240);
    gotoxy(60, 21); printf("                     ");
    gotoxy(60, 24); printf("                     ");
    color(15);
    gotoxy(60, 23); printf("Contrase%ca", 164);
}

void buscarPartida(){
    system("cls");
    marcoMenu(0);
    for(int i=0; i<2; i++){
        gotoxy(60, 17); printf("Buscando partida.  ");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida.. ");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida...");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida   ");
    }

}

void marcosTableros(){

    ///Arriba
    for(int y=4; y<80; y++){
        gotoxy(y, 17); printf("%c", 196);
    }
    ///Derecha
    for(int x=17; x<34; x++){
        gotoxy(80, x); printf("%c", 179);
    }
    ///Izquierda
    for(int x=17; x<34; x++){
        gotoxy(4, x); printf("%c", 179);
    }
    ///Abajo
    for(int y=4; y<80; y++){
        gotoxy(y, 33); printf("%c", 196);
    }

    gotoxy(4, 17); printf("%c", 218);
    gotoxy(80, 17); printf("%c", 191);
    gotoxy(4, 33); printf("%c", 192);
    gotoxy(80, 33); printf("%c", 217);
}


void cartasAbajo(int de, int hasta, nodoCarta *carta, int numCarta){
    color(240);
    for(int i=19; i<32; i++){
        for(int j=de; j<hasta; j++){
            gotoxy(j, i); printf(" ");
        }
    }

    color(15);
    if(strcmpi(carta->dato.clase, "basto") == 0)
        color(47);
    else if(strcmpi(carta->dato.clase, "oro") == 0)
        color(224);
    else if(strcmpi(carta->dato.clase, "espada") == 0)
        color(159);
    else
        color(207);

    switch(numCarta){
        case 1:
            gotoxy(11,20); printf("%i", carta->dato.num);
            gotoxy(17, 25); printf("%s", carta->dato.clase);
            if(carta->dato.num > 9){
                gotoxy(26, 30); printf("%i", carta->dato.num);
            }
            else{
                gotoxy(27, 30); printf("%i", carta->dato.num);
            }
            color(15);
            break;
        case 2:
            gotoxy(34,20); printf("%i", carta->dato.num);
            gotoxy(40, 25); printf("%s", carta->dato.clase);
            if(carta->dato.num > 9){
                gotoxy(49, 30); printf("%i", carta->dato.num);
            }
            else{
                gotoxy(50, 30); printf("%i", carta->dato.num);
            }
            color(15);
            break;
        case 3:
            gotoxy(57,20); printf("%i", carta->dato.num);
            gotoxy(63, 25); printf("%s", carta->dato.clase);
            if(carta->dato.num > 9){
                gotoxy(72, 30); printf("%i", carta->dato.num);
            }
            else{
                gotoxy(73, 30); printf("%i", carta->dato.num);
            }
            color(15);
            break;
        }
}

void mostrarCartasJugador1(CeldaMazo celdas[]){
    Pila aux;
    inicPila(&aux);

    while(!pilaVacia(&celdas[1].cartas))
        apilar(&aux, desapilar(&celdas[1].cartas));

    if(!pilaVacia(&aux)){
        cartasAbajo(10,29, tope(&aux), 1);
        apilar(&celdas[1].cartas, desapilar(&aux));
        if(!pilaVacia(&aux)){
            cartasAbajo(33,52, tope(&aux), 2);
            apilar(&celdas[1].cartas, desapilar(&aux));
            if(!pilaVacia(&aux)){
                cartasAbajo(56,75, tope(&aux), 3);
                apilar(&celdas[1].cartas, desapilar(&aux));
            }
        }
    }
}

void marcoSeleccionCarta(int carta, int eliminar){
    int de, hasta;

    switch(carta){
    case 1:
        de = 8;
        hasta = 30;
        break;
    case 2:
        de = 31;
        hasta = 53;
        break;
    case 3:
        de = 54;
        hasta = 76;
        break;
    }

    if(eliminar == 1)
        color(0);

    for(int i=de; i<hasta; i++){
        gotoxy(i, 18); printf("%c", 196);
        gotoxy(i, 32); printf("%c", 196);
    }
    for(int i=18; i<32; i++){
        gotoxy(de, i); printf("%c", 179);
        gotoxy(hasta, i); printf("%c", 179);
    }
    gotoxy(de, 18); printf("%c", 218);
    gotoxy(hasta, 18); printf("%c", 191);
    gotoxy(de, 32); printf("%c", 192);
    gotoxy(hasta, 32); printf("%c", 217);
    color(15);
}

int elegirCarta(int cant){
    int opcion = 1;
    char control;

    do{
        switch(opcion){
        case 1:
            marcoSeleccionCarta(1, 0);
            break;
        case 2:
            marcoSeleccionCarta(2, 0);
            break;
        case 3:
            marcoSeleccionCarta(3, 0);
            break;
        }

        hidecursor(0);
        control = getch();

        if(control == 77 && opcion < cant){
            marcoSeleccionCarta(opcion, 1);
            opcion++;
        }
        else if(control == 75 && opcion > 1){
            marcoSeleccionCarta(opcion, 1);
            opcion--;
        }
    }while(control != 13);
    marcoSeleccionCarta(opcion, 1);
    return opcion;
}

void mostrarCartaMesa(Carta aMostrar, int posPantalla){
    int de, hasta;

    switch(posPantalla){
    case 1:
        de = 6;
        hasta = 25;
        break;
    case 2:
        de = 29;
        hasta = 48;
        break;
    case 3:
        de = 52;
        hasta = 71;
        break;
    case 4:
        de = 75;
        hasta = 94;
        break;
    case 5:
        de = 98;
        hasta = 117;
        break;
    case 6:
        de = 121;
        hasta = 140;
        break;
    }
    color(240);
    for(int i=2; i<15; i++){
        for(int j=de; j<hasta; j++){
            gotoxy(j, i); printf(" ");
        }
    }
    color(15);

    if(strcmpi(aMostrar.clase, "basto") == 0)
        color(47);
    else if(strcmpi(aMostrar.clase, "oro") == 0)
        color(224);
    else if(strcmpi(aMostrar.clase, "espada") == 0)
        color(159);
    else
        color(207);

    gotoxy(de+1, 3); printf("%i", aMostrar.num);
    if(aMostrar.num > 9){
        gotoxy(hasta-3, 13); printf("%i", aMostrar.num);
    }
    else{
        gotoxy(hasta-2, 13); printf("%i", aMostrar.num);
    }
    gotoxy(de+7, 8); printf("%s", aMostrar.clase);
    color(15);
}

void borrarCartasJugVisual(int carta){
    int de, hasta;

    switch(carta){
    case 1:
        de = 10;
        hasta = 29;
        break;
    case 2:
        de = 33;
        hasta = 52;
        break;
    case 3:
        de = 56;
        hasta = 75;
        break;
    }

    if(carta < 4){
        color(0);
        for(int i=19; i<32; i++){
            for(int j=de; j<hasta; j++){
                gotoxy(j, i); printf(" ");
            }
        }
        color(15);
    }
}

void borrarOpciones(){
    color(0);
    for(int i=12; i<30; i++){
        for(int j = 50; j<90; j++){
            gotoxy(j, i);  printf(" ");
        }
    }
    color(15);
}

void mostrarPerfil(Jugador aux){
    color(5);

    for(int i=55; i<85; i++){
        gotoxy(i, 13); printf("%c", 196);
        gotoxy(i, 28); printf("%c", 196);
    }
    for(int i=13; i<28; i++){
        gotoxy(55, i); printf("%c", 179);
        gotoxy(85, i); printf("%c", 179);
    }
    gotoxy(55, 13); printf("%c", 218);
    gotoxy(85, 13); printf("%c", 191);
    gotoxy(55, 28); printf("%c", 192);
    gotoxy(85, 28); printf("%c", 217);

    gotoxy(61, 18); printf("ID Usuario");
    gotoxy(61, 21); printf("Nombre de Usuario");
    gotoxy(61, 24); printf("Partidas Ganadas");
    color(15);

    gotoxy(67, 15); printf("PERFIL");
    gotoxy(61, 19); printf("%i", aux.idUsuario);
    gotoxy(61, 22); printf("%s", aux.nombreDeUsuario);
    gotoxy(61, 25); printf("%i", aux.puntosHistorial);

    color(240);
    gotoxy(61, 31); printf("       Salir       ");
    color(5);
    char control;
    do{
        control = getch();
    }while(control != 13);
    gotoxy(61, 31); printf("                   ");
}

void mostrarNombres(CeldaMazo celdas[]){
    /// Puntos Bot
    gotoxy(98-(strlen(celdas[1].jug->dato.nombreDeUsuario)/2), 18); printf("%s", celdas[1].jug->dato.nombreDeUsuario);
    /// Puntos Jugador
    gotoxy(129-(strlen(celdas[0].jug->dato.nombreDeUsuario)/2), 18); printf("%s", celdas[0].jug->dato.nombreDeUsuario);
}

void mostrarPuntos(CeldaMazo celdas[]){
    gotoxy(127, 20); printf("     ");
    gotoxy(87, 20); printf("     ");

    if(celdas[0].puntos < 10){
        gotoxy(129, 20); printf("%i", celdas[0].puntos);
    }
    else{
        gotoxy(128, 20); printf("%i", celdas[0].puntos);
    }

    if(celdas[1].puntos < 10){
        gotoxy(98, 20); printf("%i", celdas[1].puntos);
    }
    else{
        gotoxy(97, 20); printf("%i", celdas[1].puntos);
    }
}

void borrarCartasMesa(){
    color(0);
    for(int i=2; i<15; i++){
        for(int j=2; j<143; j++){
            gotoxy(j, i); printf(" ");
        }
    }
    color(5);
}

void printOpcionesCantarPrimerEnfrentamiento(){
    color(15);
    gotoxy(99, 25); printf("           Envido            ");
    gotoxy(99, 26); printf("           Truco             ");
    gotoxy(99, 27); printf("           Nada              ");
}

void printOpcionesCantar(){
    color(15);
    gotoxy(99, 25); printf("           Truco             ");
    gotoxy(99, 26); printf("           Nada              ");
}

void marcarOpcionesCantarPrimerEnfrentamiento(int opcion, int marcar){
    if(marcar == 1)
        color(240);
    else
        color(15);

    switch(opcion){
    case 1:
        gotoxy(99, 25);
        printf("           Envido            ");
        break;
    case 2:
        gotoxy(99, 26);
        printf("           Truco             ");
        break;
    case 3:
        gotoxy(99, 27);
        printf("           Nada              ");
        break;
    }
    color(15);
}

void marcarOpcionesCantar(int opcion, int marcar){
    if(marcar == 1)
        color(240);
    else
        color(15);

    switch(opcion){
    case 1:
        gotoxy(99, 25);
        printf("           Truco             ");
        break;
    case 2:
        gotoxy(99, 26);
        printf("           Nada              ");
        break;
    }
    color(15);
}

int elegirOpcionCantar(int enfrentamiento){
    char control;
    int opcion = 1;
    if(enfrentamiento < 2)
        printOpcionesCantarPrimerEnfrentamiento();
    else
        printOpcionesCantar();
    hidecursor(0);

    do{
        if(enfrentamiento < 2)
            marcarOpcionesCantarPrimerEnfrentamiento(opcion, 1);
        else
            marcarOpcionesCantar(opcion, 1);
        control = getch();

        if(enfrentamiento < 2){
            if (control==80 && opcion < 3){
                marcarOpcionesCantarPrimerEnfrentamiento(opcion, 0);
                opcion++;
            }
            else if (control==72 && opcion > 1){
                marcarOpcionesCantarPrimerEnfrentamiento(opcion, 0);
                opcion--;
            }
        }
        else{
            if (control==80 && opcion < 2){
                marcarOpcionesCantar(opcion, 0);
                opcion++;
            }
            else if (control==72 && opcion > 1){
                marcarOpcionesCantar(opcion, 0);
                opcion--;
            }
        }
    }while(control != 13);

    return opcion;
}

void borrarOpcionesPartida(){
    color(0);
    for(int i=22; i<34; i++){
        for(int j=85; j<143; j++){
            gotoxy(j, i); printf(" ");
        }
    }
    color(15);
}

void printQuieroNoQuiero(int opcion, int eliminarMarca){
    if(eliminarMarca == 1)
        color(15);
    else
        color(240);

    switch(opcion){
    case 1:
        gotoxy(101, 28); printf("         Quiero         ");
        break;
    case 2:
        gotoxy(101, 29); printf("        No Quiero       ");
        break;
    }
    color(15);
}

int quieroNoQuiero(int caso){
    int opcion = 1;
    char control;
    hidecursor(0);

    color(240);
    gotoxy(99, 24); printf("                            ");
    gotoxy(99, 26); printf("                            ");
    switch(caso){
    case 1:
        gotoxy(99, 25); printf("           ENVIDO           ");
        printQuieroNoQuiero(2, 1);
        break;
    case 2:
        gotoxy(99, 25); printf("            TRUCO           ");
        printQuieroNoQuiero(2, 1);
        break;
    }
    color(15);

    do{
        printQuieroNoQuiero(opcion, 0);
        control = getch();
        if (control==80 && opcion < 2){
            printQuieroNoQuiero(opcion, 1);
            opcion++;
        }
        else if (control==72 && opcion > 1){
            printQuieroNoQuiero(opcion, 1);
            opcion--;
        }
    }while(control != 13);
    return opcion;
}

void mostrarTantos(CeldaMazo celdas[], int jug, int bot){
    color(240);
    for(int i=24; i<31; i++){
        for(int j=96; j<130; j++){
            gotoxy(j, i); printf(" ");
        }
    }
    gotoxy(110, 25); printf("ENVIDO");
    gotoxy(100, 28); printf("Tanto (%s): %i", celdas[0].jug->dato.nombreDeUsuario, bot);
    gotoxy(100, 27); printf("Tanto (%s): %i", celdas[1].jug->dato.nombreDeUsuario, jug);
    color(15);
}

void mostrarQuieroNoQuieroBot(int quieroOno){
    borrarOpcionesPartida();
    color(240);
    gotoxy(99, 26); printf("                            ");
    gotoxy(99, 28); printf("                            ");
    switch(quieroOno){
    case 1:
        gotoxy(99, 27); printf("           QUIERO           ");
        break;
    case 2:
        gotoxy(99, 27); printf("          NO QUIERO         ");
        break;
    }
    color(15);
}

void printOpcionesConfiguracion(){
    color(240);
    gotoxy(59, 20); printf("  Cambiar nombre de usuario  ");
    color(15);
    gotoxy(59, 21); printf("  Cambiar contrase%ca        ", 164);
    gotoxy(59, 22); printf("  Salir                      ");
}

void marcarOpcionesConfiguracion(int opcion, int marcar){
    if(marcar == 1)
        color(240);
    else
        color(15);

    switch(opcion){
        case 1:
            gotoxy(59, 20); printf("  Cambiar nombre de usuario  ");
            break;
        case 2:
            gotoxy(59, 21); printf("  Cambiar contrase%ca         ", 164);
            break;
        case 3:
            gotoxy(59, 22); printf("  Salir                      ");
            break;
    }
}

int elegirOpcionConfiguracion(){
    int opcion = 1;
    char control;

    printOpcionesConfiguracion();

    do{
        marcarOpcionesConfiguracion(opcion, 1);
        control = getch();
        if(control == 80 && opcion < 3){
            marcarOpcionesConfiguracion(opcion, 0);
            opcion++;
        }
        else if(control == 72 && opcion > 1){
            marcarOpcionesConfiguracion(opcion, 0);
            opcion--;
        }
    }while(control != 13);
    return opcion;
}
