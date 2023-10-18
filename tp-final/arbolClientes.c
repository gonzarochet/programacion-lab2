#include "arbolClientes.h"
#include "celdaCuenta.h"

nodoArbolCli * inicArbol(){
    return NULL;
}

nodoArbolCli * crearNodoArbol(stCliente cli){
    nodoArbolCli * aux = (nodoArbolCli * )malloc(sizeof(nodoArbolCli));
    aux->dato = cli;
    aux->arregloCuenta =  inicializarArreglo(aux->arregloCuenta);
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbolCli * alta(nodoArbolCli * arbol, stCliente cli, stCuenta cnta, stMovimiento mov){
    nodoArbolCli * aux = crearNodoArbol(cli);
    aux->arregloCuenta = altaArregloCuentas(aux->arregloCuenta,cnta,mov);
    arbol = insertarNodo(arbol,aux);
    return aux;
}

nodoArbolCli * insertarNodo(nodoArbolCli *arbol, nodoArbolCli * nuevo)
{
    if(!arbol)
    {
        arbol=nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) < atoi(arbol->dato.dni))
        {
            arbol->izq = insertarNodo(arbol->izq,nuevo);
        }
        else
        {
            arbol->der = insertarNodo(arbol->der,nuevo);
        }
    }
    return arbol;
}

void visitar(nodoArbolCli * arbol)
{
    muestraCliente(arbol->dato);
}

void preOrder(nodoArbolCli * arbol)
{
    if(arbol)
    {
        visitar(arbol);
        mostrarArregloCuentas(arbol->arregloCuenta);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}
