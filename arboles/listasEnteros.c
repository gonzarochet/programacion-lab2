#include "listasEnteros.h"

nodoLista * inicLista()
{
    return NULL;
}
nodoLista * crearNodoLista(int dato)
{
    nodoLista * aux= (nodoLista*) malloc(sizeof(nodoLista));
    aux->dato = dato;
    aux->sig = NULL;
    return aux;
}
nodoLista * agregarAlPrincipio(nodoLista * lista, nodoLista * nuevo)
{
    nuevo->sig = lista;
    return nuevo;
}

void mostrarLista(nodoLista * lista)
{
    while(lista){
        printf(" %d -->  ",lista->dato);
        lista = lista->sig;
    }
}
