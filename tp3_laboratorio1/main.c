#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "Funciones.h"

#define A 10


int main()
{
    EMovie peliculas[A];
	char seguir='s';
	char guardar= 's';
	char nameHTML[50];
	int contMovie=0;
	int i;

		for( i=0; i<A; i++)
		peliculas[i].estado=0;

		if(cargarDesdeArchivo(peliculas))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las Peliculas con exito\n");
	}


	system("cls");
	do
	{

		switch(menu())
		{
			case '1':
				system("cls");
				alta(peliculas);
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
				system("cls");
                printf("Ingrese nombre de archivo a guardar: ");
                scanf("%s",&nameHTML);
                crearPagina(peliculas,A,nameHTML);

				break;
			case '5':
                printf("\nGuardar cambios S/N ?: ");
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




