#ifndef ADA_H_INCLUDED
#define ADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registroArchivo.h"
#include "stPaciente.h"
#include "especialidad.h"
#include "arbol.h"
#include "string.h"

typedef struct {
    stEspecialidad especialidad;
    nodoArbol * arbol;
}stCelda;

int alta (stCelda ada[], int v, stEspecialidad e, stPaciente p);
int buscarPosicion(stCelda ada[],int v, char nombreEspecialidad[]);
int agregarEspecialidad(stCelda ada[],int v, stEspecialidad e);
void mostrarCelda(stCelda c);
#endif // ADA_H_INCLUDED
