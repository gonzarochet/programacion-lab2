#include "fila.h"

void inicFila (Fila* fila)
{
    fila->inicio = inializarLista2();
    fila->cola = inializarLista2();
}

void agregarFila(Fila* fila, stCliente dato)
{
    nodoDobleCliente* nuevo = crearNodo2(dato);
    fila->cola = agregarFinalLista2(fila->cola,nuevo);
    if(fila->inicio == NULL)
    {
        fila->inicio = fila->cola;
    }
    fila->cola = nuevo;
}

stCliente verPrimeroEnFila(Fila * fila)
{
    stCliente c;

    if(fila->inicio)
    {
        c = verPrimerNodo2(fila->inicio);
    }
}


stCliente desencolarFila(Fila * fila)
{
    stCliente c;
    if(fila->inicio)
    {
        c = verPrimeroEnFila(fila->inicio);
        fila->inicio = borraPrimerNodoLista2(fila->inicio);

        if(!fila->inicio)
        {
            fila->cola = inializarLista2();
        }

    }
    return c;

}


int filavacia(Fila* fila)
{
    int flag = 1;

    if(fila->inicio)
    {
       flag = 0;
    }
    return flag;
}


void muestraFila (Fila* fila)
{
    muestraLista2(fila->inicio);
}
