#include "movimiento.h"

stMovimiento cargarMovimiento() {
    stMovimiento movimiento;

    printf("Ingrese el ID del movimiento: ");
    scanf("%d", &movimiento.id);
    fflush(stdin);

    printf("Ingrese el ID de la cuenta: ");
    scanf("%d", &movimiento.idCuenta);
    fflush(stdin);

    printf("Ingrese el año del movimiento: ");
    scanf("%d", &movimiento.anio);
    fflush(stdin);

    printf("Ingrese el mes del movimiento: ");
    scanf("%d", &movimiento.mes);
    fflush(stdin);

    printf("Ingrese el día del movimiento: ");
    scanf("%d", &movimiento.dia);
    fflush(stdin);

    printf("Ingrese el detalle del movimiento: ");
    fgets(movimiento.detalle, sizeof(movimiento.detalle), stdin);
    movimiento.detalle[strcspn(movimiento.detalle, "\n")] = '\0';

    printf("Ingrese el importe del movimiento: ");
    scanf("%f", &movimiento.importe);
    fflush(stdin);

    movimiento.eliminado = 0; // Establecer como activo por defecto

    return movimiento;
}

void muestraMovimiento(stMovimiento m){
    printf("Id............:%d", m.id);
    printf("Id Cuenta.....:%d", m.idCuenta);
    printf("Detalle.......:%s", m.detalle);
    printf("Importe.......:%f", m.importe);
    printf("Fecha.........:%d / %d / %d ",m.dia, m.mes, m.anio);
    printf("Eliminado.....:%d", m.eliminado);
}

