#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"

#define TAM 5


int main()
{
	EMovie peliculas[TAM];
	char seguir='s';
	char guardar= 's';
	int cant=0;
	int i;

		for( i=0; i<TAM; i++)
		peliculas[i].estado=0;

	if(cargarDesdeArchivo(peliculas))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}





	system("cls");
	do
	{
		switch(menu())
		{
			case '1':
				system("cls");
				 if(alta(peliculas,TAM)==1)
            {
                printf("Pelicula cargada con exito!");
                cant++;
            }
            else
            {
                printf("No se pudo cargar la película!");
            }
				break;
			case '2':
				system("cls");
				baja(peliculas);
				break;
			case '3':
				system("cls");
				modificar(peliculas);
				break;
			case '4':
                crearPagina(peliculas,cant);
				system("cls");
				break;
			case '5':

				printf("\nGuardar cambios (S para confirmar) ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(peliculas))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
				break;

		}
	}while(seguir=='s');



	printf("\n");
	system("pause");
}



