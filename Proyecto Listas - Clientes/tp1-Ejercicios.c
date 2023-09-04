
#include "tp1-Ejercicios.h"


// 1. Hacer un programa que lea de un archivo datos y los inserte en una lista.
nodoSimpleClientes * archivo2listaSimple (char archivo[], nodoSimpleClientes * lista)
{
    FILE * archi = fopen(archivo,"rb");

    stCliente aux;

    if(archi)
    {
        while(fread(&aux,sizeof(stCliente),1,archi)>0)
        {
            lista = agregarPrincipio(lista,crearNodo(aux));
        }
    }
    else
    {
        printf("\n No se pudo abrir el archivo\n");
    }
    return lista;
}

//1. Ahora con Punteros Dobles
void archivo2listaSimplePD (char archivo[], nodoSimpleClientes ** lista)
{
    FILE * archi = fopen(archivo,"rb");

    stCliente aux;

    if(archi)
    {
        while(fread(&aux,sizeof(stCliente),1,archi)>0)
        {
            (*lista) = agregarPrincipio((*lista),crearNodo(aux));
        }
    fclose(archi);
    }
    else
    {
        printf("\n No se pudo abrir el archivo\n");
    }
}
//2.Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.
void archivo2listaSimpleOrdenadoPD (char archivo[], nodoSimpleClientes ** lista)
{
    FILE * archi = fopen(archivo,"rb");
    stCliente aux;

    if(archi)
    {
        while(fread(&aux,sizeof(stCliente),1, archi)>0)
        {
            (*lista) = agregarEnOrdenDni((*lista),crearNodo(aux));
        }

    fclose(archi);

    }
}
//3.Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.
int buscaElementoEnListaSimplePD (nodoSimpleClientes ** lista, char apellido[30])
{
    int flag = 0;

    nodoSimpleClientes  * seg = (*lista);

    if(seg)
    {
        while(seg && flag ==0)
        {

            if(strcmp(seg->dato.persona.apellido,apellido)==0)
            {
                flag = 1;

            }
            else
            {
                seg = seg->siguiente;
            }
        }
    }

    return flag;
}
//4.Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
//  Se deben redireccionar los punteros, no se deben crear nuevos nodos.
nodoSimpleClientes * intercalarElementosOrdenadosListaSimplePD(nodoSimpleClientes * listaA, nodoSimpleClientes * listaB, nodoSimpleClientes * listaC)
{

    nodoSimpleClientes * aux;

    while((listaA) && (listaB))
    {
        if((atoi(listaA->dato.persona.dni)) < (atoi(listaB->dato.persona.dni)))
        {
            aux =listaA;
            listaA = listaA->siguiente;
            aux->siguiente = NULL;
            listaC = agregarFinalLista(listaC, aux);
        }
        else
        {
            aux = listaB;
            listaB= listaB->siguiente;
            aux->siguiente = NULL;
            listaC = agregarFinalLista(listaC, aux);
        }
    }

    if(listaA)
    {
        listaC = agregarFinalLista(listaC, listaA);
    }
    else
    {
        if(listaB)
        {
            listaC = agregarFinalLista(listaC, listaB);
        }
    }

    return listaC;
}
//6. Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)
nodoSimpleClientes * invertirElementosLista (nodoSimpleClientes * lista)
{
    nodoSimpleClientes * invertida = inicLista();
    nodoSimpleClientes * aux;

    while(lista)
    {
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL; // sirve para que pasar el nodo sin "nada"
        invertida = agregarPrincipio(invertida,aux);
    }

    return invertida;
}

//7. Utilizando el TDA Pila creado en el punto 5, cargar la pila con números enteros.
//Luego, recorrer dicha pila e insertar por orden de llegada (al final) en una lista simplemente enlazada aquellos números que sean pares.
//Cuidado, la función no debe perder la pila original, trabaje de forma tal que se conserven sus datos.

void Archi2PilaClientes(char archivo[], Pila* pilaClientes)
{
    FILE *archi = fopen(archivo,"rb");
    stCliente aux;

    if(archi)
    {
        while(fread(&aux,sizeof(stCliente),1, archi)>0)
        {
            apilarClientePila(pilaClientes,aux);
        }

    fclose(archi);
    }
    else
    {
        printf("\n No se ha podido abrir el archivo\n");
    }

}


void PilaClientes2Lista(Pila* PilaClientes, nodoSimpleClientes ** lista)
{
   Pila aux;
   inicLista(&aux);

   stCliente cliente;

    while(!pilavacia(PilaClientes))
    {
       cliente = topePilaCliente(PilaClientes);

        if((atoi(cliente.persona.dni))%2==0)
        {
           (*lista) = agregarFinalLista((*lista),crearNodo(cliente));
        }
        apilarClientePila(&aux,desapilarClientePila(PilaClientes));
    }

    while(!pilavacia(&aux)){

       apilarClientePila(PilaClientes,desapilarClientePila(&aux));
    }

}


void muestraPila(Pila * p)
{
    Pila aux;
    inicPila(&aux);


    while(!pilavacia(p))
    {
        muestraUnCliente(topePilaCliente(p));
        apilarClientePila(&aux, desapilarClientePila(p));
    }

    while(!pilavacia(&aux))
    {
        apilarClientePila(p, desapilarClientePila(&aux));
    }


}


//8.Eliminar de la lista cargada en el ejercicio anterior, aquellos nodos que contengan valores menores a 10000000.
nodoSimpleClientes * EliminarDniMenor10Millones (nodoSimpleClientes * lista, int parametro)
{
    nodoSimpleClientes * seg;
    nodoSimpleClientes * aux;
    nodoSimpleClientes * ante;


    if(lista)
    {
       while(lista && (atoi(lista->dato.persona.dni) < parametro))
       {
           aux = lista;
           lista = lista->siguiente;
           free(aux);
       }

       seg = lista->siguiente;
       ante = lista;

       while(seg)
       {
           if(atoi(seg->dato.persona.dni) < parametro)
           {
               aux = seg;
               ante->siguiente = seg->siguiente;
               seg = seg->siguiente;
               free(aux);
           }
           else
           {
               ante = seg;
               seg = seg->siguiente;
           }
       }
    }

    return lista;
}










