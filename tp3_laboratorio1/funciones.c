#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"

#define A 5

char menu()
{       char c;
	system("cls");
        printf("---PELICULAS---\n\n");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir y Guardar\n");
	printf("Elija una opcion <1-5>: ");
	c=getche();
	return c;
}


int buscarLibre(EMovie peliculas[])
{
	int index=-1;
	int i;
	for( i=0; i < A; i++)
	   if(peliculas[i].estado==0){
		index=i;
		break;
	   }
	return index;
}

void alta(EMovie peliculas[])
{
	int index, i;
    char duracion[5];
    char puntaje[5];
	char titulo[50];
	int esNumero;
	int encontro=0;
	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(peliculas);
	if(index!=-1)//si hay lugar:
	{

		printf("INGRESO DE DATOS:\n");
		printf("Ingrese titulo: ");
		gets(titulo);
		 esNumero = validarString(titulo);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(titulo);
            esNumero = validarString(titulo);

        }
		/*Buscamos si el legajo ya existe*/
		for(i=0; i<A; i++)
		{
			if(strcmp(peliculas[i].titulo,titulo)==0)
			{
				encontro=1;//encontro en true
				break;
			}
		}
		if(!encontro)//entra si encontro==0
		{
        strcpy(peliculas[index].titulo,titulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets(peliculas[index].genero);
        esNumero = validarString(peliculas[index].genero);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(peliculas[index].genero);
            esNumero = validarString(peliculas[index].genero);

        }



        printf("Ingrese duracion (minutos): ");
        gets(duracion);
        esNumero = validarNumero(duracion);

        while (esNumero == 1)
        {
            printf("Error. numero incorrecta, reingrese la numero: ");
            fflush(stdin);
            gets(duracion);
            esNumero = validarNumero(duracion);
        }

        peliculas[i].duracion = atoi(duracion);

        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(peliculas[index].descripcion);

        esNumero = validarString(peliculas[index].descripcion);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(peliculas[index].descripcion);
            esNumero = validarString(peliculas[index].descripcion);

        }



        printf("Ingrese puntaje: ");
        gets(puntaje);
         esNumero = validarNumero(puntaje);

        while (esNumero == 1)
        {
            printf("Error. numero incorrecta, reingrese la numero: ");
            fflush(stdin);
            gets(puntaje);
            esNumero = validarNumero(puntaje);
        }

        peliculas[i].puntaje = atoi(puntaje);




        printf("ingrese el Link a la imagen: ");
        fflush(stdin);
        gets(peliculas[index].linkImagen);

        peliculas[index].estado=1;
			system("cls");
		}
		else
		{
			printf("­­La pelicula ingresada ya existe!!");
			getch();
		}
	}
	else
	{
		printf("No queda espacio");
		getch();
	}
}

void toString(EMovie* unaPeli)
{
	printf("%d\t\t%s\t\t%s\n", unaPeli->puntaje, unaPeli->titulo, unaPeli->genero);
}

