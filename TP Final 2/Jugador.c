#include "Jugador.h"

void ingresarNombreUsuario(char c[])
{
    int i = 0;
    fflush(stdin);
    hidecursor(1);
    color(240);
    gotoxy(60, 21);
    while(c[i]!=13)
    {
        if(i == 1)
        {
            color(4);
            gotoxy(55, 18);
            printf("                              ");
            color(240);
            gotoxy(61, 21);
        }
        c[i] = getch();

        if(c[i]>32 && i<20)
        {
            putchar(c[i]);
            i++;
        }
        else if(c[i]==8 && i>0)
        {
            putchar(8);
            putchar(' ');
            putchar(8);
            i--;
        }
    }
    c[i] = '\0';
    hidecursor(0);
}

void ingresarContrasenia(char c[])
{
    int i = 0;
    fflush(stdin);
    hidecursor(1);

    gotoxy(60, 24);
    while(c[i]!=13)
    {
        if(i == 1)
        {
            color(4);
            gotoxy(55, 18);
            printf("                              ");
            color(240);
            gotoxy(61, 24);
        }
        c[i] = getch();

        if(c[i]>32 && i<20)
        {
            putchar('*');
            i++;
        }
        else if(c[i]==8 && i>0)
        {
            putchar(8);
            putchar(' ');
            putchar(8);
            i--;
        }
    }
    c[i] = '\0';
    hidecursor(0);
}

void intentos(int flag, int usuarioOcontrasenia)
{
    if(flag == 3)
    {
        color(4);
        gotoxy(40, 27);
        printf("Intentaste mas de 3 veces, el programa se cerrara en 5 segundos");
        Sleep(5000);
        system("cls");
        exit(1);
    }
    else if(flag != -1)
    {
        if(usuarioOcontrasenia == 1)
        {
            color(4);
            gotoxy(60, 18);
            printf("El usuario no existe");
            color(240);
            gotoxy(60, 21);
            printf("                     ");
        }
        else if(usuarioOcontrasenia == 2)
        {
            color(4);
            gotoxy(60, 18);
            printf("Contrasenia incorrecta",164);
            hidecursor(0);
            color(240);
            gotoxy(60, 24);
            printf("                     ");
        }
        else
        {
            color(4);
            gotoxy(60, 18);
            printf("El usuario ya existe");
            hidecursor(0);
            color(240);
            gotoxy(60, 21);
            printf("                     ");
        }
    }
}

void mostrarJugador(Jugador a)
{
    color(6);
    gotoxy(60, 18);
    printf("ID del usuario................: %d",a.idUsuario);
    printf("Nombre del Usuario............: %s",a.nombreDeUsuario);
    printf("Puntaje del  Usuario..........: %d",a.puntosHistorial);
    hidecursor(0);
    color(240);
}
