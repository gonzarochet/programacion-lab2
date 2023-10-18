#include "celdaCuenta.h"

celdaCuenta altaCeldaCuenta(stCuenta cuenta){

    celdaCuenta celda;
    celda.cuenta = cuenta;
    celda.lista = inicLista();
      return celda;
}
