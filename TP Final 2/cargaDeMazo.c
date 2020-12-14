#include "cargaDeMazo.h"

void cargarArchivo (char archivo [] )
{
    char opcion;

    Carta a ;
    FILE * archi=fopen(archivo, "ab");
    if (archi != NULL)
    {
        do
        {

            printf("\n Numero.......:");
            fflush(stdin);
            scanf("%d",&a.num);
            printf("\n Clase.......:");
            fflush(stdin);
            scanf("%s",&a.clase);
            printf("\n nivel.......:");
            fflush(stdin);
            scanf("%d",&a.nivel);

            fwrite(&a,sizeof(Carta),1,archi);

            system("cls");
            printf("\n ESC para salir ");
            opcion=getch();
        }
        while(opcion!=27);
        fclose(archi);
    }

}
void mostrarMazo (Carta a)
{
    printf("\n-------------------------------------\n");
    printf("\n Numero......:%d",a.num);
    printf("\n Clase.......:%s",a.clase);
    printf("\n Nivel......:%d",a.nivel);
    printf("\n-------------------------------------\n");
}
void mostrarArchivoMazo (char archivo [])
{
    Carta a;
    FILE*arch=fopen(archivo,"rb");
    if (arch)
    {
        while(fread(&a,sizeof(Carta),1,arch)>0)
        {
            mostrarMazo(a);
        }
        fclose(arch);
    }
}

int cantRegistros(char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    int cant = 0;
    if(archi != NULL){
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi) / sizeof(Carta);
        fclose(archi);
    }
    return cant;
}
