#include <stdio.h>
#include <stdlib.h>
#include "arbolEnteros.h"
#include "listasEnteros.h"
#include "math.h"

int cargarArreglo(int arreglo[], int dim);
void mostrarArreglo(int arreglo[], int validos, int dim);
nodoArbolInt * arregloToArbol(int arreglo[], int validos, nodoArbolInt* arbol);
int nroNoRepetido(int arreglo[], int validos,  int dato);
int agregoEnArreglo (int arreglo[], int validos, int dim, int dato);

/// ARB TO LIST
nodoLista * arbol2Lista(nodoArbolInt * arbol, nodoLista * lista);
nodoLista * arbol2ListaConFiltro(nodoArbolInt * arbol, nodoLista * lista, int filtro);

/// ARB TO ARR
int arbolToArray (nodoArbolInt * arbol, int arreglo[], int validos, int dim );
/// ARR TO ARB
nodoArbolInt * arregloToArbol(int arreglo[], int validos, nodoArbolInt* arbol);
nodoArbolInt * arregloToArbolBalanceado(int arreglo[], int inicio, int fin, nodoArbolInt * arbol);

int main()
{
    //srand(time(NULL));
    nodoArbolInt * arbolito = inicArbol();
    nodoArbolInt * arbolito2 = inicArbol();

    int arreglo[10] = {8,2,10,6,5,4,7,1,9,3};
    int arreglo2[10];

    int validos = 10;
    int validos2 = 0;
    //validos = cargarArreglo(arreglo,10);
    printf("Arreglo original: \n");
    mostrarArreglo(arreglo,validos,10);

    printf("\n");
    arbolito = arregloToArbol(arreglo,validos,arbolito);
   // preOrder(arbolito);

    printf("\n");
    validos2 = arbolToArray(arbolito,arreglo2,0,10);
    printf("Arreglo 2 con los datos del arbol 1: \n");
    mostrarArreglo(arreglo2,validos2,10);

    printf("\n");
    arbolito2 = arregloToArbolBalanceado(arreglo2,0,validos2-1,arbolito2);
    //preOrder(arbolito2);

    printf("\n --- ARBOL 1 GRAFICO ---\n"),
    dibujarArbol(arbolito,0);
    printf("\n\n\n --- ARBOL 2 GRAFICO ---\n"),
    dibujarArbol(arbolito2,0);

    system("pause");

    nodoLista * lista = inicLista();
    lista = arbol2ListaConFiltro(arbolito,lista,5);

    mostrarLista(lista);

    system("pause");


//    int cantidad = cantidadHojas(arbolito);
//
//    int cantG1 = cantNodosGradoUno(arbolito);
//
//    printf("\n El valor de cantidad  de hojas es: %d", cantidad);
//    printf("\n El valor de cantidad de grado uno es: %d", cantG1);
//    printf("\n");
//
//    system("pause");
//
//    printf("\n2.\n");
//
//
//
//    /*nodoArbolInt * arbolote = eliminarNodo(arbolito,5);
//     inOrder(arbolote);*/
//
//    eliminar2(&arbolito,5);
//    inOrder(arbolito);
//
//    printf("\n3.\n");
//    validos = arbolToArray(arreglo2,0,9,arbolito);
//    mostrarArreglo(arreglo2,validos,9);
//    printf("\n El valor de validos es: %d", validos);

    return 0;
}



/// 2. ARREGLO TO ARBOL
int cargarArreglo(int arreglo[], int dim)
{
    int i=0;
    int dato = 0;

    for(i=0; i<dim; i++)
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
    for(i=0; i < validos; i++)
    {
        printf(" %d |",arreglo[i]);
    }
}




/// 1.1 ARBOL TO LISTA

nodoLista * arbol2Lista(nodoArbolInt * arbol, nodoLista * lista)
{

    if(arbol)
    {
        lista = agregarAlPrincipio(lista,crearNodoLista(arbol->dato));
        lista = arbol2Lista(arbol->der,lista);
        lista = arbol2Lista(arbol->izq,lista);

    }

    return lista;

}

/// 1.2 ARBOL TO LISTA Con FILTRO

nodoLista * arbol2ListaConFiltro(nodoArbolInt * arbol, nodoLista * lista, int filtro)
{

    if(arbol)
    {
        lista = arbol2ListaConFiltro(arbol->der,lista,filtro);
        if(arbol->dato > filtro)
        {
            lista = agregarAlPrincipio(lista,crearNodoLista(arbol->dato));
        }
        lista = arbol2ListaConFiltro(arbol->izq,lista,filtro);

    }


    return lista;

}

/// 2.1 ARBOL A ARREGLO


int agregoEnArreglo (int arreglo[], int validos, int dim, int dato)
{
    if(validos<=dim)
    {
        arreglo[validos] = dato;
        validos++;
    }
    return validos;
}


int arbolToArray (nodoArbolInt * arbol, int arreglo[], int validos, int dim )
{
    if(arbol)
    {
        validos = arbolToArray(arbol->izq, arreglo,validos,dim);
        // validos = agregoEnArreglo(arreglo,validos,dim,arbol->dato);
        if(validos<dim)
        {
            arreglo[validos] = arbol->dato;
            validos++;
        }
        validos = arbolToArray(arbol->der,arreglo,validos,dim);
    }
    return validos;

}

/// 2.2 ARREGLO TO ARBOL

nodoArbolInt * arregloToArbol(int arreglo[], int validos, nodoArbolInt* arbol)
{
    for(int i = 0; i<validos; i++)
    {
        arbol = insertarNodo(arbol,arreglo[i]);
    }

    return arbol;
}

/// 2.3 ARREGLO TO ARBOL (BALANCEADO)

nodoArbolInt * arregloToArbolBalanceado(int arreglo[], int inicio, int fin, nodoArbolInt * arbol)
{

    if(inicio<=fin)
    {
        int posMedio = floor((inicio + fin) / 2);
        arbol = insertarNodo(arbol,arreglo[posMedio]);
        arbol = arregloToArbolBalanceado(arreglo,inicio,posMedio-1,arbol);
        arbol = arregloToArbolBalanceado(arreglo,posMedio+1,fin,arbol);
    }


    return arbol;

}


// ADL, ADL, LDL , LDA


