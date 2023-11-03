#include "cliente.h"

stCliente cargarUnCliente() {

    stCliente cliente;

    printf("Ingrese el ID del cliente: ");
    scanf("%d", &cliente.id);

    printf("Ingrese el número de cliente: ");
    scanf("%d", &cliente.nroCliente);

    printf("Ingrese el nombre del cliente: ");
    fflush(stdin);
    scanf("%s", cliente.nombre);

    printf("Ingrese el DNI del cliente: ");
    fflush(stdin);
    scanf("%s", cliente.dni);

    printf("Ingrese el email del cliente: ");
    fflush(stdin);
    scanf("%s", cliente.email);

    printf("Ingrese el domicilio del cliente: ");
    fflush(stdin);
    scanf("%s", cliente.domicilio);

    printf("Ingrese el teléfono del cliente: ");
    fflush(stdin);
    scanf("%s", cliente.telefono);

    cliente.eliminado = 0; // Establecer como activo por defecto

    return cliente;
}


void muestraCliente(stCliente cli){
    printf("Nombre........: %s\n",cli.nombre);
    printf("DNI...........: %s\n",cli.dni);
    printf("Domicilio.....: %s\n",cli.domicilio);
    printf("ID............: %d\n",cli.id);
    printf("Email.........: %s\n",cli.email);
    printf("Nro Cliente...: %d\n",cli.nroCliente);
    printf("Telefono......: %s\n",cli.telefono);
    printf("Eliminado.....: %d\n",cli.eliminado);
}
