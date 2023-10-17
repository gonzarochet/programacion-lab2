#include "arrayCuenta.h"

void inicializarArreglo(arregloCuenta c)
{
    c.v = 0;
    c.dim = 3;
}

void agregarCuentaArreglo(arregloCuenta arr, stCuenta cnta)
{

    if(buscaCuenta(arr,cnta.tipoDeCuenta)==-1)
    {
        if(arr.v < arr.dim)
        {
            celdaCuenta celda;
            celda = altaCeldaCuenta(cnta);
            arr.arreglo[arr.v] = celda;
            arr.v++;
        }
    }

}

int buscaCuenta(arregloCuenta arr, int tipoCuenta)
{
    int i = 0;
    int flag = -1;
    while(i < arr.v && flag  == -1)
    {
        if(arr.arreglo[i].cuenta.tipoDeCuenta == tipoCuenta)
        {
            flag = i;
        }
        i++;
    }
    return flag;
}
