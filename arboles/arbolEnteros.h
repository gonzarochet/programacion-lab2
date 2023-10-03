#ifndef ARBOLENTEROS_H_INCLUDED
#define ARBOLENTEROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dato;
    struct nodoArbolInt * izq;
    struct nodoArbolInt * der;
}nodoArbolInt;

nodoArbolInt * inicArbol();

nodoArbolInt * crearNodoArbol(int dato);
void * nuevoArbol(nodoArbolInt * raiz, nodoArbolInt * ramaDerecha, int dato, nodoArbolInt * ramaIzquierda);
nodoArbolInt * insertarNodo(nodoArbolInt*arbol, int dato);

void visitar(nodoArbolInt * arbol);
void preOrder(nodoArbolInt * arbol);
void inOrder(nodoArbolInt * arbol);
void postOrder(nodoArbolInt * arbol);

int cantNodosGradoUno(nodoArbolInt * arbol);

int profundidadArbol(nodoArbolInt * arbol);
int cantidadNodos(nodoArbolInt * arbol);
int cantidadHojas(nodoArbolInt * arbol);
int esHoja (nodoArbolInt * nodo);

nodoArbolInt * buscarInfoEspec(nodoArbolInt * arbol, int buscado);
nodoArbolInt *  nodoMasDerecho(nodoArbolInt * nodo);
nodoArbolInt * nodoMasIzquierdo(nodoArbolInt * nodo);
nodoArbolInt * eliminarNodo (nodoArbolInt * arbol, int dato);

void eliminar2 (nodoArbolInt ** raiz, int clave);
void reemplazar(nodoArbolInt ** act);




#endif // ARBOLENTEROS_H_INCLUDED
