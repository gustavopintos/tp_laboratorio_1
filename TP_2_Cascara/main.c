#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{   EPersona listaPersonas[TAM];
    char seguir='s';
    int opcion=0;
    int i;
    for(i=0; i<TAM; i++)
    {
        listaPersonas[i].estado=0;
    }


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                agregarPersona(listaPersonas, TAM);
                break;
            case 2:
                borrarPersona(listaPersonas, TAM);
                break;
            case 3:
                listaOrdenada(listaPersonas, TAM);
                mostrarPersonas(listaPersonas, TAM);
                break;
            case 4:
                graficoEdades(listaPersonas, TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\n ERROR: Ingrese una opcion del 1 al 5.");
        }
    }

    return 0;
}
