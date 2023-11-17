#include "listaJugador.h"


nodoJugador * inicListaJugador()
{
    return NULL;
}

nodoJugador * crearNodoJugador(stJugador dato)
{
    nodoJugador * nuevo = (nodoJugador*) malloc(sizeof(nodoJugador));
    nuevo->dato = dato;
    nuevo->sig = NULL;

    return nuevo;

}

nodoJugador * buscarUltimo(nodoJugador * lista)
{
    if(lista)
    {
        while(lista->sig)
        {
            lista = lista->sig;
        }
    }

    return lista;
}

nodoJugador * agregarAlFinal(nodoJugador * lista, nodoJugador * nuevo)
{

    if(!lista)
        lista = nuevo;
    else{
        nodoJugador * aux = buscarUltimo(lista);
        aux->sig = nuevo;
    }

    return lista;
}

void mostrarListaJugadores(nodoJugador * lista){
    printf("\n------- Plantel-----\n");
    while(lista){
        mostrarJugador(lista->dato);
        printf("\n");
        lista = lista->sig;
    }
    printf("\n-------Fin del Plantel-----\n");

}

stJugador jugadorGoleador(nodoJugador * lista){

    stJugador jMax;
    jMax.puntosAnotados = 0;

    while(lista){
        if(jMax.puntosAnotados < lista->dato.puntosAnotados){
            jMax = lista->dato;
        }
        lista = lista->sig;
    }

    return jMax;
}

int cuentaJugadores(nodoJugador * lista){
    return (lista) ? 1 + cuentaJugadores(lista->sig) : 0;
}

/// 7.
stJugador buscarJugadorXCamiseta(nodoJugador * lista ,int nroCamiseta){
    stJugador aux;
    aux.idJugador = -1;

    while(lista && aux.idJugador == -1){
        if(lista->dato.nroCamisetaJugador == nroCamiseta){
            aux = lista->dato;
        }
        lista = lista->sig;
    }

    return aux;
}
