#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int idEquipo;
    char nombreEquipo[30];
}stEquipo;


void mostrarEquipo(stEquipo e);

#endif // EQUIPO_H_INCLUDED
