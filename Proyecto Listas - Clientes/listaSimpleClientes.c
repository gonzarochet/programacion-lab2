#include "listaSimpleClientes.h"


/*********************************************************//**
*
* \brief Inicializa la lista
* \param -
* \return  Puntero de tipo Nodo - NULL
*
***********************************************************/
nodoSimpleClientes* inicLista()
{
    return NULL; // inicializa la lista, el puntero del primer nodo de la lista lo inicializa con NULL.
}

/*********************************************************//**
*
* \brief Crea un Nodo.
* \param  stCliente  - El cliente a agregar al Nodo.
* \return Puntero de tipo Nodo - Retorna el puntero a la direccion de memoria del primer elemento de ese nodo.
*
***********************************************************/
nodoSimpleClientes * crearNodo(stCliente clienteAgregar)
{
    nodoSimpleClientes * aux = (nodoSimpleClientes*) malloc(sizeof(nodoSimpleClientes));
    // crea un puntero de tipo nodo de manera dinamica.

    aux->dato = clienteAgregar; // le asigan los campos de información que recibio la funcion al puntero del nodo.

    aux->siguiente = NULL; // asigna el valor NULL al campo que contiene la siguiente direccion de memoria.

    return aux; // retorna el puntero al nodo creado, es decir la dirección de memoria, que deberá ser asiganada a auna variable de tipo "puntero a nodo".

}

stCliente verPrimerNodo (nodoSimpleClientes * lista)
{
    return lista->dato;
}



/*********************************************************//**
*
* \brief  Agrega un Nodo al Principio.
* \param  nodoSimpleClientes - La lista donde se van a incluir el nuevo nodo.
* \param  nodoSimpleClientes - El nuevo nodo a agregar.
* \return Puntero de tipo Nodo - Retorna la lista.
*
***********************************************************/
nodoSimpleClientes * agregarPrincipio(nodoSimpleClientes* lista, nodoSimpleClientes* nuevoNodo)
{
    if(lista==NULL)  // si la lista es igual a NULL
    {
        lista = nuevoNodo; // La lista *"apunta"* a la direccion de memoria del nuevo nodo.
    }
    else{
         nuevoNodo->siguiente = lista; // el nuevo nodo va a apuntar a la direccion de memoria que apunta lista.

         lista = nuevoNodo; // la lista apunta a la direccion de memoria del nuevo nodo.
    }

    return lista; // retorna la nueva posicion de memoria donde empieza la lista.
}

/*********************************************************//**
*
* \brief  Busca el ultimo nodo en una colección.
* \param  nodoSimpleClientes - La lista donde se van a incluir el nuevo nodo.
* \return Puntero de tipo Nodo - Retrona el puntero a la direccion de memoria del primer elemento de ese nodo.
*
***********************************************************/
nodoSimpleClientes * buscarUltimoNodo(nodoSimpleClientes *lista)
{
    nodoSimpleClientes*seg = lista; // seg es una variable local, donde se guarda la direccion de memoria del primer nodo de la lista.

    if(seg) // si seg no es NULL.
    {
        while(seg->siguiente!=NULL) // seg va tomando la direccion del nodo siguiente.
        {
            seg = seg->siguiente; // este es el incremento de la variable, se avanza en el recorrido secuencial de la lista.
        }
    }
    return seg; // se retorna la direccion de memoria del último nodo de la lista.
}


/*********************************************************//**
*
* \brief  Agrega un Nodo al Final de la lista.
* \param  nodoSimpleClientes - La lista donde se van a incluir el nuevo nodo.
* \param  nodoSimpleClientes - El nuevo nodo a agregar.
* \return Puntero de tipo Nodo - Retorna la lista.
*
***********************************************************/
nodoSimpleClientes * agregarFinalLista(nodoSimpleClientes * lista, nodoSimpleClientes * nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;

    }
    else
    {
        nodoSimpleClientes* ultimo  = buscarUltimoNodo(lista);// ultimo contiene la direccion de memoria del ultimo nodo de la lista.
        ultimo->siguiente = nuevoNodo;  // inicialmente este apunta a null y ahora, apunta a la direccion de memoria del nuevoNodo.
    }

    return lista;
}


/*********************************************************//**
*
* \brief  Muestra 1 Nodo de tipo cliente.
* \param  nodoSimpleClientes - El nuevo nodo a leer.
* \return Sin retorno - VOID.
*
***********************************************************/
void muestraNodo (nodoSimpleClientes * nodoLeer)
{
    printf("\n nodoLeer: %p - nodoSiguiente: %p",nodoLeer, nodoLeer->siguiente);
    muestraUnCliente(nodoLeer->dato);
}

/*********************************************************//**
*
* \brief  Muestra un alista de clientes.
* \param  nodoSimpleClientes - La lista donde se van a leer los nodos.
* \return Sin retorno - VOID.
*
***********************************************************/
void muestraLista(nodoSimpleClientes*lista)
{
    nodoSimpleClientes * aux = lista; // resguardar el puntero a la direccion de memoria del primer elemento de la lista.

    while(aux)
    {
         muestraNodo(aux); // lee el nodo en cuestion.
         aux = aux->siguiente; // generador de movimiento.
    }
}


