#include "nodoAlumno.h"
#include "alumno.h"



nodoAlumno * inicLista()
{
    return NULL;
}

nodoAlumno * crearNodo(stStudent student)
{
    nodoAlumno * nuevo = (nodoAlumno * )malloc(sizeof(nodoAlumno));
    nuevo->dato = student;
    nuevo->sig = NULL;
    return nuevo;
}

nodoAlumno * agregarPrincipio(nodoAlumno * lista, nodoAlumno * nuevoNodo)
{
    nuevoNodo->sig = lista;
    return nuevoNodo;
}

void muestraNodo(nodoAlumno * nodo)
{
    printf("\n Nodo: %p", nodo);
    showStudent(nodo->dato);
    printf("\n Nodo->sig: %p", nodo->sig);

}

void muestraLista(nodoAlumno * lista)
{
    while(lista)
    {
        muestraNodo(lista);
        lista = lista->sig;
    }

}

void muestraListaRecursiva(nodoAlumno * lista)
{
    if(lista)
    {
        muestraNodo(lista);
        muestraLista(lista->sig);
    }

}

nodoAlumno* buscarUltimo(nodoAlumno* lista)
{
    nodoAlumno * seg = lista;
    while(seg->sig != NULL)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoAlumno* agregarAlFinal(nodoAlumno* lista, nodoAlumno* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoAlumno* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}


nodoAlumno * agregarEnOrdenDNI(nodoAlumno * lista, nodoAlumno * nuevo)
{

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoAlumno * aux = lista; // ante
        if(atoi(aux->dato.dni) > atoi(nuevo->dato.dni))
        {
            agregarPrincipio(aux,nuevo);
            lista = aux;
        }
        else
        {
            nodoAlumno * seg = lista;

            while(seg && atoi(aux->dato.dni) < atoi(nuevo->dato.dni))
            {
                aux = seg;
                seg = seg->sig;
            }

            aux->sig = nuevo;
            nuevo->sig = seg;


        }

    }

    return lista;

}

///  4. Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
///  Se deben redireccionar los punteros, no se deben crear nuevos nodos.

nodoAlumno * intercalarListasOrden(nodoAlumno * listaA, nodoAlumno * listaB)
{

    nodoAlumno * listaResultante = inicLista();
    nodoAlumno * aux = NULL;

    while(listaA && listaB)
    {
        if(listaA->dato.dni < listaB->dato.dni)
        {
            aux = listaA;
            listaA = listaA->sig;
        }
        else
        {
            aux = listaB;
            listaB = listaB->sig;
        }

        aux->sig = NULL;
        agregarAlFinal(listaResultante,aux);
    }

    if(listaA)
    {
        agregarAlFinal(listaResultante,listaA);
    }
    else if(listaB)
    {
        agregarAlFinal(listaResultante,listaB);
    }
    return listaResultante;

}

/// 5. Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)
nodoAlumno *  invertirElementosLista(nodoAlumno * lista)
{

    if(lista)
    {
        nodoAlumno * aux = NULL;
        nodoAlumno * ante = lista;
        nodoAlumno * seg = lista;

        ante->sig = NULL;

        while(seg->sig)
        {
            aux = seg->sig;
            seg->sig = ante;
            ante = seg;
            seg = aux;
        }

        return seg;
    }
}

nodoAlumno* invertirElementosLista2(nodoAlumno* lista)
{
    if (lista)
    {
        nodoAlumno* anterior = NULL;
        nodoAlumno* actual = lista;
        nodoAlumno* siguiente = NULL;

        while (actual)
        {
            siguiente = actual->sig; // Guarda el siguiente nodo
            actual->sig = anterior; // Cambia el puntero al siguiente nodo

            // Mueve los punteros a la siguiente posición
            anterior = actual;
            actual = siguiente;
        }

        return anterior; // El último nodo se convierte en la nueva cabeza de la lista invertida
    }

    return NULL; // Devuelve NULL si la lista original estaba vacía
}
















/*
nodo* agregarEnOrdenPorEdad(nodo* lista, nodo* nuevo){
    /// Si la lista esta vacia le asigno el nuevo nodo
    if(!lista){
        lista = nuevo;
    }else{
        /// si el nuevo nodo es menor al primero de la lista, agrego a principio
        if(nuevo->dato.edad <= lista->dato.edad){
            lista = agregarAlPpio(lista, nuevo);
        }else{
            /// buscamos el lugar donde insertar
            nodo* ante = lista;
            nodo* seg = lista;
            while(seg && (nuevo->dato.edad > seg->dato.edad)){
                ante = seg;
                seg = seg->siguiente;
            }
            /// insertar el nuevo nodo en la lista de manera ordenada
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}*/
/*
nodo* intercalarListas(nodo* listaA, nodo* listaB, nodo* listaFinal){
   nodo* aux = NULL;
   while(listaA && listaB){ /// while(listaA != NULL && listaB != NULL)
       if(listaA->dato.edad < listaB->dato.edad){
           aux = listaA;
           listaA = listaA->siguiente;
       }else{
           aux = listaB;
           listaB = listaB->siguiente;
       }
       aux->siguiente = NULL;
       listaFinal = agregarAlFinal(listaFinal, aux);
   }
   if(listaA){
       listaFinal = agregarAlFinal(listaFinal, listaA);
   }else if(listaB){
       listaFinal = agregarAlFinal(listaFinal, listaB);
   }


   return listaFinal;
}
*/

