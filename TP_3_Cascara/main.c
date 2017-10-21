#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>



int main()
{   FILE* pFile=NULL;
    int cantPunteros=100;
    EMovie** pelicula=(EMovie**)malloc(sizeof(EMovie*)*cantPunteros);
    int peliculasCargadas=0;
    int totalPeliculas=100;
    reservarEspacio(pelicula,totalPeliculas);
    system("cls");


    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(pelicula,&peliculasCargadas,&totalPeliculas,&cantPunteros);
                break;
            case 2:
                borrarPelicula(pelicula,&peliculasCargadas,&totalPeliculas);
                break;
            case 3:
                modificarDatos(pelicula,&peliculasCargadas,&totalPeliculas);
               break;
            case 4:
                mostrarPelicula(pelicula,peliculasCargadas);
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
