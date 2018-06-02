#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicializarPersona(EPersona personas[],int tam){

    for(int i=0;i<tam;i++){
        personas[i].estado=0;
    }
}
int obtenerEspacioLibre(EPersona personas[], int tam)
{
    int indice = -1;
    for (int i=0; i<tam; i++){
        if (personas[i].estado==0){
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPersona(EPersona persona)
{
   printf("\nNombre: %s Edad:%d DNI:%d\n\n",persona.nombre,persona.edad,persona.dni);

}
int buscarPorDni(EPersona persona[],int tam, int dni)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(persona[i].estado == 1 && persona[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void agregarPersona(EPersona persona[],int tam){

    int esta;
    int indice;
    int dni;
    EPersona nuevaPersona;

    system("cls");

    printf("---Agregar Persona---\n\n");

    indice = obtenerEspacioLibre(persona, tam);


    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede agregar mas personas.\n\n");
    }
    else
    {
        printf("Ingrese DNI: ");
        scanf("%d", &dni);

        esta = buscarPorDni(persona, tam, dni);

        if(esta != -1)
        {
            printf("\nEl dni %d corresponde a otra persona en el sistema: \n", dni);
            mostrarPersona(persona[esta]);
        }
        else
        {
            nuevaPersona.estado = 1;
            nuevaPersona.dni = dni;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &nuevaPersona.edad);



            persona[indice] = nuevaPersona;

            printf("\nLa persona ha sido agregada con exito!!\n\n");

        }
    }

}
void eliminarPersona(EPersona persona[], int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("****Eliminar persona****\n\n");

    printf("Ingrese dni: ");
    scanf("%d", &dni);

    esta = buscarPorDni(persona, tam, dni);

    if(esta == -1)
    {
        printf("\nLa persona con el DNI %d no se encuentra en el sistema\n\n", dni);

    }
    else
    {

        mostrarPersona(persona[esta]);

        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            persona[esta].estado = 0;
            printf("\nSe ha realizado la eliminacion\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la eliminacion\n\n");
        }

    }
}
void listaOrdenada(EPersona persona[], int tam){
    EPersona auxPer;

    for(int i=0; i< tam-1; i++){
        for(int j=i +1; j< tam; j++){
        if(strcmp(persona[i].nombre, persona[j].nombre)>0){
                auxPer = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPer;
                }
            }
        }
        mostrarPersonas(persona,tam);
}
void mostrarPersonas(EPersona persona[], int tam)
{
    system("cls");
    printf("*****Lista de Personas****\n\n");
    printf("  NOMBRE  EDAD   DNI \n");
    for(int i=0; i< tam; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("%2s   %2d  %2d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }
}
void ContadorDePersonas(EPersona persona[],int tam)
{
    int contadorMenor19=0;
    int contador19_35=0;
    int contadorMayor35=0;
    int i;

    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==1)
        {
            if(persona[i].edad<19)
            {
                contadorMenor19++;
            }
            else
            {
                if(persona[i].edad>=19 && persona[i].edad<=35)
                {
                    contador19_35++;
                }
                else
                {
                    contadorMayor35++;
                }
            }
        }
    }
    graficoDePersonas(contadorMenor19,contador19_35,contadorMayor35);
}
void graficoDePersonas(int menora19,int entre19_35,int mayor35)
{
   int edades[3]={menora19,entre19_35,mayor35};
   int i;
   int j;
   int maximo=0;

   for(i=0;i<3;i++)
   {
        if(edades[i]>maximo)
        {
            maximo=edades[i];
        }
   }


    for(i=maximo;i>0;i--)
    {
          for(j=0;j<3;j++)
          {
                if(edades[j]>=i)
                {
                    printf("\t%c",158);
                }

                else
                {
                    printf("\t ");
                }
          }
          printf("\n");
   }
    printf("\t<18\t19-35\t>35\n");
}


