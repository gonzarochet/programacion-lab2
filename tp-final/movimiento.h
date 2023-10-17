#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef struct{

    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;  /// 0 si esta activo, 1 si esta dado de baja;

 }stMovimiento;

stMovimiento cargarMovimiento();
void muestraMovimiento(stMovimiento m);


#endif // MOVIMIENTO_H_INCLUDED
