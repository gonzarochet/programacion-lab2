#ifndef CELDACUENTA_H_INCLUDED
#define CELDACUENTA_H_INCLUDED

#include "cuenta.h"
#include "listaMovimiento.h"

typedef struct {
    stCuenta cuenta;
    nodoListaMov * lista;
}celdaCuenta;

celdaCuenta altaCeldaCuenta(stCuenta cuenta);


#endif // CELDACUENTA_H_INCLUDED
