#include "arbolEnteros.h"


nodoArbolInt * inicArbol()
{
    return NULL;
}

nodoArbolInt * crearNodoArbol(int dato)
{
    nodoArbolInt * aux = (nodoArbolInt*) malloc(sizeof(nodoArbolInt));

    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

//void * nuevoArbol(nodoArbolInt * raiz, nodoArbolInt * ramaDerecha, int dato, nodoArbolInt * ramaIzquierda)
//{
//    *raiz = crearNodoArbol(dato);
//    raiz->der = ramaDerecha;
//    raiz->izq = ramaIzquierda;
//}

nodoArbolInt * insertarNodo(nodoArbolInt*arbol, int dato)
{
    if(!arbol)
    {
        arbol=crearNodoArbol(dato);
    }
    else
    {
        if(dato < arbol->dato)
        {
            arbol->izq = insertarNodo(arbol->izq,dato);
        }
        else
        {
            arbol->der = insertarNodo(arbol->der,dato);
        }
    }
    return arbol;
}

int profundidadArbol(nodoArbolInt *arbol)
{
    int valorProfundidadDer = 0;
    int valorProfundidadIzq = 0;

    if(arbol)
    {
        valorProfundidadDer = profundidadArbol(arbol->der);
        valorProfundidadIzq = profundidadArbol(arbol->izq);
    }

    return (valorProfundidadDer > valorProfundidadIzq)? valorProfundidadDer+1 : valorProfundidadIzq+1;
}


void visitar(nodoArbolInt * arbol)
{
    printf(" %d |",arbol->dato);
}

void preOrder(nodoArbolInt * arbol)
{
    if(arbol)
    {
        visitar(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbolInt * arbol)
{
    if(arbol)
    {
        inOrder(arbol->izq);
        visitar(arbol);
        inOrder(arbol->der);
    }

}
void postOrder(nodoArbolInt * arbol)
{
    if(arbol)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        visitar(arbol);
    }

}

void dibujarArbol(nodoArbolInt* arbol, int nivel)
{
    if (arbol)
    {
        // Imprimir el subárbol derecho
        dibujarArbol(arbol->der, nivel + 1);

        // Imprimir espacios y conectores
        for (int i = 0; i < nivel; i++)
        {
            if (i == nivel - 1)
            {
                printf("+--");
            }
            else
            {
                printf("     ");
            }
        }

        // Imprimir el valor del nodo actual
        printf("|%d|\n", arbol->dato);

        // Imprimir el subárbol izquierdo
        dibujarArbol(arbol->izq, nivel + 1);
    }

}

int cantNodosGradoUno(nodoArbolInt * arbol){

    int cant = 0;
    if(arbol){
        if((!arbol->der && arbol->izq) ||(arbol->der &&  !arbol->izq)) {
            cant = 1 +  cantNodosGradoUno(arbol->der) + cantNodosGradoUno(arbol->izq);
        } else{
            cant = cantNodosGradoUno(arbol->der) + cantNodosGradoUno(arbol->izq);
        }
    }
    return cant;
}

nodoArbolInt * buscarInfoEspec(nodoArbolInt * arbol, int buscado)
{
    nodoArbolInt * aBuscar = NULL;

    if(arbol)
    {
        if(arbol->dato == buscado)
        {
            aBuscar = arbol;
        }
        else
        {
            if(arbol->dato > buscado)
            {
                aBuscar = buscarInfoEspec(arbol->izq,buscado);
            }
            else
            {
                aBuscar = buscarInfoEspec(arbol->der,buscado);
            }
        }
    }

    return aBuscar;
}

int cantidadNodos(nodoArbolInt * arbol)
{
    int cantidad = 0;

    if(arbol)
    {
        cantidad = cantidadNodos(arbol->izq) + cantidadNodos(arbol->der) +1 ;
    }

    return cantidad;
}

int cantidadHojas(nodoArbolInt * arbol)
{
    int hojas = 0;
    if(arbol)
    {
        if(esHoja(arbol))
        {
            hojas++;
        }
        else
        {
            hojas = cantidadHojas(arbol->der)+cantidadHojas(arbol->izq);
        }

    }
    return hojas;
}



nodoArbolInt * eliminarNodo (nodoArbolInt * arbol, int dato)
{
    if(arbol)
    {
        if(dato == arbol->dato)
        {
            if(arbol->izq)
            {
                nodoArbolInt * masDerecho = nodoMasDerecho(arbol->izq);
                arbol->dato = masDerecho->dato;
                arbol->izq = eliminarNodo(arbol->izq, masDerecho->dato);
            }
            else
            {
                if(arbol->der)
                {
                    nodoArbolInt * masIzquierdo = nodoMasIzquierdo(arbol->der);
                    arbol->dato = masIzquierdo->dato;
                    arbol->der = eliminarNodo(arbol->der, masIzquierdo->dato);
                }
                else
                {
                    if(esHoja(arbol)==1)
                    {
                        free(arbol);
                        arbol = NULL;
                    }
                }
            }
        }

        else if (dato > arbol->dato)
        {
            arbol->der = eliminarNodo(arbol->der,dato);
        }
        else if (dato < arbol->dato)
        {
            arbol->izq = eliminarNodo(arbol->izq,dato);
        }
    }

    return arbol;
}

int esHoja(nodoArbolInt * nodo)
{
    int flag = 0;
    if(!nodo->der && !nodo->izq)
    {
        flag = 1;
    }
    return flag;
}

nodoArbolInt *  nodoMasDerecho(nodoArbolInt * nodo)
{
    if(nodo)
    {
        if(nodo->der)
        {
            nodo = nodoMasDerecho(nodo->der);
        }
    }
    return nodo;
}

nodoArbolInt * nodoMasIzquierdo(nodoArbolInt * nodo)
{
    if(nodo)
    {
        if(nodo->izq)
        {
            nodo = nodoMasIzquierdo(nodo->izq);
        }
    }
    return nodo;
}


void eliminar2 (nodoArbolInt ** raiz, int clave)
{
    if(!(*raiz))
        puts("\n!NODO NO ENCONTRADO!!\n");
    else if(clave < (*raiz)->dato)
        eliminar2((&(*raiz)->izq),clave);
    else if(clave >(*raiz)->dato)
        eliminar2((&(*raiz)->der),clave);
    else
    {
        nodoArbolInt * q;
        q = (*raiz);
        if(q->izq == NULL)
            (*raiz) = q->der;
        else if (q->der == NULL)
            (*raiz)= q->izq;
        else
        {

            reemplazar(&q);
        }
        free(q);
    }

}

void reemplazar(nodoArbolInt ** act)
{
    nodoArbolInt *a,*p;
    p = *act;
    a = (*act)->izq;
    while(a->der)
    {
        p = a;
        a = a->der;
    }
    (*act)->dato = a->dato;
    if(p==(*act))
    {
        p->izq = a->izq;
    }
    else
    {
        p->der = a->der;
    }
    (*act) = a;
}