void listar(EMovie* peliculas)
{
	int i,j;


	printf("Puntaje\tTitulo\tGenero\n");
	for(i=0; i<A; i++)
	{
		if(peliculas[i].estado==1)
		   toString((peliculas + i));

	}
	getch();
}
void baja(EMovie* peliculas)
{
	int  flag=0,i;
	char opcion;
	char titulo[50];
    int esNumero;


	for(i=0; i<A; i++)
	{


		if(peliculas[i].estado==1){
                printf("\nPELICULAS A ELIMINAR. PRESIONE UNA TECLA PARA ELEGIR UNA\n\n");
        listar(peliculas+i);



    printf("Ingrese titulo a dar de baja: ");
	   gets(titulo);
	   esNumero = validarString(titulo);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(titulo);
            esNumero = validarString(titulo);

        }
		if(strcmp((peliculas+i)->titulo,titulo)==0)
		{
			printf("Datos a eliminar:\n");

			toString((peliculas + i));

			printf("\nLegajo encontrado. ¨Seguro desea dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				peliculas[i].estado=0;
				printf("­­Pelicula eliminada!!");
				system("pause");
			}
			else
			{
				printf("El registro no fue eliminado!");
			}
			flag=1;
			break;
		}
		}else{
	    printf("\n\nNO SE HAN INGRESADO PELICULAS\n");
	    break;
	}
	}
	if(flag==0)
	{
		printf("\nPelicula inexistente");
		getch();
	}
}
void modificar(EMovie* peliculas)
{
    char tituloModificar[51];
    char opcion;
    char titulo[51];
    char genero[41];
    char duracion[5];
    char descripcion[2000];
    char puntaje[5];
    char imagen[500];
    int estado;
    int i;
    int flag=0;
    int esNumero;
	system("cls");

	for( i=0; i<A; i++)
	{

	if(peliculas[i].estado==1){
            printf("\nPELICULAS A MODIFICAR. PRESIONE UNA TECLA PARA ELEGIR UNA\n\n");
        listar(peliculas+i);
	}else{
	    printf("\n\nNO SE HAN INGRESADO PELICULAS\n");
	    break;
	}

	    printf("Ingrese titulo a modificar: ");
	gets(titulo);
	esNumero = validarString(titulo);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(titulo);
            esNumero = validarString(titulo);

        }
		if(strcmp((peliculas+i)->titulo,titulo)==0)
		{
			printf("Datos encontrados:\n");

			toString((peliculas + i));

			printf("Ingrese nuevo titulo: ");
            fflush(stdin);
            gets(titulo);
            esNumero = validarString(titulo);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(titulo);
            esNumero = validarString(titulo);

        }
            printf("Ingrese nuevo genero: ");
        fflush(stdin);
        gets(peliculas[i].genero);
        esNumero = validarString(peliculas[i].genero);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(peliculas[i].genero);
            esNumero = validarString(peliculas[i].genero);

        }



        printf("Ingrese nueva duracion (minutos): ");
        gets(duracion);
        esNumero = validarNumero(duracion);

        while (esNumero == 1)
        {
            printf("Error. numero incorrecta, reingrese la numero: ");
            fflush(stdin);
            gets(duracion);
            esNumero = validarNumero(duracion);
        }

        peliculas[i].duracion = atoi(duracion);

        printf("Ingrese nueva descripcion: ");
        fflush(stdin);
        gets(peliculas[i].descripcion);

        esNumero = validarString(peliculas[i].descripcion);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(peliculas[i].descripcion);
            esNumero = validarString(peliculas[i].descripcion);

        }



        printf("Ingrese nuevo puntaje: ");
        gets(puntaje);
         esNumero = validarNumero(puntaje);

        while (esNumero == 1)
        {
            printf("Error. numero incorrecta, reingrese el numero: ");
            fflush(stdin);
            gets(puntaje);
            esNumero = validarNumero(puntaje);
        }

        peliculas[i].puntaje = atoi(puntaje);




        printf("ingrese nuevo el Link a la imagen: ");
        fflush(stdin);
        gets(peliculas[i].linkImagen);


			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{

               // peliculas->estado=estado;

				printf("Pelicula modificada");
				system("pause");
			}
			else
			{
				printf("La pelicula no fue modificada");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nPelicula inexistente");
		getch();
	}
}

int guardarEnArchivo(EMovie * x)
{

	FILE *f;

		f=fopen("pelis.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),A,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(EMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("pelis.dat", "rb");
	if(f==NULL)
	{
		f= fopen("pelis.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(x,sizeof(EMovie),A,f);
    }

	fclose(f);
	return 0;

}
void crearPagina(EMovie* peliculas,int tam,char nombre[])

{
     int i;
     FILE *H;
     strcat(nombre,".html");
     H=fopen(nombre, "w");

     if(H == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         for(i=0; i<tam; i++)
         {
             if((peliculas+i)->estado==1){
             fprintf(H,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");
             fprintf(H,"<img class='img-responsive img-rounded' src='");
             if((peliculas+i)->duracion>0)
             {
                 fprintf(H,"%s'\n\nalt=''>\n </a>\n <h3>\n <a href='#'>", (peliculas+i)->linkImagen);
                 fprintf(H,"%s</a>\n </h3>\n<ul>\n<li>", (peliculas+i)->titulo);
                 fprintf(H,"Genero: %s</li>\n<li>", (peliculas+i)->genero);
                 fprintf(H,"Puntaje: %d</li>\n<li>", (peliculas+i)->puntaje);
                 fprintf(H,"Duracion: %d</li>\n</ul>\n <p>", (peliculas+i)->duracion);
                 fprintf(H,"%s</p>\n</article>\n", (peliculas+i)->descripcion);
             }

         }
         }
      }

      fclose(H);

      printf("Archivo HTML creado con exito.\n");
      system("pause");
}
int validarString (char cadena[])
{
    int esNumero = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (isalpha(cadena[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

int validarNumero (char numero[])
{
    int esNumero = 0;
    int len;

    len = strlen(numero);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(numero[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}
