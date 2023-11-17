#ifndef JUGADOREQUIPO_H_INCLUDED
#define JUGADOREQUIPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "equipo.h"
#include "jugador.h"

typedef struct{
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;

}stJugadorEquipo;


void mostrarJugadorEquipo(stJugadorEquipo j);
stJugador getJugador(stJugadorEquipo j);
stEquipo getEquipo(stJugadorEquipo j);


#endif // JUGADOREQUIPO_H_INCLUDED
