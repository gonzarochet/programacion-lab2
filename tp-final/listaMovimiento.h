#ifndef LISTAMOVIMIENTO_H_INCLUDED
#define LISTAMOVIMIENTO_H_INCLUDED

#include "movimiento.h"

typedef struct _nodoListaMov{
    stMovimiento dato;
    struct _nodoListaMov * sig;
    struct _nodoListaMov * ante;
} nodoListaMov;

nodoListaMov * inicLista();
nodoListaMov * crearNodoLista(stMovimiento dato);
nodoListaMov * agregarMovimientoAlFinal(nodoListaMov * lista, nodoListaMov * nuevo);
nodoListaMov * buscarUltimo(nodoListaMov * lista);
void mostrarListaMovimiento(nodoListaMov * lista);

#endif // LISTAMOVIMIENTO_H_INCLUDED
