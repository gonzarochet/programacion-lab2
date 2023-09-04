#ifndef LISTADOBLECLIENTE_H_INCLUDED
#define LISTADOBLECLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "archivoClientes.h"


typedef struct{

    stCliente dato;
    struct nodoDobleCliente * siguiente;
    struct nodoDobleCliente * anterior;

}nodoDobleCliente;

nodoDobleCliente* inializarLista2();
nodoDobleCliente* crearNodo2(stCliente dato);
nodoDobleCliente * agregarPrincipio2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar);
nodoDobleCliente * agregarEnOrdenDni2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar);
nodoDobleCliente * agregarFinalLista2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar);



void muestraNodo2(nodoDobleCliente * nodo);
void muestraLista2(nodoDobleCliente * lista);

stCliente verPrimerNodo2(nodoDobleCliente * lista);
nodoDobleCliente * buscaNodoxDni2(nodoDobleCliente* lista, char dni[10]);
nodoDobleCliente * buscarUltimoNodo2(nodoDobleCliente * lista);

nodoDobleCliente * borraPrimerNodoLista2(nodoDobleCliente * lista);
nodoDobleCliente * borraPrimerNodoLista2Version2(nodoDobleCliente * lista);
nodoDobleCliente * borrarNodo2ListaDni (nodoDobleCliente* lista, char dni[10]);
nodoDobleCliente * borrarUltimoNodo2(nodoDobleCliente * lista);
nodoDobleCliente * borrarLista2 (nodoDobleCliente* lista);







#endif // LISTADOBLECLIENTE_H_INCLUDED
