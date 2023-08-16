#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

void inicArray(int ** array,int dim);
void loadArray(int ** array,int dim);
void showArray(int * array, int dim);

int main()
{
    printf("Hello world!\n");


    int * arr = NULL;

    inicArray(&arr,10);

    loadArray(&arr,10);

    showArray(arr,10);

    free(arr);




    return 0;
}


/**
1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.

**/

void inicArray(int ** array,int dim)
{
    (*array) =(int *) malloc(dim*(sizeof(int)));

    if(array)
    {

        for(int i = 0; i<dim; i++)
        {
            (*array)[i] = -1;
        }
    }

}

void loadArray(int ** array,int dim)
{

    int i = 0;
    char option = 's';


    if(*array)
    {
        while(i<dim && option == 's')
        {
            if((*array)[i] > -1)
            {
                i++;
            }
            else
            {
                printf("\nIngrese un valor positivo válido: ");
                scanf("%d", &((*array)[i]));
                i++;
                printf("\nDesea seguir cargando?. Para continuar presione 's' ");
                option = getch();

            }
        }
    }

}
void showArray(int * array, int dim)
{
    int i = 0;
    while(i<dim)
    {
        printf("%d | ", array[i]);
        i++;
    }

}
