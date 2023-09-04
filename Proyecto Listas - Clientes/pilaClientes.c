#include "pilaClientes.h"


void inicPila(Pila* p)
{
    (*p) = inicLista();
}

int pilavacia(Pila* p)
{
    int flag = 1;

    if((*p))
    {
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    return flag;
}

void apilarClientePila(Pila* p, stCliente cliente)
{
    (*p) = agregarPrincipio((*p), crearNodo(cliente));
}

stCliente desapilarClientePila(Pila* p)
{
    stCliente aux = verPrimerNodo((*p));
    (*p) = borrarPrimerNodo((*p));

    return aux;
}

stCliente topePilaCliente(Pila* p)
{
    stCliente aux = verPrimerNodo((*p));
    return aux;
}






