#include "jugador.h"


void mostrarJugador(stJugador j){
    printf("\nId Jugador.........:%d",j.idJugador);
    printf("\nId Equipo.........:%d",j.idEquipo);
    printf("\nNro Camiseta.......:%d",j.nroCamisetaJugador);
    printf("\nNombre Jugador.....:%s",j.nombreJugador);
    printf("\nPuntos Anotados....:%d",j.puntosAnotados);
}

