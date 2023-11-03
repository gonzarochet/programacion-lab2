#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stPaciente dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, stPaciente dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.idPaciente > arbol->dato.idPaciente){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, dato);
        }
    }

    return arbol;
}

void preOrden(nodoArbol* arbol){
    if(arbol){
        mostrarPaciente(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbol* arbol){
    if(arbol){
        inOrden(arbol->izq);
        mostrarPaciente(arbol->dato);
        inOrden(arbol->der);
    }
}

void postOrden(nodoArbol* arbol){
    if(arbol){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        mostrarPaciente(arbol->dato);
    }
}

int buscaPaciente(nodoArbol * arbol,char nombre[], char apellido[]){

    int flag = 0;
    if(arbol){
            if(strcmp(arbol->dato.nombrePaciente,nombre) == 0 && strcmp(arbol->dato.apellidoPaciente,apellido) == 0){
                flag = 1;
            }else{
                flag = buscaPaciente(arbol->izq,nombre,apellido) ;
                if(flag == 0){
                   flag = buscaPaciente(arbol->der,nombre,apellido);
                }
            }
    }

    return flag;

}

int cuentaPacientes(nodoArbol * arbol){
    int cant = 0;
    if(arbol){
        cant = 1 + cuentaPacientes(arbol->izq) + cuentaPacientes(arbol->der);
    }
    return cant;
}

void arbol2Archi(nodoArbol * arbol , FILE * archi){

    if(arbol){
        arbol2Archi(arbol->izq,archi);
        fwrite(&arbol->dato,sizeof(stPaciente),1,archi);
        arbol2Archi(arbol->der,archi);
    }
}

