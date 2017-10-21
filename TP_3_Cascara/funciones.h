#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    char duracion[5];
    char descripcion[600];
    char puntaje[2];
    char linkImagen[250];
}EMovie;

int getInt(char* mensaje);
char getChar(char mensaje[]);
void getText(char* mensaje,char* arrayChar,int cantCaracteres);
int getNumerosChar (char array[],char mensaje[]);
void getTexto(char* mensaje,char* arrayChar,char* cantCaracteres);
void getString(char mensaje[],char arrayChar[]);
int esNumeroChar (char num[]);
void cualquierTeclaContinuar(void);

int cargarDescripcion(EMovie** pelicula, int index);
int cargarGenero(EMovie** pelicula, int index);
int cargarDuracion (EMovie** pelicula,int index, char pedirDato[], char error[]);
int cargarImagen(EMovie** pelicula, int index);
int cargarPuntaje (EMovie** pelicula, int index);
int cargarTitulo(EMovie** pelicula, int index);
void agregarHTML(char* array,char* HTML);

#endif // FUNCIONES_H_INCLUDED
