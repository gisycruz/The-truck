#include "Usuarios.h"
nodoJugador * iniclista()
{
    return NULL;
}
nodoJugador *crearNodoJugador(Jugador jug){
    nodoJugador *aux = malloc(sizeof(nodoJugador));
    aux->dato = jug;
    aux->siguiente = NULL;
    return aux;
}

nodoJugador *agregarAlFinal(nodoJugador *lista, nodoJugador *insertar){
    if(lista != NULL){
        if(lista->siguiente != NULL)
            lista->siguiente = agregarAlFinal(lista->siguiente, insertar);
        else{
            insertar->dato.idUsuario = lista->dato.idUsuario+1;
            lista->siguiente = insertar;
        }
    }
    else{
        lista = insertar;
        lista->dato.idUsuario = 0;
    }
    return lista;
}


nodoJugador *borrarLista(nodoJugador *lista){
    if(lista != NULL){
        if(lista->siguiente != NULL)
            borrarLista(lista->siguiente);
        free(lista);
    }
    return NULL;
}

nodoJugador *buscarJugador(nodoJugador *lista, char nombreDeUsuario[]){
    nodoJugador *aux = NULL;
    if(lista != NULL){
        if(strcmpi(lista->dato.nombreDeUsuario, nombreDeUsuario)==0){
            aux = lista;
        }
        else if(lista->siguiente != NULL){
            aux = buscarJugador(lista->siguiente, nombreDeUsuario);
        }
    }
    return aux;
}

nodoJugador *agregarUsuario(nodoJugador *lista){
    Jugador aux;
    aux.puntosHistorial = 0;
    nodoJugador *usuario;
    int flag = 0;
    aux.bajado = 0;

    color(240);
    do{
        ingresarNombreUsuario(aux.nombreDeUsuario);
        usuario = buscarJugador(lista, aux.nombreDeUsuario);
        if(usuario != NULL){
            flag++;
            intentos(flag, 3);
        }
    }while(usuario != NULL);

    ingresarContrasenia(aux.contrasenia);
    color(15);

    lista = agregarAlFinal(lista, crearNodoJugador(aux));
    return lista;
}

void lTF(FILE *fi, nodoJugador *lista){
    if(lista != NULL){
        Jugador aux = lista->dato;
        fwrite(&aux, sizeof(Jugador), 1, fi);
        if(lista->siguiente != NULL)
            lTF(fi, lista->siguiente);
    }
}

nodoJugador *listaToArchivo(char f[], nodoJugador *lista){
    FILE *fi = fopen(f, "wb");

    if(fi != NULL){
        lTF(fi, lista);
        if(fclose(fi) != 0)
            printf("\n Error closing file");
    }
    else
        printf("\n Error opening file");
    return borrarLista(lista);
}

nodoJugador *fTL(FILE *fi){
    nodoJugador *aux = NULL;
    Jugador aux2;
    if(fread(&aux2, sizeof(Jugador), 1, fi) > 0){
        aux = crearNodoJugador(aux2);
        aux->siguiente = fTL(fi);
    }
    return aux;
}


nodoJugador *archivoToLista(char archivoJugadores[]){
    FILE *archi = fopen(archivoJugadores, "rb");
    nodoJugador *aux = NULL;
    if(archi != NULL){
        aux = fTL(archi);
        if(fclose(archi) != 0){
            system("cls");
            printf("\n Error al cerrar el archivo\n");
        }
    }
    else{
        system("cls");
        printf("\n Error al abrir el archivo\n");
    }
    return aux;
}

nodoJugador *iniciarSesionUsuario(nodoJugador *lista){
    char nombreUsuario[30];
    char contrasenia[30];
    nodoJugador *usuario = NULL;

    int flag = 0;
    color(240);
    do{
        ingresarNombreUsuario(nombreUsuario);
        usuario = buscarJugador(lista, nombreUsuario);
        if(usuario == NULL){
            flag ++;
            intentos(flag, 1);
        }
    }while(usuario == NULL);
    flag = 0;
    if(usuario->dato.bajado == 1){
        color(4);
        gotoxy(40, 27);
        printf("El usuario esta baneado, el programa se cerrara en 5 segundos");
        Sleep(5000);
        system("cls");
        exit(1);
    }

    do{
        ingresarContrasenia(contrasenia);
        flag ++;
        if(strcmpi(contrasenia, usuario->dato.contrasenia) == 0)
            flag = -1;
        intentos(flag, 2);
    }while(flag != -1);

    return usuario;
}

void cambiarContrasenia(nodoJugador *aux){
    borrarOpciones();
    gotoxy(60, 23); printf("Contrase%ca", 164);
    color(240);
    gotoxy(60, 24); printf("                     ");
    ingresarContrasenia(aux->dato.contrasenia);
    borrarOpciones();
}

void cambiarNombreUsuario(nodoJugador *aux){
    borrarOpciones();
    gotoxy(60, 20); printf("Nombre de usuario");
    color(240);
    gotoxy(60, 21); printf("                     ");
    ingresarNombreUsuario(aux->dato.nombreDeUsuario);
    borrarOpciones();
}


