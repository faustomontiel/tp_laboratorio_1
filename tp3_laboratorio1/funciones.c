#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"

#define TAM 5

char menu()
{       char c;
	system("cls");
        printf("---PELICULAS---\n\n");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir y Guardar\n");
	printf("Elija una opcion: ");
	c=getche();
	return c;
}

int buscarLibre(EMovie* peliculas)
{
	int index=-1;
	int i;
	for( i=0; i < TAM; i++)
	   if((peliculas+i)->estado==0){
		index=i;
		break;
	   }
	return index;
}

int alta(EMovie* peliculas,int tam)
{
    int returnAUX=0;
	int lugar=0;
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
    int i;
    int esta;

	lugar=buscarLibre(peliculas);
	if(lugar!=-1)
	{

		printf("Ingrese titulo: ");
		fflush(stdin);
        gets(titulo);

		for(i=0; i<tam; i++)
		{
			if(strcmp((peliculas+i)->titulo,titulo)==0)
			{
				lugar=1;
				break;
			}
		}
		if(!lugar)
		{
        strcpy(peliculas->titulo,titulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets(genero);
        printf("Ingrese duracion (minutos): ");
        scanf("%d",&duracion);
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(descripcion);
        printf("Ingrese puntaje: ");
        scanf("%d",&puntaje);
        printf("ingrese el Link a la imagen: ");
        fflush(stdin);
        gets(imagen);
        estado=1;
        returnAUX=1;

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
	return returnAUX;
}

void baja(EMovie* peliculas)
{
	int flag=0,i;
	char titulo[51];
	char opcion;


	for(i=0; i<TAM; i++)
	{

        printf("Ingrese titulo de la Pelicula a borrar: ");
     	fflush(stdin);
        gets(titulo);

		if(strcmp((peliculas+i)->titulo,titulo)==0)
		{
		    printf("Datos a eliminar:\n");

			toString((peliculas + i));

			printf("\nConfirma dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				peliculas[i].estado=0;
				//guardarEnArchivo(peliculas);
				printf("­-Pelicula borrada--");
				system("pause");
			}
			else
			{
				printf("--La pelicula no fue borrada--");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Esa Pelicula no  existe");
		getch();
	}

}
void modificar(EMovie* peliculas)
{

	char tituloModificar[51];
    char opcion;
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
    int i;
    int flag=0;

	system("cls");

	for( i=0; i<TAM; i++)
	{
	    printf("Titulos de peliculas a modificar:\n");

            printf("--%s--\n",(peliculas+i)->titulo);

        printf("Ingrese titulo de la Pelicula a modificar: ");
     	fflush(stdin);
        gets(titulo);

		if(strcmp((peliculas+i)->titulo,titulo)==0)
		{


            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(genero);
            printf("Ingrese duracion (minutos): ");
            scanf("%d",&duracion);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(descripcion);
            printf("Ingrese puntaje: ");
            scanf("%d",&puntaje);
            printf("ingrese el Link a la imagen: ");
            fflush(stdin);
            gets(imagen);

            estado=1;

			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{
				strcpy(peliculas->titulo,titulo);
                strcpy(peliculas->genero,genero);
                peliculas->duracion=duracion;
                strcpy(peliculas->descripcion,descripcion);
                peliculas->puntaje=puntaje;
                strcpy(peliculas->linkImagen,imagen);
                peliculas->estado=estado;

				printf("Registro modificado");
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
		printf("pelicula inexistente inexistente");
		getch();
	}
}


int guardarEnArchivo(EMovie * pel)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(pel,sizeof(EMovie),TAM,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(EMovie *pel)
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(pel,sizeof(EMovie),TAM,f);
    }

	fclose(f);
	return 0;

}
void crearPagina(EMovie* peliculas, int tam)
{
    FILE* archivo;
    int i;

    archivo=fopen("peliculas.html","w");
    if(archivo==NULL)
    {
        printf("La pagina no se va a poder generar.");
    }
    else
    {

        for(i=0;i<tam;i++)
        {

            fprintf(archivo,"<img  src=%s alt=%s style=width:200px;hight:200px>",(peliculas+i)->linkImagen,(peliculas+i)->titulo);
            fprintf(archivo,"<h2><a href=#>%d)%s</a></h2>",i+1,(peliculas+i)->titulo);
            fprintf(archivo,"<h4><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>            <li> DESCRIPCION: %s</li>   </h4>",(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion,(peliculas+i)->descripcion);

        fprintf(archivo,"</html> </body>");
    }
    fclose(archivo);
    printf("La pagina se genero correctamente.\n");
}
}
void toString(EMovie* pelicula)
{
	printf("%s\t\t%s\n",  pelicula->titulo, pelicula->genero);
}

