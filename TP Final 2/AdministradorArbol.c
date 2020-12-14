#include "Administrador.h"
nodoArbol * inicArbol()
{
    return NULL;
}
nodoArbol * crearnodoArbol(Jugador datos)
{
    nodoArbol * nuevo= (nodoArbol*)malloc(sizeof (nodoArbol));
    nuevo->dato=datos;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}
nodoArbol * insertarDatoArbol(nodoArbol * arbol,Jugador datos)
{
    if (arbol == NULL)
    {
        arbol=crearnodoArbol(datos);


    }
    else
    {
        if (strcmpi(datos.nombreDeUsuario, arbol->dato.nombreDeUsuario) < 0)
            arbol->izq=insertarDatoArbol(arbol->izq,datos);
        else
            arbol->der=insertarDatoArbol(arbol->der,datos);
    }
    return arbol;
}
nodoArbol * buscasDatoArbol(nodoArbol * arbol, int idUsuario)
{
    nodoArbol * buscar= NULL;
    if (arbol)
    {
        if (arbol->dato.idUsuario == idUsuario)
        {
            buscar=arbol;
        }
        else
        {
            if(idUsuario < arbol->dato.idUsuario )
                buscar=buscasDatoArbol(arbol->izq, idUsuario);
            else
                buscar=buscasDatoArbol(arbol->der, idUsuario);
        }
    }
    return buscar;
}

nodoArbol * buscarxNombre(nodoArbol * arbol, char nombre []){
    nodoArbol * buscar=NULL;
    if (arbol)
    {
        int comp = strcmp(arbol->dato.nombreDeUsuario,nombre);
        if (comp == 0)
            buscar=arbol;
        else if(comp > 0)
            buscar=buscarxNombre(arbol->izq,nombre);
        else
            buscar=buscarxNombre(arbol->izq,nombre);
    }
    return buscar;
}

void Inorden(nodoArbol * arbol){
    if (arbol)
    {
        Inorden(arbol->izq);
        mostrarNodoArbol(arbol);
        Inorden(arbol->der);
    }

}

void mostrarNodoArbol (nodoArbol * arbol ){
    borrarOpciones();
    mostrarPerfil(arbol->dato);

}

nodoArbol * masCercaIsq(nodoArbol * arbol){
    nodoArbol * MgI ;
    if(arbol->der == NULL  && arbol->izq == NULL)
    {
        MgI=arbol;
    }
    else
        MgI=masCercaIsq(arbol->der);

    return MgI;
}

nodoArbol * masCercaDer(nodoArbol * arbol){
    nodoArbol * MgD ;
    if(arbol->der == NULL  && arbol->izq == NULL)
    {
        MgD=arbol;
    }
    else
        MgD=masCercaIsq(arbol->izq);

    return MgD;
}

nodoArbol * borrarNodoArbol (nodoArbol * arbol, int idusuario){
    nodoArbol * mgi;
    nodoArbol * mgd;
    if(arbol)
    {
        if(idusuario == arbol->dato.idUsuario)
        {
            if(arbol->izq != NULL)
            {
                mgi=masCercaIsq(arbol->izq);
                arbol->dato=mgi->dato;
                arbol->izq=borrarNodoArbol(arbol->izq,mgi->dato.idUsuario);
            }

            else
            {
                if (arbol->der != NULL)
                {
                    mgd=masCercaDer(arbol->der);
                    arbol->dato=mgd->dato;
                    arbol->der=borrarNodoArbol(arbol->der,mgd->dato.idUsuario);
                }

                else
                {
                    free(arbol);
                    arbol=NULL;
                }
            }
        }
        else
        {

            if ( idusuario > arbol->dato.idUsuario)
            {
                arbol->der=borrarNodoArbol(arbol->der,idusuario);
            }
            else
            {
                arbol->izq=borrarNodoArbol(arbol->izq,idusuario);
            }
        }

    }
    return arbol;
}

nodoArbol * PasaArchivoUsuarioToArbol (nodoArbol * arbol, char archiUsuario []){
    Jugador usuario;
    FILE * archi=fopen(archiUsuario,"rb");
    if (archi)
    {
        while(fread(&usuario,sizeof(Jugador),1,archi)>0)
        {

            arbol=insertarDatoArbol(arbol,usuario);

        }
    }
    fclose(archi);

    return arbol;
}
