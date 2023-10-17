#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED

#include "cliente.h"
#include "arrayCuenta.h"
#include "celdaCuenta.h"
#include "movimiento.h"

typedef struct _nodoArbolCli{
    stCliente dato;
    arregloCuenta arregloCuenta;
    struct _nodoArbolCli * izq;
    struct _nodoArbolCli * der;
}nodoArbolCli;

nodoArbolCli * inicArbol();
nodoArbolCli * crearNodoArbol(stCliente cli);
nodoArbolCli * alta(nodoArbolCli * arbol, stCliente cli, celdaCuenta celda, stMovimiento mov);
nodoArbolCli * insertarNodo(nodoArbolCli * arbol, nodoArbolCli * nuevo);



#endif // ARBOLCLIENTES_H_INCLUDED
