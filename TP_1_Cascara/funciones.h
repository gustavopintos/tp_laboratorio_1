#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * \brief Calcula la suma de dos numeros.
 * \param x float Primer valor de tipo flotante.
 * \param y float Segundo valor de tipo flotante.
 * \return Retorna la suma de ambos numeros.
 *
 */
float suma(float x,float y)
{
    return(x+y);
}


/**
 * \brief  Calcula la resta entre dos numeros.
 * \param x float Primer valor de tipo flotante.
 * \param y float Segundo valor de tipo flotante.
 * \return Retorna el resultado de la resta.
 *
 */
float resta(float x,float y)
{
    return(x-y);
}

/**
 * \brief Calcula la division entre dos numeros.
 * \param x float Primer valor de tipo flotante.
 * \param y float Segundo valor de tipo flotante.
 * \return Retorna el resultado de la division.
 *
 */
float division(float x,float y)
{   if(y==0){
    printf("Error: no se puede dividir por cero");
    return 0;}
    else{
    return (x/y);
    }
    }

/**
 * \brief Calcula la multiplicacion entre dos numeros.
 * \param x float Primer valor de tipo flotante.
 * \param y float Segundo valor de tipo flotante.
 * \return Retorna el resultado de la multiplicacion.
 *
 */
float multiplicacion(float x,float y)
{
    return(x*y);
}

/**
 * \brief Calcula el factorial de un numero.
 * \param x float Valor de tipo flotante sobre el que se va a calcular el factorial.
 * \return Retorna el factorial del numero.
 *
 */
int i;
long double factorial(float x)
{
    long double factorial=1;
    for(i=0; i<x-1; i++)
    factorial=factorial*(x-i);
    return factorial;
}
#endif // FUNCIONES_H_INCLUDED
