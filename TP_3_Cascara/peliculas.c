#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "funciones.h"
#include "Peliculas.h"

void agregarPelicula(EMovie** pelicula,int*  peliculasCargadas,int *totalPeliculas, int* cantPunteros)
{
    ampliarMemoria(pelicula, *peliculasCargadas,totalPeliculas,cantPunteros);
    if(agregarDatos(pelicula,peliculasCargadas,totalPeliculas))
    {
        agregarPeliculaBinario(pelicula,peliculasCargadas);
        printf("\nExito al cargar.\n\n");
        (*peliculasCargadas)++;
        cualquierTeclaContinuar();
    }
}

void ampliarMemoria(EMovie** pelicula,int peliculasCargadas,int* totalPeliculas,int* cantPunteros)
{
    EMovie** auxArray;
    int index;

    while(((*totalPeliculas)-peliculasCargadas)<10)
    {
        auxArray=(EMovie**)realloc(pelicula,sizeof(EMovie*)*((*cantPunteros)+100));
        if(auxArray==NULL)
        {
            printf("No hay memoria\n");
            return;
        }
        pelicula=auxArray;
        *cantPunteros+=100;
        printf("\nLa memoria fue ampliada.\n\n");

        for(index=*totalPeliculas; index<(*totalPeliculas+100); index++)
        {
            *(pelicula+index)=(EMovie*)malloc(sizeof(EMovie));
            if(*(pelicula+index)==NULL)
            {
                break;
                printf("No hay memoria.\n");
                auxArray=(EMovie**)realloc(pelicula,sizeof(EMovie*)*(*cantPunteros-(100+index)));
                if(auxArray!=NULL)
                    pelicula=auxArray;
            }
        }
            if(index==(*totalPeliculas+(100)))
            {
            printf("Exito al ampliar memoria.\n");
            *totalPeliculas=*totalPeliculas+100;
            }
    }
}

int agregarDatos(EMovie** pelicula,int* peliculasCargadas, int* totalPeliculas)
{
    int retorno;
    retorno=cargarTitulo(pelicula,*peliculasCargadas);
    if(retorno)
        retorno=cargarDuracion(pelicula,*peliculasCargadas,"\nIngresar duracion de la pelicula (en minutos):\n","\nValor incorrecto.");
    if(retorno)
        retorno=cargarGenero(pelicula,*peliculasCargadas);
    if(retorno)
        retorno=cargarImagen(pelicula,*peliculasCargadas);
    if(retorno)
        retorno=cargarPuntaje(pelicula,*peliculasCargadas);
    if(retorno)
        retorno=cargarDescripcion(pelicula,*peliculasCargadas);
    return retorno;
}


void borrarPelicula(EMovie** pelicula, int* peliculasCargadas,int* totalPeliculas)
{
    if(*peliculasCargadas==0)
    {
        printf("No hay peliculas.\n");
        getch();
        return;
    }
    char opcion;
    int i;
    int intentos=3;
    int indice;
    do
    {
        printf("\nElegir la pelicula que desea borrar:\n");
        for(i=0; i<*peliculasCargadas; i++)
        {
            printf("\n%d- Pelicula: %s\n",i+1,((pelicula[i]))->titulo);
        }
        indice=getInt("Opcion: ")-1;
        if(indice<(*(peliculasCargadas)) && indice>0)
        {
            system("cls");
            printf("\nSe va a borrar %s.\nPresione la tecla S para continuar:\n",(*(pelicula+indice))->titulo);
            opcion=getChar(" ");

        }
        else
        {
            printf("Opcion incorrecta. Quedan %d intentos. Reintentar? S/N  \n",intentos-1);
            opcion=getChar(" ");
            intentos--;
            continue;
        }
        comprimirArray(pelicula,peliculasCargadas, indice,totalPeliculas);
        crearArchivoBinario(pelicula,peliculasCargadas);
        opcion='n';
    }

        while(intentos>0 && (opcion=='s'|| opcion== 'S'));
        cualquierTeclaContinuar();
}

