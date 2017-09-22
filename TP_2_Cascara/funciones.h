#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);


/**
 * \brief Pide al usuario que ingrese los datos de una persona (Nombre, edad y DNI).
 * \param EPersona El array se pasa como parametro.
 * \param TAM El tamaño del array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void agregarPersona(EPersona[], int TAM);


/**
 * \brief Muestra la lista de todas las personas con sus datos.
 * \param EPersona El array se pasa como parametro.
 * \param TAM El tamaño del array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void mostrarPersonas(EPersona[], int TAM);


/**
 * \brief Muestra una persona.
 * \param EPersona El array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void mostrarUnaPersona(EPersona);


/**
 * \brief Borra de la lista los datos de una persona.
 * \param EPersona El array se pasa como parametro.
 * \param TAM El tamaño del array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void borrarPersona(EPersona[], int TAM);


/**
 * \brief Muestra la lista de personas con los nombres en orden alfabetico.
 * \param EPersona El array se pasa como parametro.
 * \param TAM El tamaño del array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void listaOrdenada(EPersona[], int TAM);


/**
 * \brief Muestra la lista de personas cargadas en forma grafica (Menores a 18(inclusive), de 19 a 35 y mayores a 35).
 * \param EPersona El array se pasa como parametro.
 * \param TAM El tamaño del array se pasa como parametro.
 * \return No retorna ningun valor.
 */
void graficoEdades(EPersona[], int TAM);

#endif // FUNCIONES_H_INCLUDED
