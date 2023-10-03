#include <stdio.h>
#include <stdlib.h>
#include "arbolEnteros.h"

int cargarArreglo(int arreglo[], int dim);
void mostrarArreglo(int arreglo[], int validos, int dim);
nodoArbolInt * arregloToArbol(int arreglo[], int validos, nodoArbolInt* arbol);
int nroNoRepetido(int arreglo[], int validos,  int dato);
int arbolToArray (int arreglo[], int validos, int dim, nodoArbolInt * arbol);
int agregoEnArreglo (int arreglo[], int validos, int dim, int dato);

int main()
{
    //srand(time(NULL));
    nodoArbolInt * arbolito = inicArbol();

    int arreglo[10];
    int arreglo2[9];
    int validos;
    validos = cargarArreglo(arreglo,10);
    mostrarArreglo(arreglo,validos,10);

    printf("1.\n");

    arbolito = arregloToArbol(arreglo,validos,arbolito);
    inOrder(arbolito);
    printf("\n --- ARBOL GRAFICO ---\n"),
    dibujarArbol(arbolito,0);


    int cantidad = cantidadHojas(arbolito);

    int cantG1 = cantNodosGradoUno(arbolito);

    printf("\n El valor de cantidad  de hojas es: %d", cantidad);
    printf("\n El valor de cantidad de grado uno es: %d", cantG1);
    printf("\n");

    system("pause");

    printf("\n2.\n");



   /*nodoArbolInt * arbolote = eliminarNodo(arbolito,5);
    inOrder(arbolote);*/

    eliminar2(&arbolito,5);
    inOrder(arbolito);

    printf("\n3.\n");
    validos = arbolToArray(arreglo2,0,9,arbolito);
    mostrarArreglo(arreglo2,validos,9);
    printf("\n El valor de validos es: %d", validos);

    return 0;
}

int cargarArreglo(int arreglo[], int dim)
{
    int i=0;
    int dato = 0;

    for(i=0;i<dim;i++)
    {
        int flag =0;
        while(flag==0)
        {
             dato = (rand()%11);
             flag = nroNoRepetido(arreglo,i,dato);
        }

        arreglo[i] = dato;
    }

    return i;
}

int nroNoRepetido(int arreglo[], int validos,  int dato)
{
    int flag = 1;
    int i = 0;

    while(i<validos && flag == 1)
    {
        if(dato == arreglo[i])
        {
            flag = 0;
        }
        i++;
    }
    return flag;
}



void mostrarArreglo(int arreglo[], int validos, int dim)
{
    int i;
    for(i=0;i < validos;i++)
    {
        printf(" %d |",arreglo[i]);
    }
}

nodoArbolInt * arregloToArbol(int arreglo[], int validos, nodoArbolInt* arbol)
{
    for(int i = 0; i<validos;i++)
    {
        arbol = insertarNodo(arbol,arreglo[i]);
    }

    return arbol;
}

int arbolToArray (int arreglo[], int validos, int dim, nodoArbolInt * arbol)
{
    if(arbol)
    {
        validos = arbolToArray(arreglo,validos,dim,arbol->izq);
        int dato = arbol->dato;
        validos = agregoEnArreglo(arreglo,validos,dim,dato);
        validos = arbolToArray(arreglo,validos,dim,arbol->der);
    }
    return validos;

}

int agregoEnArreglo (int arreglo[], int validos, int dim, int dato)
{
    if(validos<dim)
    {
        arreglo[validos] = dato;
        validos++;
    }
    return validos;
}

// ADL, ADL, LDL , LDA


