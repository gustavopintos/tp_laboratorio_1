#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Peliculas.h"

int getInt(char* mensaje)
{
    int entero;
    printf("%s",mensaje);
    scanf(" %d",&entero);
    return entero;
}

char getChar(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);
    return caracter;
}

void getText(char* mensaje,char* arrayChar,int cantCaracteres)
{
    if(cantCaracteres==21)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%21[^\n]",arrayChar);
    }
    else if(cantCaracteres==51)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%51[^\n]",arrayChar);
    }
    else if(cantCaracteres==101)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%101[^\n]",arrayChar);
    }
    else if(cantCaracteres==201)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%101[^\n]",arrayChar);
    }

}

void getTexto(char* mensaje,char* arrayChar,char* cantCaracteres)
{
    int i;
    char mascara[10]="%";
    strcpy((mascara+1),cantCaracteres);
    i=1+strlen(cantCaracteres);
    strcpy((mascara+i),"[^\n]");
    fflush(stdin);
    printf("%s",mensaje);
    scanf(mascara,arrayChar);
}


int getNumerosChar (char array[],char mensaje[])
{
    fflush(stdin);
    int retorno=0;
    getString(mensaje,array);
    if(esNumeroChar(array))
    {
        retorno = 1;
    }
    return retorno;
}


int esNumeroChar (char num[])
{
    int i=0;
    while(num[i]!='\0')
    {
        if(num[i] < '0' || num[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void cualquierTeclaContinuar(void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}


void getString(char mensaje[],char arrayChar[])
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%s",arrayChar);
}





int cargarDescripcion(EMovie** pelicula, int index)
{
    char auxDescripcion[100];
    int cantCaracteres;
    int retorno=0;
    char seguir='n';

    do
    {
        getText("\nIngresar la descripcion (50 caracteres):\n",auxDescripcion,51);
        if((cantCaracteres=strlen(auxDescripcion))<51)
        {
            strcpy(((*(pelicula+index))->descripcion),auxDescripcion);
            retorno=1;
        }
        else
        {
            seguir=getChar("Error: Ingresar una descripcion inferior a 50  caracteres.\nDesea reintentar? s/n:\n");
        }
    }
    while(seguir=='s' && retorno ==0);
    return retorno;

}


int cargarGenero(EMovie** pelicula,int index)
{
    char auxGenero[52];
    int cantCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngresar el genero (20 caracteres):\n",auxGenero,51);
        if((cantCaracteres=strlen(auxGenero))<51)
        {
            strcpy(((*(pelicula+index))->genero),auxGenero);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nReintentar? s/n:\n");
        }

    }

    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));
    return retorno;
}


int cargarDuracion (EMovie** pelicula,int index, char pedirDato[],char error[])
{
    char seguir='s';
    int retorno=0;
    char aux[20];
    do
    {

        retorno=getNumerosChar(aux,pedirDato);
        if(retorno==0 || (atoi(aux)<1) || (atoi(aux)>500 ))
        {
            printf(error);
            retorno=0;
            seguir=getChar("Reintentar? s/n");
        }
        else
        {
            retorno = 1;
            strcpy((*(pelicula+index))->duracion,(aux));
        }
    }

    while(retorno!=1 && seguir == 's');
    return retorno;
}


int cargarImagen(EMovie** pelicula,int index)
{
    char auxLink[102];
    int cantCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngresar link:\n",auxLink,101);
        if((cantCaracteres=strlen(auxLink))<101)
        {

            strcpy(((*(pelicula+index))->linkImagen),auxLink);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nReintentar? s/n:\n");
        }

    }

    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));
    return retorno;
}


int cargarPuntaje (EMovie** pelicula,int index)
{
    char seguir='s';
    int retorno=0;
    char aux[20];
    do
    {

        retorno=getNumerosChar(aux,"\nIngresar puntaje de la pelicula(0 a 10):\n");
        if(retorno==0 || (atoi(aux)<0) || (atoi(aux)>10 ))
        {
            printf("Valor incorrecto.");
            retorno=0;
            seguir=getChar("Desea reintentar? s/n");
        }
        else
        {
            retorno = 1;
            strcpy((*(pelicula+index))->puntaje,(aux));
        }
    }

    while(retorno!=1 && seguir == 's');
    return retorno;
}


int cargarTitulo(EMovie** pelicula,int index)
{
    char auxTitulo[22];
    int cantCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngrese el titulo (20 caracteres):\n",auxTitulo,21);
        if((cantCaracteres=strlen(auxTitulo))<21)
        {
            strcpy(((*(pelicula+index))->titulo),auxTitulo);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nReintentar? s/n:\n");
        }

    }

    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));
    return retorno;
}

void agregarHTML(char* array,char* HTML)
{
    int i;
    for(i=0;*(array+i)!='\0'&&*(array+i)!='.';)
    {
        i++;
    }
    strcpy((array+i),".html");
}

