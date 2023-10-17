#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int nroCliente;
    char nombre[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int eliminado; /// 0 si esta activo, 1 si esta dado de baja
}stCliente;

stCliente cargaUnCliente();
void muestraCliente(stCliente cli);

#endif // CLIENTE_H_INCLUDED
