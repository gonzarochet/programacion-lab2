#ifndef ARRAYCUENTA_H_INCLUDED
#define ARRAYCUENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "celdaCuenta.h"


typedef struct {
    celdaCuenta arreglo[3]; // celdaCuenta * arreglo (dinamico)
    int dim;
    int v;
}arregloCuenta;

void inicializarArreglo(arregloCuenta c);
void agregarCuenta(arregloCuenta arr, celdaCuenta celda);
int buscaCuenta(arregloCuenta arr, int tipoCuenta);

#endif // ARRAYCUENTA_H_INCLUDED
