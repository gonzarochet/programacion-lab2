#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "archivoClientes.h"
#include "listaSimpleClientes.h"
#include "registroArchivo.h"
#include "utilidades.h"
#include "gotoxy.h"
#include "listaDobleCliente.h"
#include "muestraMenu.h"
#include "tp1-Ejercicios.h"
#include "pilaClientes.h"

typedef struct{

    struct nodoDobleCliente* inicio;
    struct nodoDobleCliente* cola;

}Fila;



void agregarFila(Fila* fila, stCliente dato);
stCliente verPrimeroEnFila(Fila * fila);
stCliente desencolarFila(Fila * fila);
int filavacia(Fila *fila);
void muestraFila (Fila* fila);


#endif // FILA_H_INCLUDED
