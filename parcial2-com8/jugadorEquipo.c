#include "jugadorEquipo.h"


void mostrarJugadorEquipo(stJugadorEquipo j){

    printf("\nId Equipo..........:%d",j.idEquipo);
    printf("\nNombre Equipo......:%s",j.nombreEquipo);
    printf("\nId Jugador.........:%d",j.idJugador);
    printf("\nNro Camiseta.......:%d",j.nroCamisetaJugador);
    printf("\nNombre Jugador.....:%s",j.nombreJugador);
    printf("\nPuntos Anotados....:%d",j.puntosAnotados);

}

stJugador getJugador(stJugadorEquipo j){

    stJugador jug;

    jug.idJugador = j.idJugador;
    strcpy(jug.nombreJugador,j.nombreJugador);
    jug.idEquipo = j.idEquipo;
    jug.nroCamisetaJugador = j.nroCamisetaJugador;
    jug.puntosAnotados = j.puntosAnotados;

    return jug;
}

stEquipo getEquipo(stJugadorEquipo j){
    stEquipo equi;

    equi.idEquipo = j.idEquipo;
    strcpy(equi.nombreEquipo,j.nombreEquipo);

    return equi;

}

