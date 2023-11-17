#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;
    int idEquipo;
}stJugador;

void mostrarJugador(stJugador j);



#endif // JUGADOR_H_INCLUDED
