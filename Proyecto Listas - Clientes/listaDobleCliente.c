#include "listaDobleCliente.h"


// 1. Inicializa la lista
nodoDobleCliente* inializarLista2()
{
    return NULL;
}


//2. Crear Nodo Doble
nodoDobleCliente* crearNodo2(stCliente dato)
{
    nodoDobleCliente* nuevo = (nodoDobleCliente*) malloc(sizeof(nodoDobleCliente));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}


//3. Agregar Nodo al Principio de una lista.
nodoDobleCliente * agregarPrincipio2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar)
{
    if(lista == NULL)
    {
        lista = nodoAgregar;
    }
    else
    {
        lista->anterior = nodoAgregar; // el ex primer nodo de la lista, hacemos que anterior apunte al nodo que vamo a poner como primero.
        nodoAgregar->siguiente = lista; // el nuevo nodo que vamos a poner como primero, igualamos siguiente al ex primer nodo de la lista.
        lista = nodoAgregar; // igualamos el nuevo nodo al principio de la lista.
    }
    return lista; // retornamos "lista" que es la direccion de memoria del primer nodo, es decir, el que creamos recién.
}


//4. Agregar un Nodo en Orden por DNI en lista doble.
nodoDobleCliente * agregarEnOrdenDni2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar)
{
    if(!lista)
    {
        lista = nodoAgregar;
    }
    else
    {
        if((atoi(nodoAgregar->dato.persona.dni)) < (atoi(lista->dato.persona.dni)))
        {
            lista = agregarPrincipio2(lista,nodoAgregar);

        }
        else
        {
            nodoDobleCliente * seg = lista->siguiente; // salteo el primer nodo.
            nodoDobleCliente * ante = lista;


               while(seg && (atoi(seg->dato.persona.dni)) < (atoi(nodoAgregar->dato.persona.dni)))
                {
                    ante = seg; //ante igual a seg
                    seg = seg->siguiente; // avanzo una en la posicion de seg.

                }

                nodoAgregar->siguiente = seg;
                ante->siguiente = nodoAgregar;
                nodoAgregar->anterior = ante; // se agrega esta linea adcional en listas dobles.

            }

    }
    return lista;
}

//5. Agregar un Nodo al Final de la lista
nodoDobleCliente * agregarFinalLista2(nodoDobleCliente * lista, nodoDobleCliente * nodoAgregar)
{
    if(lista==NULL)
    {
        lista = nodoAgregar;
    }
    else
    {
        nodoDobleCliente * ultimo = buscarUltimoNodo2(lista); // busco el ultimo nodo.
        ultimo->siguiente = nodoAgregar; // siguiente del ultimo nodo la igualo al nuevo nodo que quiero poner como ultimos.
        nodoAgregar->anterior = ultimo; // el anterior del nuevo nodo a agregar la igualo al nodoq que antes era el ultimo.
    }
    return lista;
}


//6. Muestra un Nodo Y Muestra una lista de Nodos Dobles.
void muestraNodo2(nodoDobleCliente * nodo)
{

    printf("\n Nodo: %p - nodo->anterior: %p - nodo->siguiente: %p", nodo, nodo->anterior, nodo->siguiente);
    muestraUnCliente(nodo->dato);
}

void muestraLista2(nodoDobleCliente * lista)
{
    nodoDobleCliente * seg  = lista;

    while(seg)
    {
        muestraNodo2(seg);
        seg = seg->siguiente;
    }

}
//7. Ve el primer nodo de una lista DOBLE.
stCliente verPrimerNodo2(nodoDobleCliente * lista)
{
    return lista->dato;
}

//8. Busca un nodo por DNI en una lista DOBLE.
nodoDobleCliente * buscaNodoxDni2(nodoDobleCliente* lista, char dni[10])
{
    nodoDobleCliente* seg = lista;

    while(seg && (atoi(seg->dato.persona.dni)) != (atoi(dni)))
    {
        seg = seg->siguiente;
    }

   return seg;

}


//9. Busca el Último Nodo de una lista DOBLE.
nodoDobleCliente * buscarUltimoNodo2(nodoDobleCliente * lista)
{
    nodoDobleCliente * seg = lista;

    while(seg->siguiente) // parametro para recorrer la lista, hasta antes del ultimo
    {
        seg = seg->siguiente; // el incremento de seg
    }

    return seg; // se debuto el ciclo justo antes del ultimo y se retorna la direccion de memoria del ultimo.
}



//10. Borrar el Primer Nodo de una lista.
nodoDobleCliente * borraPrimerNodoLista2(nodoDobleCliente * lista)
{
   nodoDobleCliente * seg;

   if(lista)
   {
        seg = lista->siguiente;
        seg->anterior = NULL;
        free(lista);
   }
    return seg;
}

nodoDobleCliente * borraPrimerNodoLista2Version2(nodoDobleCliente * lista)
{
    if(lista)
    {
        nodoDobleCliente * aux = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        free(aux);
    }

    return lista;

}

//11. Borrar un Nodo definido por DNI de una lista.
nodoDobleCliente * borrarNodo2ListaDni (nodoDobleCliente* lista, char dni[10])
{
    nodoDobleCliente * seg;
    // nodoDobleCliente * current;
    nodoDobleCliente * ante;

    if(lista->siguiente)
    {
        if(atoi(lista->dato.persona.dni) == atoi(dni))// si el primer nodo es el que se quiere eliminar.
        {
            nodoDobleCliente * aux = lista; // la direccion de memoria del primer nodo se guarda en aux.
            lista = lista->siguiente; // salteo el primer nodo.
            lista->anterior = NULL; // anterior lo igualo a null.
            free(aux); // elimino el primer nodo.
        }
        else
        {
            seg = lista;

            while(seg && (atoi(seg->dato.persona.dni) != atoi(dni)))
            {
                ante = seg; // adelanto una posicion la variable ante.
                seg = seg->siguiente; // avanzo al siguiente nodo.
            }
            if(seg) // si seg tiene datos.
            {
                ante->siguiente = seg->siguiente; // salteo el nodo que quiero eliminar
                seg->siguiente = ante; // el nodo seg->siguiente lo igualo, es decir que anterior apunta a ante.
                free(seg); // elimino el nodo.
            }
        }
    }
    return lista;
}


//12. Borrar el Último Nodo de una lista.
nodoDobleCliente * borrarUltimoNodo2(nodoDobleCliente * lista)
{
    nodoDobleCliente * seg = lista;
    nodoDobleCliente * ante;


    while(seg->siguiente)
    {
        ante = seg;
        seg = seg->siguiente;
    }
    free(seg);
    ante->siguiente = NULL;

    return lista;

}


//13. Borrar una Lista de Nodos Dobles COMPLETA.
nodoDobleCliente * borrarLista2 (nodoDobleCliente* lista)
{
    nodoDobleCliente * proximo;
    nodoDobleCliente *seg = lista;

    while(seg)
    {
        proximo = seg->siguiente; // tomo la direccion del siguiente nodo.
        free(seg); // elimino el nodo actual, es decir, libero la memoria.
        seg = proximo; // me muevo al siguiente nodo.
    }
    return seg;
}