void modificarDatos(EMovie** pelicula, int* peliculasCargadas,int* totalPeliculas)
{
    if(*peliculasCargadas==0)
    {
        printf("No hay peliculas.\n");
        getch();
        return;
    }
    int i;
    int indice;
    char opcion;
    int intentos=3;
    do
    {

        printf("\nElegir la pelicula a modificar:\n");
        for(i=0; i<*peliculasCargadas; i++)
        {
            printf("\n%d- Pelicula: %s\n",i+1,((pelicula[i]))->titulo);
        }
        indice=getInt("Opcion: ")-1;
        if(indice<(*(peliculasCargadas)))
        {
            system("cls");
            printf("\nSe va a modificar %s.\nPresionar S para continuar:\n",(*(pelicula+indice))->titulo);
            opcion=getChar(" ");
        }
        else
        {
            printf("Opcion incorrecta. Quedan %d intentos. Reintentar? S/N  \n",intentos-1);
            opcion=getChar(" ");
            intentos--;
            continue;
        }

        if(opcion=='s'|| opcion == 'S')
        {
            system("cls");
            opcion=getChar("Ingresar la opcion a modificar: \n\n1-Titulo. \n2-Genero. \n3-Duracion. \n4-Descripcion \n5-Puntaje \n6-Imagen\n");
            switch(opcion)
            {
            case '1':
                if(cargarTitulo(pelicula,indice))
                    printf("\nExito al modificar.");
                break;
            case '2':
                if(cargarGenero(pelicula,indice))
                    printf("\nExito al modificar.");
                break;
            case '3':
                if(cargarDuracion(pelicula,indice,"\nIngresar duracion de la pelicula (en minutos):\n","\nValor incorrecto."))
                    printf("\nExito al modificar.");
                break;
            case '4':
                if(cargarDescripcion(pelicula,indice))
                    printf("\nExito al modificar.");
                break;
            case '5':
                cargarPuntaje(pelicula,indice);
                break;
            case '6':
                if(cargarImagen(pelicula,indice))
                    printf("\nExito al modificar.");
                break;
            default :
                printf("Error: opcion incorrecta.");
                break;
            }
            for(i=0; i<=indice; i++)
                editarPeliculaFile(pelicula,0);

        }
    }
    while(intentos>0 && (opcion =='s'&& opcion =='S'));
}


void comprimirArray(EMovie** pelicula,int* peliculasCargadas, int indicePeliculaEliminada,int* totalPeliculas)
{
    int i;
    EMovie* auxLista;

    auxLista=(*(pelicula+indicePeliculaEliminada));
    (*(pelicula+indicePeliculaEliminada))=(*(pelicula+(*peliculasCargadas-1)));
    (*(pelicula+(*peliculasCargadas-1)))=auxLista;
    (*peliculasCargadas)--;

    i=((*totalPeliculas)-1);
    while(((*totalPeliculas)-((*peliculasCargadas)))>10)
    {
        free(*(pelicula+i));
        (*totalPeliculas)--;
    }
}


void reservarEspacio(EMovie** pelicula,int totalPeliculas)
{
    int i;
    for(i=0; i<totalPeliculas; i++)
    {
        (*(pelicula+i))=(EMovie*)malloc(sizeof(EMovie));
    }
}

