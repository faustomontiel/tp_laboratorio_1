#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

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
int obtenerEspacioLibre(EPersona [],int );


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona [],int, int );
/** \brief inicializa la pocision de la persona en el array.
 * \param  el vector y el tamaño del array.
 */
void inicializarPersona(EPersona [],int );
/** \brief muestra los datos guardados de la persona.
 * \param  recibe un vector para poder llamar al nombre, a la edad y el dni.
 */
void mostrarPersona(EPersona );
/** \brief permite el ingreso de datos de una persona y los guarda en el array.
 *
 * \param recibe un vector de valor epersona y el tamaño del array a ser guardado.
 */
void agregarPersona(EPersona [],int );
/** \brief elimina a la persona del array.
 *
 * \param se ingresa un vector perteneciente a epersona y el tamaño del array.
 */
void eliminarPersona(EPersona [], int );
/** \brief permite el ordenamiento alfabeticamente de las personas
 *
 * \param un vector epersona y el tamaño del array.
 */

void listaOrdenada(EPersona [], int );
/** \brief muestra las personas ingresadas en una lista con sus respectivos datos
 *
 * \param un vector epersona y el tamaño del array.
 */

void mostrarPersonas(EPersona [], int );
/** \brief cuenta las personas con una edad determinada: menores de 19,entre 19 y 35 y los mayores a 35; y luego
    los muestra en un grafico;
 *
 * \param   un vector epersona y el tamaño del array.
 */

void ContadorDePersonas(EPersona [],int );
/** \brief permite realizar un grafico para ser llamado en la funcion ccontador de personas.
 *
 * \param se ingresan 3 enteros que contienen la cantidad de personas que cumplen con las escalas del grafico
 */

void graficoDePersonas(int ,int ,int );


#endif // FUNCIONES_H_INCLUDED
