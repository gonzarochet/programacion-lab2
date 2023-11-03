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

arregloCuenta inicializarArreglo(arregloCuenta c);
arregloCuenta agregarCuentaArreglo(arregloCuenta  arr, stCuenta cnta);
arregloCuenta altaArregloCuentas(arregloCuenta  arr, stCuenta cnta, stMovimiento mov);
int buscaCuenta(arregloCuenta arr, int tipoCuenta);
void mostrarArregloCuentas(arregloCuenta arr);

#endif // ARRAYCUENTA_H_INCLUDED
