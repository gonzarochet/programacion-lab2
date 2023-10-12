#ifndef LISTASENTEROS_H_INCLUDED
#define LISTASENTEROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodoLista{
    int dato;
    struct _nodoLista * sig;
}nodoLista;

nodoLista * inicLista();
nodoLista * crearNodoLista(int dato);
nodoLista * agregarAlPrincipio(nodoLista * lista, nodoLista * nuevo);
void mostrarLista(nodoLista * lista);





#endif // LISTASENTEROS_H_INCLUDED
