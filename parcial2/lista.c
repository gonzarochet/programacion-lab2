//#include <stdio.h>
//#include <stdlib.h>
//#include "lista.h"
//
//nodo * iniciLista(){
//    return NULL;
//}
//
//nodo * crearNodo(COMPLETAR dato){
//    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
//    nuevo->dato = dato;
//    nuevo->siguiente = NULL;
//    return nuevo;
//}
//
//nodo * agregarAlPrincipio(nodo* lista, nodo* nuevo){
//    nuevo->siguiente = lista;
//    return nuevo;
//}
//
//void muestraLista(nodo* lista){
//    nodo* seg = lista;
//    while(seg!=NULL){
//        muestraNodo(seg);
//        seg=seg->siguiente;
//    }
//}
//
//void muestraNodo(nodo* n){
//    printf("\n Nodo: %p - Nodo siguiente: %p", n, n->siguiente);
//    COMPLETAR(n->dato);
//}
//
//nodo* buscarUltimo(nodo* lista){
//    nodo* seg = lista;
//    while(seg->siguiente != NULL){
//        seg = seg->siguiente;
//    }
//    return seg;
//}
//
//nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
//    if(!lista){
//        lista = nuevo;
//    }else{
//        nodo* ultimo = buscarUltimo(lista);
//        ultimo->siguiente = nuevo;
//    }
//
//    return lista;
//}
//
//nodo* agregarEnOrden(nodo* lista, nodo* nuevo){
//    if(!lista){
//        lista = nuevo;
//    }else{
//        if(nuevo->dato.COMPLETAR <= lista->dato.COMPLETAR){
//            lista = agregarAlPrincipio(lista, nuevo);
//        }else{
//            nodo* ante = lista;
//            nodo* seg = lista->siguiente;
//            while(seg && (nuevo->dato.COMPLETAR > seg->dato.COMPLETAR)){
//                ante = seg;
//                seg = seg->siguiente;
//            }
//            nuevo->siguiente = seg;
//            ante->siguiente = nuevo;
//        }
//    }
//    return lista;
//}


