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
    printf("Nombre........: %s",cli.nombre);
    printf("DNI...........: %s",cli.dni);
    printf("Domicilio.....: %s",cli.domicilio);
    printf("ID............: %s",cli.id);
    printf("Email.........: %s",cli.email);
    printf("Nro Cliente...: %s",cli.nroCliente);
    printf("Telefono......: %s",cli.telefono);
    printf("Eliminado.....: %s",cli.eliminado);
}
