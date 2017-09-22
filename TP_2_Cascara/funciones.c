#include <stdio.h>
#include "funciones.h"

void agregarPersona(EPersona lista[],int TAM)
{    int auxDNI;
     int i;
     for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==0)
        {
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);
            printf("Ingrese la edad: ");
            scanf("%d",&lista[i].edad);
            printf("Ingrese el DNI (sin puntos): ");
            scanf("%d", &lista[i].dni);

            if(lista[i].estado=1)
            {
            printf("\nLos datos de la persona se han cargado correctamente.\n");
            }

            break;
        }
    }
}


void mostrarUnaPersona(EPersona persona)
{
    printf("Nombre: %s -- Edad: %d -- DNI: %d\n", persona.nombre, persona.edad, persona.dni);
}


void mostrarPersonas(EPersona lista[], int TAM)
{
    int i;
    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarUnaPersona(lista[i]);
        }

    }
}


void listaOrdenada(EPersona lista[], int TAM)
{
    int i;
    int flag=1;
    EPersona auxPersona;

    while(flag)
    {
        flag=0;
        for(i=0; i<TAM-1 ; i++)
        {
            if(stricmp(lista[i].nombre, lista[i+1].nombre)>0 && lista[i].estado==1)
            {
                auxPersona = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = auxPersona;

                flag=1;
            }
        }
    }
}


void borrarPersona(EPersona lista[], int TAM)
{
    int auxInt;
    int i;
    int flag=0;
    char rta;

    printf("Ingrese el DNI de la persona: ");
    scanf("%d", &auxInt);

    for(i=0; i<TAM; i++)
    {
        if(auxInt==lista[i].dni)
        {
            flag=1;
            mostrarUnaPersona(lista[i]);

            printf("\nDesea borrar a esta persona? s/n ");
            rta= getche();
            if(rta=='s')
            {
                lista[i].estado=0;
                printf("\nLa persona ha sido borrada.\n");
            }
            else
            {
                printf("\nAccion cancelada.\n");

            }
            break;
        }
    }
    if(flag==0)
    {
        printf("ERROR: No existe el DNI.\n");
    }
}


void graficoEdades(EPersona lista[], int TAM)
{
    int i;
    int MenoresA18=0;
    int Entre19y35=0;
    int MayoresA35=0;
    int GrupoMasGrande;

    char grupoMenorA18=' ';
    char grupo19a35=' ';
    char grupoMayorA35=' ';

    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==1)
        {
        if(lista[i].edad<=18)
            {
            MenoresA18++;
            }
            else if(lista[i].edad>35)
              {
                MayoresA35++;
              }
            else
              {
                Entre19y35++;
              }
        }
    }

    if(MenoresA18 >= Entre19y35 && MenoresA18 >= MayoresA35)
        {
        GrupoMasGrande=MenoresA18;
        }
    else if(Entre19y35 >= MenoresA18 && Entre19y35 >= MayoresA35)
        {
        GrupoMasGrande=Entre19y35;
        }
    else
        {
        GrupoMasGrande=MayoresA35;
        }
        printf("\n\n");

    for(i=GrupoMasGrande; i>0; i--)
    {
        if(i<=MenoresA18)
            {
            grupoMenorA18='*';
            }
        if(i<=Entre19y35)
            {
            grupo19a35='*';
            }
        if(i<=MayoresA35)
            {
            grupoMayorA35='*';
            }
            printf("    %c     %c     %c \n",grupoMenorA18,grupo19a35,grupoMayorA35);
    }
            printf("\n   <18  19-35  >35\n");
    }

