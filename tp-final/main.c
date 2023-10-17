#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "cuenta.h"
#include "movimiento.h"
#include "celdaCuenta.h"
#include "arbolClientes.h"
#include "arrayCuenta.h"

int main()
{
    printf("Hello world!\n");

    stCliente cli;
    cli = cargarUnCliente();

    stCuenta cuenta;
    cuenta = cargarUnaCuenta();

    stMovimiento mov;
    mov = cargarMovimiento();

    arbol = alta(arbol,cli,cuenta,mov);
    preOrder(arbol);



    return 0;
}
