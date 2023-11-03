#ifndef TP1-EJERCICIOS_H_INCLUDED
#define TP1-EJERCICIOS_H_INCLUDED


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
#include "pilaClientes.h"

#define Pila nodoSimpleClientes*

nodoSimpleClientes * archivo2listaSimple (char archivo[], nodoSimpleClientes * lista);
void archivo2listaSimplePD (char archivo[], nodoSimpleClientes ** lista);
void archivo2listaSimpleOrdenadoPD (char archivo[], nodoSimpleClientes ** lista);
int buscaElementoEnListaSimplePD (nodoSimpleClientes ** lista, char apellido[30]);

nodoSimpleClientes * intercalarElementosOrdenadosListaSimplePD(nodoSimpleClientes * listaA, nodoSimpleClientes * listaB, nodoSimpleClientes * listaC);
nodoSimpleClientes * invertirElementosLista (nodoSimpleClientes * lista);

void Archi2PilaClientes(char archivo[], Pila* pilaClientes);
void PilaClientes2Lista(Pila* PilaClientes, nodoSimpleClientes ** lista);
void muestraPila(Pila * p);
nodoSimpleClientes * EliminarDniMenor10Millones (nodoSimpleClientes * lista, int parametro);

#endif // TP1-EJERCICIOS_H_INCLUDED
