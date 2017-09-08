#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0, num2=0, respuesta;

        inicio:
        printf("\n1- Ingresar 1er operando (A=%.2f)\n",num1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresar 1er numero: ");
                scanf("%f",&num1);
                goto inicio;
                break;
            case 2:
                printf("\nIngresar 2do numero: ");
                scanf("%f",&num2);
                goto inicio;
                break;
            case 3:
                respuesta=suma(num1,num2);
                printf("\nLa suma de los numeros es: %.2f \n", respuesta);
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 4:
                respuesta=resta(num1,num2);
                printf("\nLa resta de los numeros es: %.2f \n", respuesta);
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 5:
                if(num2==0){printf("\nERROR: No se puede dividir por cero. \n");}
                else{
                respuesta=division(num1,num2);
                printf("\nLa division es: %.2f \n", respuesta);}
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 6:
                respuesta=multiplicacion(num1,num2);
                printf("\nLa multiplicacion de los numeros es: %.2f \n", respuesta);
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 7:
                respuesta=factorial(num1);
                printf("\nEl factorial del 1er numero es: %.0f \n", respuesta);
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 8:
                respuesta=suma(num1,num2);
                printf("\nLa suma de los numeros es: %.2f \n", respuesta);
                respuesta=resta(num1,num2);
                printf("La resta de los numeros es: %.2f \n", respuesta);
                if(num2==0){printf("ERROR: No se puede dividir por cero. \n");}
                else{
                respuesta=division(num1,num2);
                printf("La division es: %.2f \n", respuesta);}
                respuesta=multiplicacion(num1,num2);
                printf("La multiplicacion de los numeros es: %.2f \n", respuesta);
                respuesta=factorial(num1);
                printf("El factorial del 1er numero es: %.0f \n", respuesta);
                printf("\nDesea continuar? s/n \n");
                scanf("%s", &seguir);
                while(seguir == 's'){
                goto inicio;
                }
                break;
            case 9:
                (seguir == 'n');
                break;
            default:
                printf("\nERROR: Elija una opcion del 1 al 9 \n");
                break;

        }


    return 0;
}



