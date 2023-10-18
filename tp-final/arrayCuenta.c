#include "arrayCuenta.h"

arregloCuenta inicializarArreglo(arregloCuenta c)
{
    c.v = 0;
    c.dim = 3;

    return c;
}


arregloCuenta agregarCuentaArreglo(arregloCuenta arr, stCuenta cnta){

    if(arr.v < arr.dim)
    {
        celdaCuenta celda;
        celda = altaCeldaCuenta(cnta);
        arr.arreglo[arr.v] = celda;
        arr.v++;
    }

    return arr;

}

arregloCuenta altaArregloCuentas(arregloCuenta  arr, stCuenta cnta, stMovimiento mov)
{
    nodoListaMov * nuevo = crearNodoLista(mov);
    int posCuenta = buscaCuenta(arr,cnta.tipoDeCuenta);

    if(posCuenta==-1)
    {
        arr = agregarCuentaArreglo(arr,cnta);
        posCuenta = arr.v - 1;
    }

    arr.arreglo[posCuenta].lista = agregarMovimientoAlFinal(arr.arreglo[posCuenta].lista,nuevo);

    return arr;

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

void mostrarArregloCuentas(arregloCuenta arr){
    int i = 0;

    while(i<arr.v){
        printf("\n Cuenta: \n");
        muestraCuenta(arr.arreglo[i].cuenta);
        printf("\nLista de los movimientos: \n");
        mostrarListaMovimiento(arr.arreglo[i].lista);
        i++;
    }


}
