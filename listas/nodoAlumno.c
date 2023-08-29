#include "nodoAlumno.h"
#include "alumno.h"



nodoAlumno * inicLista(){
    return NULL;
}

nodoAlumno * crearNodo(stStudent student){
    nodoAlumno * nuevo = (nodoAlumno * )malloc(sizeof(nodoAlumno));
    nuevo->dato = student;
    nuevo->sig = NULL;
    return nuevo;
}

nodoAlumno * agregarPrincipio(nodoAlumno * lista, nodoAlumno * nuevoNodo){
    nuevoNodo->sig = lista;
    return nuevoNodo;
}

void muestraNodo(nodoAlumno * nodo){
    printf("\n Nodo: %p", n);
    showStudent(nodo->dato);
    printf("\n Nodo->sig: %p", n->siguiente);

}

void muestraLista(nodoAlumno * lista){
    while(lista){
        muestraNodo(lista);
        lista = lista->sig;
    }

}

void muestraListaRecursiva(nodoAlumno * lista){
    if(lista){
    muestraNodo(lista);
       muestraLista(lista->sig);
    }

}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente != NULL){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

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
}

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