void mostrarPelicula(EMovie** pelicula,int peliculasCargadas)
{
    FILE* pFile;
    char nombre[50];
    char opcion;
    int contador=3;
    int index;

    char Imagen[]="\n<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='";
    char Titulo[]="\'nalt=''>\n </a>\n <h3>\n <a href='#'>";
    char Genero[]="</a>\n </h3>\n<ul>\n<li>Género: ";
    char Puntaje[]="</li>\n<li>Puntaje: ";
    char Duracion[]="</li>\n<li>Duración: ";
    char Descripcion[]="</li>\n</ul>\n <p>";
    char Fin[]="</p>\n</article>";

    strcpy(nombre,"index.html");
    pFile=fopen(nombre,"rb");

    if(pFile!=NULL)
    {
        do
        {
            if(contador>0)
            {
                contador--;
                opcion=getChar("\nYa existe el archivo. Elegir una opcion:\n1-Cambiar nombre\n2-Sobreescribir\n3-Salir");
            }
            else
                opcion='3';
            switch(opcion)
            {
            case '1':
                getTexto("\nElegir un nombre distinto de index: ",nombre,"44");
                agregarHTML(nombre,".html");
                pFile=fopen(nombre,"rb");
                break;
            case '2':
                pFile=NULL;
                printf("\nEl archivo se sobreescribira.");
                getch();
                break;
            case '3':
                return;
            default:
                printf("\nOpcion incorrecta");
                break;
            }
        }
        while(pFile!=NULL);
    }
        pFile=fopen(nombre,"wb");
        if(pFile==NULL)
        {
            printf("Error al guardar.\n");
            getch();
        }
        else
        {
            for(index=0; index<peliculasCargadas; index++)
            {
                fwrite(Imagen,sizeof(char),strlen(Imagen),pFile);
                fwrite(((*(pelicula+index))->linkImagen),sizeof(char),strlen(((*(pelicula+index))->linkImagen)),pFile);

                fwrite(Titulo,sizeof(char),strlen(Titulo),pFile);
                fwrite(((*(pelicula+index))->titulo),sizeof(char),strlen((*(pelicula+index))->titulo),pFile);

                fwrite(Genero,sizeof(char),strlen(Genero),pFile);
                fwrite(((*(pelicula+index))->genero),sizeof(char),strlen((*(pelicula+index))->genero),pFile);

                fwrite(Puntaje,sizeof(char),strlen(Puntaje),pFile);
                fwrite(((*(pelicula+index))->puntaje),sizeof(char),strlen((*(pelicula+index))->puntaje),pFile);

                fwrite(Duracion,sizeof(char),strlen(Duracion),pFile);
                fwrite(((*(pelicula+index))->duracion),sizeof(char),strlen((*(pelicula+index))->duracion),pFile);

                fwrite(Descripcion,sizeof(char),strlen(Descripcion),pFile);
                fwrite(((*(pelicula+index))->descripcion),sizeof(char),strlen((*(pelicula+index))->descripcion),pFile);

                fwrite(Fin,sizeof(char),strlen(Fin),pFile);
        }
        fclose(pFile);
        printf("\nDatos guardados.\n");
        cualquierTeclaContinuar();
    }
}


void crearArchivoBinario(EMovie** pelicula, int* peliculasCargadas)
{
    int i;
    FILE* pFileBinario=NULL;
    pFileBinario=fopen("pelicula.txt","wb");
    for(i=0; i<*peliculasCargadas; i++)
    {
        fwrite(*(pelicula+i),sizeof(EMovie),1,pFileBinario);
    }
    fclose(pFileBinario);
    pFileBinario=fopen("pelicula.txt","wb");
    for(i=0; i<*peliculasCargadas; i++)
    {
        fwrite(*(pelicula+i),sizeof(EMovie),1,pFileBinario);
    }
    fclose(pFileBinario);
}


void agregarPeliculaBinario(EMovie** pelicula,int* peliculasCargadas)
{
    FILE* pFileBin=NULL;
    pFileBin=fopen("pelicula.txt","rb");
    if(pFileBin==NULL)
        crearArchivoBinario(pelicula,peliculasCargadas);
    else
    {
        pFileBin=fopen("pelicula.txt","ab");
        if(pFileBin==NULL)
            printf("\nError.");
        else
        {
            fwrite(*(pelicula+*peliculasCargadas),sizeof(EMovie),1,pFileBin);
            printf("%s",((*(pelicula+*peliculasCargadas))->titulo));
            getch();
            fclose(pFileBin);
        }
    }
}


void editarPeliculaFile(EMovie** pelicula,int indice)
{
    FILE* pFileBinario=NULL;
    pFileBinario=fopen("pelicula.txt","r+b");
    if(pFileBinario==NULL)
        printf("Error: no se pudo abrir el archivo.");
    else
    {
        pFileBinario=fopen("pelicula.txt","ab");
        if(pFileBinario==NULL)
        {
            printf("\nError.");
            getch();
        }
        else
        {
            fseek(pFileBinario,sizeof(EMovie)*indice,SEEK_SET);
            fwrite(((*(pelicula+indice))),sizeof(EMovie),1,pFileBinario);
            fclose(pFileBinario);
        }
    }
}
