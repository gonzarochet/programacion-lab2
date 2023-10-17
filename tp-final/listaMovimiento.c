#include "listaMovimiento.h"
#include <stdio.h>
#include <stdlib.h>

nodoListaMov * inicLista()
{
    return NULL;
}
nodoListaMov * crearNodoLista(stMovimiento dato)
{

    nodoListaMov * aux = (nodoListaMov*) malloc(sizeof(nodoListaMov));
    aux->dato = dato;
    aux->sig = NULL;
    aux->ante = NULL;

    return aux;
}

void agregarMovimientoAlFinal(nodoListaMov ** lista, nodoListaMov * nuevo)
{

    if(!(*lista))
    {
        (*lista) = nuevo;

    }
    else
    {

        nodoListaMov * ult = buscarUltimo(*lista);
        nuevo->ante = ult;
        ult->sig = nuevo;
    }
}

nodoListaMov * buscarUltimo(nodoListaMov * lista)
{
    nodoListaMov* seg = lista;

    while(seg->sig)
    {
        seg = seg->sig;
    }

    return seg;
}


void muestraNodo(nodoListaMov * nodo)
{
    printf("\n Nodo: %p", nodo);
    muestraMovimiento(nodo->dato);
    printf("\n Nodo->sig: %p", nodo->sig);

}

