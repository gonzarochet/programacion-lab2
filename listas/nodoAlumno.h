#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"
#include "alumno.h"

typedef struct {
    stStudent  dato;
    struct nodoAlumno * sig;
}nodoAlumno;

nodoAlumno * inicLista();
nodoAlumno * crearNodo(stStudent student);
nodoAlumno * agregarPrincipio(nodoAlumno * lista, nodoAlumno * nuevoNodo);




#endif // NODOALUMNO_H_INCLUDED
