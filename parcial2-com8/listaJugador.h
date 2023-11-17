#ifndef LISTAJUGADOR_H_INCLUDED
#define LISTAJUGADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"

typedef struct _nodoJugador{

    stJugador dato;
    struct _nodoJugador * sig;

}nodoJugador;

nodoJugador * inicListaJugador();
nodoJugador * crearNodoJugador(stJugador dato);
nodoJugador * buscarUltimo(nodoJugador * lista);
nodoJugador * agregarAlFinal(nodoJugador * lista, nodoJugador * nuevo);
void mostrarListaJugadores(nodoJugador * lista);
stJugador jugadorGoleador(nodoJugador * lista);
int cuentaJugadores(nodoJugador * lista);
stJugador buscarJugadorXCamiseta(nodoJugador * lista ,int nroCamiseta);



#endif // LISTAJUGADOR_H_INCLUDED
