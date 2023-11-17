#include "listaEquipo.h"

nodoEquipo * inicListaEquipo()
{
    return NULL;
}
nodoEquipo * crearNodoEquipo(stEquipo e)
{

    nodoEquipo * nuevo = (nodoEquipo*) malloc(sizeof(nodoEquipo));
    nuevo->dato = e;
    nuevo->sig = NULL;
    nuevo->listaJugadores = inicListaJugador();

    return nuevo;
}

nodoEquipo * buscarUltimoEquipo(nodoEquipo * ldl)
{
    if(ldl)
    {
        while(ldl->sig)
        {
            ldl = ldl->sig;
        }
    }
    return ldl;
}

nodoEquipo * agregarAlFinalEquipo(nodoEquipo * ldl, nodoEquipo * nuevoEquipo)
{
    if(!ldl)
        ldl = nuevoEquipo;
    else
    {
        nodoEquipo * aux = buscarUltimoEquipo(ldl);
        aux->sig = nuevoEquipo;
    }
    return ldl;
}

nodoEquipo * buscarEquipo(nodoEquipo * ldl, int idEquipo)
{

    nodoEquipo * aBuscar = NULL;

    while(ldl && !aBuscar)
    {
        if(ldl->dato.idEquipo == idEquipo){
            aBuscar = ldl;
        }

        ldl = ldl->sig;
    }

    return aBuscar;
}
/// 2 y 3
nodoEquipo * alta(nodoEquipo *ldl, stEquipo e, stJugador j){

    nodoEquipo * nuevo = buscarEquipo(ldl,e.idEquipo);

    if(!nuevo){
        nuevo = crearNodoEquipo(e);
        ldl = agregarAlFinalEquipo(ldl,nuevo);
    }

    nuevo->listaJugadores = agregarAlFinal(nuevo->listaJugadores,crearNodoJugador(j));

    return ldl;
}
/***
4- Realizar una función que muestre los equipos con sus jugadores correspondientes.
Tenga en cuenta la modularización y la responsabilidad de cada estructura de datos trabajada.
**/

void mostrarListaEquipos(nodoEquipo * ldl){

    while(ldl){
        printf("\n\n----- EQUIPO-------\n\n");
        mostrarEquipo(ldl->dato);
        mostrarListaJugadores(ldl->listaJugadores);
        printf("\n\n----- FIN EQUIPO-------\n\n");
        ldl = ldl->sig;
    }
}



/***
6- Realizar una función (o varias) que determine qué porcentaje con respecto al total de
jugadores del torneo, representan los jugadores de un equipo determinado.

El subprograma deberá informar por pantalla:
Total de jugadores del torneo.
Total de jugadores del equipo.
Porcentaje con respecto al total.

**/

int cuentaEquipos(nodoEquipo * ldl){
    return (ldl) ? 1 + cuentaEquipos(ldl->sig):0;
}

int cuentaJugadoresTodosEquipos(nodoEquipo * ldl){
    return (ldl) ? cuentaJugadores(ldl->listaJugadores) + cuentaJugadoresTodosEquipos(ldl->sig) : 0;
}

float porcentajeRepresentaUnEquipo(nodoEquipo * ldl, int idEquipo){
    float total = 0.0;
    nodoEquipo * equipo = buscarEquipo(ldl,idEquipo);

    if(equipo){
        total = (float) ((float)(cuentaJugadores(equipo->listaJugadores) * 100) / cuentaJugadoresTodosEquipos(ldl));
    }

    return total;
}
