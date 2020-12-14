#include "Administrador.h"
#include "Jugador.h"
void iniciarSesionAdmin()
{
    char nombre[30] = {"admin"};
    char contrasenia[30] = {"123451"};
    char nombreAevaluar[30];
    char contraseniaAevaluar[30];
    int flag = 0;

    color(240);
    do
    {
        ingresarNombreUsuario(nombreAevaluar);
        if(strcmpi(nombreAevaluar, nombre) != 0)
        {
            flag ++;
            intentos(flag, 1);
        }
        else
            flag = -1;//no se encontro
    }
    while(flag != -1);
    flag = 0;

    do
    {
        ingresarContrasenia(contraseniaAevaluar);
        if(strcmpi(contraseniaAevaluar, contrasenia) != 0)
        {
            flag ++;
            intentos(flag, 2);
        }
        else
            flag = -1;// incorrecta
    }
    while(flag != -1);

    intentos(flag,nombreAevaluar);
    intentos(flag, contraseniaAevaluar);
    color(15);

}
void textoAdministrador()
{
    color(15);
    gotoxy(30,5); puts ("             __          _       _      __                 __            ");
    gotoxy(30,6); puts ("  ____ _____/ /___ ___  (_)___  (_)____/ / _____ ___  ____/ /__   _____  ");
    gotoxy(30,7); puts (" / __ `/ __  / __ `__ \/ / __ \\/ / ___/ __/ ___/ __ `/ __  / _  \\/ ___/  ");
    gotoxy(30,8); puts ("/ /_/ / /_/ / / / / / / / / / / (__  ) /_/ /  / /_/ / /_/ / /_/ / /      ");
    gotoxy(30,9); puts ("\\__,_/\\__,_/_/ /_/ /_/_/_/ /_/_/____/\\__/_/   \\__,_/\\__,_/\\____/_/       ");
}
void printOpcionesAdministrador()
{
    color(240);
    gotoxy(59, 20);
    puts(" Buscar Usuario   ");
    color(15);
    gotoxy(59, 21);
    puts(" Baja Usuario     ");
    gotoxy(59, 22);
    puts(" Alta Usuario     ");
    gotoxy(59, 23);
    puts(" Salir            ");
}

void opcionesMenu3(int opcion, int color2)
{
    switch(opcion)
    {
    case 1:
        if(color2 == 1)
        {
            color(240);
            gotoxy(59, 20);
            puts(" Buscar Usuario   ");
            color(15);
        }
        else
        {
            color(15);
            gotoxy(59, 20);
            puts(" Buscar Usuario   ");
        }
        break;
    case 2:
        if(color2 == 1)
        {
            color(240);
            gotoxy(59, 21);
            puts(" Baja Usuario     ");
            color(15);
        }
        else
        {
            color(15);
            gotoxy(59, 21);
            puts(" Baja Usuario     ");
        }
        break;
    case 3:
        if(color2 == 1)
        {
            color(240);
            gotoxy(59, 22);
            puts(" Alta Usuario     ");
            color(15);
        }
        else
        {
            color(15);
            gotoxy(59, 22);
            puts(" Alta Usuario     ");
            color(15);
        }
        break;
    case 4:
        if(color2 == 1)
        {
            color(240);
            gotoxy(59, 23);
            puts(" Salir            ");
            color(15);
        }
        else
        {
            color(15);
            gotoxy(59, 23);
            puts(" Salir            ");
            color(15);
        }
        break;
    }
}

int moverCursorAdministrador(){
    int opcion=1;
    char control;
    printOpcionesAdministrador();
    do{
        opcionesMenu3(opcion,1);
        control = getch();
        if(control == 80 && opcion<4){
            opcionesMenu3(opcion,0);
            opcion++;
        }
        if(control == 72 && opcion> 1){
            opcionesMenu3(opcion,0);
            opcion--;
        }
    }while(control != 13);
    return opcion;
}
void OpcionBuscarUsuario ()
{
    color(15);
    gotoxy(60, 20);
    puts("Nombre de usuario");
    color(240);
    gotoxy(60, 21);
    printf("                     ");
    color(15);
}
int menu3(nodoArbol *arbol, nodoJugador* lista)
{
    int opcion, salir = 0;
    nodoArbol * buscar=NULL;
    char nombreUsuario[30];
    do{
        color(15);
        system("cls");
        marcoMenu(0);
        textoAdministrador();
        opcion = moverCursorAdministrador();
        switch(opcion){
        case 1:
            system("cls");
            marcoMenu(0);
            textoAdministrador();
            OpcionBuscarUsuario();
            ingresarNombreUsuario(nombreUsuario);
            buscar=buscarxNombre(arbol, nombreUsuario);
            if (buscar)
                mostrarNodoArbol(buscar);
            else
            {
                color(4);
                gotoxy(60, 18);
                printf(" NO Existe el usuario");
                hidecursor(0);
                color(240);
            }
            break;
        case 2:
            system("cls");
            marcoMenu(0);
            textoAdministrador();
            OpcionBuscarUsuario();
            ingresarNombreUsuario(nombreUsuario);
            buscar=buscarxNombre(arbol, nombreUsuario);
            if (buscar)
            {
                buscarJugador(lista, buscar->dato.nombreDeUsuario)->dato.bajado=1;
            }
            else
            {
                color(4);
                gotoxy(60, 18);
                printf(" NO Existe el usuario");
                hidecursor(0);
                color(15);
            }
            break;
        case 3:
            system("cls");
            marcoMenu(0);
            textoAdministrador();
            OpcionBuscarUsuario();
            ingresarNombreUsuario(nombreUsuario);
            buscar=buscarxNombre(arbol, nombreUsuario);
            if (buscar)
            {
                buscarJugador(lista, buscar->dato.nombreDeUsuario)->dato.bajado=0;
            }
            else
            {
                color(4);
                gotoxy(60, 18);
                printf(" NO Existe el usuario");
                hidecursor(0);
                color(240);
            }
            break;
        case 4:
          system("cls");
            salir++;
            break;
        }
    }while(salir==0);
    return opcion;
}



