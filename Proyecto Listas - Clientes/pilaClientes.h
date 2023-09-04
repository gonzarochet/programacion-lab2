#ifndef PILACLIENTES_H_INCLUDED
#define PILACLIENTES_H_INCLUDED
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

#define Pila nodoSimpleClientes*

void inicPila (Pila * p);
int pilavacia (Pila* p);
void apilarClientePila(Pila* p, stCliente cliente);
stCliente desapilarClientePila(Pila* p);
stCliente topePilaCliente(Pila* p);



#endif // PILACLIENTES_H_INCLUDED
