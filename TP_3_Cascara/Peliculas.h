
void agregarPelicula(EMovie** pelicula,int*  peliculasCargadas,int* totalPeliculas,int* cantPunteros);
void borrarPelicula(EMovie** pelicula, int* peliculasCargadas,int* totalPeliculas);
int agregarDatos(EMovie** pelicula,int* peliculasCargadas, int* totalPeliculas);
void modificarDatos(EMovie** pelicula, int* peliculasCargadas,int* totalPeliculas);
void comprimirArray(EMovie** pelicula,int* peliculasCargadas, int indicePeliculaEliminada,int* totalPeliculas);
void ampliarMemoria(EMovie** pelicula,int  peliculasCargadas,int* totalPeliculas,int* cantPunteros);
void reservarEspacio(EMovie** pelicula,int totalPeliculas);
void mostrarPelicula(EMovie** pelicula,int peliculasCargadas);
void agregarPeliculaBinario(EMovie** pelicula,int* peliculasCargadas);
void crearArchivoBinario(EMovie** movie, int* peliculasCargadas);