/*********************************************************//**
*
* \brief  Busca un Nodo en una lista por medio del nombre.
* \param  nodoSimpleClientes - La lista donde se van a incluir el nuevo nodo.
* \param  char - el nombre a buscar.
* \return nodoSimpleCLiente - retorna el nodo donde se encontro el nombre.
*
***********************************************************/
nodoSimpleClientes * buscarNodoxNombreCli(nodoSimpleClientes * lista, char nombre[20])
{
   nodoSimpleClientes * seg = lista;

   while(seg && (strcmp(seg->dato.persona.nombre, nombre)!=0))
   {
       seg=seg->siguiente;
   }
   return seg;
}

/*********************************************************//**
*
* \brief  Agrega un nodo en orden segun el DNI.
* \param  nodoSimpleClientes - La lista donde se van a incluir el nuevo nodo.
* \param  nodoSimpleClientes - El nodo a agregar.
* \return nodoSimpleCLientes - Retorna la lista con el nodo ya incluido.
*
***********************************************************/
nodoSimpleClientes * agregarEnOrdenDni (nodoSimpleClientes * lista, nodoSimpleClientes * nodoAgregar)
{
    if(!lista)
    {
        lista = nodoAgregar;
    }
    else{
        if(atoi(nodoAgregar->dato.persona.dni) < atoi(lista->dato.persona.dni)) // si el nuevo elemento es menor al primer nodo.
        {
           lista = agregarPrincipio(lista,nodoAgregar);
        }
        else
        {
            nodoSimpleClientes * ante = lista; // guarda la direccion de memoria de la posicion actual.
            nodoSimpleClientes * seg = lista->siguiente; // salteo la posición primera

            while(seg && (atoi(nodoAgregar->dato.persona.dni) > atoi(seg->dato.persona.dni)))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            // insertar el nuevo nodo en el lugar indicado.
            nodoAgregar->siguiente = seg;
            ante->siguiente = nodoAgregar;
        }
    }
    return lista;

}


nodoSimpleClientes * borrarNodoListaApellido (nodoSimpleClientes * lista , char apellido[20])
{
   nodoSimpleClientes * seg;
   nodoSimpleClientes * ante;

   if(lista && (strcmp(lista->dato.persona.apellido,apellido)==0))
   {
       nodoSimpleClientes * aux = lista;
       lista = lista->siguiente; // salteo el primer nodo.
       free(aux); // elimino el primer nodo.
   }
   else
    {
        seg = lista;
        while(seg && (strcmp(seg->dato.persona.apellido,apellido)!=0))
        {
            ante = seg; // adelanto una posicion la variable ante.
            seg = seg->siguiente; // avanzo al siguiente nodo.
        }
        if(seg)
        {
            ante->siguiente = seg->siguiente; // salteo el nodo que quiero eliminar
            free(seg); // elimino el nodo.
        }
   }
    return lista;
}

/*********************************************************//**
*
* \brief  Cuenta nodos en la lista.
* \param  nodoSimpleClientes - La lista donde se va a hacer el conteo.
* \return Int - La cantidad de nodos leidos.
*
***********************************************************/
int cuentaNodosEnLista (nodoSimpleClientes * lista)
{
    nodoSimpleClientes * aux =lista;
    int i=0;

    while(aux){
        i++;
        aux = aux->siguiente;
    }
    return i;
}

/*********************************************************//**
*
* \brief  Borrar Nodos de la lista.
* \param  nodoSimpleClientes - La listaque se va a eliminar.
* \return nodoSimpleClientes - Se retorna NULL (si la lista se elimino correctamente).
*
***********************************************************/

nodoSimpleClientes * borrarLista (nodoSimpleClientes* lista)
{
    nodoSimpleClientes* proximo;
    nodoSimpleClientes*seg = lista;

    while(seg)
    {
        proximo = seg->siguiente; // tomo la direccion del siguiente nodo.
        free(seg); // elimino el nodo actual, es decir, libero la memoria.
        seg = proximo; // me muevo al siguiente nodo.
    }
    return seg;
}


/*********************************************************//**
*
* \brief  Borrar Ultimo nodo de la lista.
* \param  nodoSimpleClientes - La lista donde se va a realizar la eliminacion del ultimo nodo.
* \return nodoSimpleClientes - Se retorna la lista.
*
***********************************************************/

nodoSimpleClientes * borrarUltimoNodo(nodoSimpleClientes * lista)
{

    nodoSimpleClientes * aux = lista;
    nodoSimpleClientes * ante;

       while(aux->siguiente)
        {
          ante = aux; // guarda en ante la posicion actual.
          aux = aux->siguiente;
        }
        free(aux);
        ante->siguiente = NULL;

    return lista;
}


/*********************************************************//**
*
* \brief  Borrar el primer nodo de la lista.
* \param  nodoSimpleClientes - La lista donde se va a realizar la eliminacion del primer nodo.
* \return nodoSimpleClientes - Se retorna la lista.
*
***********************************************************/
nodoSimpleClientes * borrarPrimerNodo(nodoSimpleClientes * lista)
{
    nodoSimpleClientes * aux = lista; // en aux se iguala a la primera posicion que apunta lista.
    lista = lista->siguiente; // lista ahora apunta a la direcion de memoria de siguiente
    free(aux); // se libera la memoria.
    return lista;
}
