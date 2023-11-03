#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct{

    int id;
    int idCuenta;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual;
    int eliminado;  /// 0 si esta activo, 1 si esta dado de baja;
}stCuenta;

stCuenta cargarUnaCuenta();
void muestraCuenta(stCuenta c);

#endif // CUENTA_H_INCLUDED
