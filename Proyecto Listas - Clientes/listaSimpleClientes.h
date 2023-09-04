#ifndef LISTASIMPLECLIENTES_H_INCLUDED
#define LISTASIMPLECLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "archivoClientes.h"
#include "listaSimpleClientes.h"


typedef struct{

    stCliente dato;
    struct nodo* siguiente;

}nodoSimpleClientes;



nodoSimpleClientes* inicLista();
nodoSimpleClientes * crearNodo(stCliente clienteAgregar);

stCliente verPrimerNodo (nodoSimpleClientes * lista);

void muestraNodo (nodoSimpleClientes * nodoLeer);
void muestraLista(nodoSimpleClientes* lista);

nodoSimpleClientes * agregarPrincipio(nodoSimpleClientes* lista, nodoSimpleClientes* nuevoNodo);
nodoSimpleClientes * agregarEnOrdenDni (nodoSimpleClientes * lista, nodoSimpleClientes * nodoAgregar);
nodoSimpleClientes * agregarFinalLista(nodoSimpleClientes * lista, nodoSimpleClientes * nuevoNodo);



nodoSimpleClientes * buscarNodoxNombreCli(nodoSimpleClientes * lista, char arreglo[20]);

nodoSimpleClientes * borrarNodoListaApellido (nodoSimpleClientes * lista , char apellido[20]);
nodoSimpleClientes * borrarLista (nodoSimpleClientes* lista);
nodoSimpleClientes * borrarUltimoNodo(nodoSimpleClientes * lista);
nodoSimpleClientes * borrarPrimerNodo (nodoSimpleClientes * lista);





#endif // LISTASIMPLECLIENTES_H_INCLUDED
