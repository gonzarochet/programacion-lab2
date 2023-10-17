#include "cuenta.h"

stCuenta cargarUnaCuenta()
{
    stCuenta cuenta;

    printf("Ingrese el ID de la cuenta: ");
    scanf("%d", &cuenta.id);
    fflush(stdin);

    printf("Ingrese el ID de la cuenta principal: ");
    scanf("%d", &cuenta.idCuenta);
    fflush(stdin);

    printf("Ingrese el número de cuenta: ");
    scanf("%d", &cuenta.nroCuenta);
    fflush(stdin);

    printf("Ingrese el tipo de cuenta (0 para corriente, 1 para ahorro, etc.): ");
    scanf("%d", &cuenta.tipoDeCuenta);
    fflush(stdin);

    printf("Ingrese el costo mensual de la cuenta: ");
    scanf("%f", &cuenta.costoMensual);
    fflush(stdin);

    cuenta.eliminado = 0; // Establecer como activo por defecto

    return cuenta;

}

void muestraCuenta(stCuenta c)
{
    printf("Id............:%d", c.id);
    printf("Id Cuenta.....:%d", c.idCuenta);
    printf("Nro Cuenta.....:%d", c.nroCuenta);
    printf("Tipo Cuenta.......:%d", c.tipoDeCuenta);
    printf("Costo mensual.......:%f", c.costoMensual);
    printf("Eliminado.....:%d", c.eliminado);
}
