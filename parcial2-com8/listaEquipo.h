#ifndef LISTAEQUIPO_H_INCLUDED
#define LISTAEQUIPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "equipo.h"
#include "listaJugador.h"

typedef struct _nodoEquipo{

    stEquipo dato;
    struct _nodoEquipo * sig;
    nodoJugador * listaJugadores;

}nodoEquipo;

nodoEquipo * inicListaEquipo();
nodoEquipo * crearNodoEquipo(stEquipo e);
nodoEquipo * buscarUltimoEquipo(nodoEquipo * ldl);
nodoEquipo * agregarAlFinalEquipo(nodoEquipo * ldl, nodoEquipo * nuevoEquipo);
nodoEquipo * buscarEquipo(nodoEquipo * ldl, int idEquipo);
nodoEquipo * alta(nodoEquipo *ldl, stEquipo e, stJugador j);
void mostrarListaEquipos(nodoEquipo * ldl);
int cuentaEquipos(nodoEquipo * ldl);
int cuentaJugadoresTodosEquipos(nodoEquipo * ldl);
float porcentajeRepresentaUnEquipo(nodoEquipo * ldl, int idEquipo);

#endif // LISTAEQUIPO_H_INCLUDED
