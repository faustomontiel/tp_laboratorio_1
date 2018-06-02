#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20


int main()
{   EPersona personas[TAM];
    inicializarPersona(personas,TAM);

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(personas,TAM);
                system("pause");
                break;
            case 2:
                eliminarPersona(personas, TAM);
                system("pause");
                break;
            case 3:
                listaOrdenada(personas, TAM);
                system("pause");
                break;
            case 4:
                ContadorDePersonas(personas,TAM);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
