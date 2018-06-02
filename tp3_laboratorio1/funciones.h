

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}EMovie;

char menu(void);
/** \brief permite el ingreso de datos de una pelicula y los guarda en el array.
 *
 * \param recibe un vector de valor pelicula y el tamaño del array a ser guardado.
 */
int alta(EMovie*,int);
/** \brief modifica a la persona del array.
 *
 * \param se ingresa un vector perteneciente a emovie y el tamaño del array.
 */

void modificar(EMovie*);
/** \brief elimina a la pelicula del array.
 *
 * \param se ingresa un vector perteneciente a emovie y el tamaño del array.
 */
void baja(EMovie*);
/**
 * Obtiene el indice que este vacio.
 * @param lista el array se pasa como parametro.
 * @return el indice en donde se encuentra vacio.
 */
int buscarLibre(EMovie*);
/**
 * genera un archivo con los datos ingresados.
 * @param puntero se pasa como parametro.
 * @return un valor de acuerdo si se guardo.
 */
int guardarEnArchivo(EMovie *);
/**
 * lee un archivo con los datos ingresados.
 * @param puntero se pasa como parametro.
 * @return un valor de acuerdo si se puede leer o no.
 */
int cargarDesdeArchivo(EMovie *);
