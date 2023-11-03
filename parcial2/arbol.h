#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stPaciente.h"

typedef struct _nodoArbol{
    stPaciente dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stPaciente dato);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, stPaciente dato);
nodoArbol* agregarNodoArbolSinRepetidos(nodoArbol* arbol, stPaciente dato);
void preOrden(nodoArbol* arbol);
void inOrden(nodoArbol* arbol);
void postOrden(nodoArbol* arbol);
nodoArbol* buscaNodoArbol(nodoArbol* arbol, int id);
int buscaPaciente(nodoArbol * arbol,char nombre[], char apellido[]);
void arbol2Archi(nodoArbol * arbol , FILE * archi);
int cuentaPacientes(nodoArbol * arbol);

#endif // ARBOL_H_INCLUDED
