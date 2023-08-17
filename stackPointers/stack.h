#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

typedef struct {
    stStudent * student;
    int nextPosition;
    int dim;
}StackStudent;

// inicializar
void initStack(StackStudent * s);
// apilar elemento
int pushStack(StackStudent * s, stStudent sv);

// desapilar elemento
stStudent popStack(StackStudent * s);
// tope pila
stStudent peekStack(StackStudent * s);
// esta vacia pila
int isEmptyStack(StackStudent * s);
// muestra pila;
void showStack(StackStudent * s);

// de pila a arreglo estatico/dinámico
int stackStudentToArray(StackStudent * s, stStudent ** arr,int dim);


#endif // STACK_H_INCLUDED
