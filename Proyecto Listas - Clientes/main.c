#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "archivoClientes.h"
#include "listaSimpleClientes.h"
#include "registroArchivo.h"
#include "utilidades.h"
#include "gotoxy.h"
#include "listaDobleCliente.h"
#include "muestraMenu.h"
#include "tp1-Ejercicios.h"
#include "pilaClientes.h"
#include "fila.h"


// Prototipado de funciones con Listas Simples:
nodoSimpleClientes * arreglo2Lista(stCliente arreglo[], int validos, nodoSimpleClientes* lista);

// Prototipada de funciones con Listas Dobles:
nodoDobleCliente * arreglo2ListaDoble (stCliente arreglo[], int validos, nodoDobleCliente*lista);
nodoDobleCliente * buscaMenorDni (nodoDobleCliente * lista);
nodoDobleCliente * ordenarPorDNIListasDobles(nodoDobleCliente * lista);





int main()
{

    nodoSimpleClientes * listaClientes = inicLista();
    nodoSimpleClientes * listaClientesB = inicLista();
    nodoSimpleClientes * listaClientesC = inicLista();
    nodoSimpleClientes * listaVacia = inicLista();

    nodoDobleCliente *listaClientesDoble = inializarLista2();
   //nodoDobleCliente *menor = inializarLista2();
   // nodoDobleCliente *seleccion = inializarLista2();

   Pila pilaClientes;
   inicPila(&pilaClientes);

    char opcion;

    do
    {

        system("cls");

        // 1. Espacio para crear las variables...

        //int elementos=0;
        // char archivo[100] = "numeros.bin" ;

        stCliente arregloClientes[20];
        int validos =6;

        // 2. Muestra el printf con las opciones
        muestraMenu();

        //3. Elige la opcion el usuario.

        opcion=getch();

        //4. Codigos
        switch(opcion)
        {
        case 49://1
            generaArchivoRandom(5);
            muestraClientesArchivo("clientes.dat");
            break;
        case 50://2
            archivoClientes2Arreglo("clientes.dat",arregloClientes,0,validos);
            muestraClientesArreglo(arregloClientes,validos);
            break;
        case 51://3
            listaClientesDoble = arreglo2ListaDoble(arregloClientes,validos,listaClientesDoble);
            muestraLista2(listaClientesDoble);
            break;
        case 52://4
            archivo2listaSimpleOrdenadoPD("clientes.dat",&listaClientes);
            muestraLista(listaClientes);
            printf("\nAHORA SE PROCEDERA A elimianr los valores menores a los 10 millones\n");
            listaClientes = EliminarDniMenor10Millones(listaClientes,10000000);
            muestraLista(listaClientes);

            break;
        case 53://5
            archivo2listaSimpleOrdenadoPD("clientes.dat",&listaClientesB);
            listaClientesC = intercalarElementosOrdenadosListaSimplePD(listaClientes,listaClientesB,listaClientesC);
            muestraLista(listaClientesC);
        case 54://6
            printf("\n");
            listaClientesDoble = ordenarPorDNIListasDobles(listaClientesDoble);
            muestraLista2(listaClientesDoble);
           /* printf("\nAHORA SE PROCEDERA A ELIMINAR EL ULTIMO NODO\n");

            listaClientesDoble = borrarUltimoNodo2(listaClientesDoble);
            muestraLista2(listaClientesDoble);*/
            break;

        case 55://7
                Archi2PilaClientes("clientes.dat",&pilaClientes);
                muestraPila(&pilaClientes);

                printf("\nAHORA SE PROCEDERA A ELIMINAR EL ULTIMO NODO\n");

                PilaClientes2Lista(&pilaClientes,&listaVacia);
                printf("termine aqui\n");
                muestraLista(listaVacia);


            /* case 56:
                 int valor;
                 FILE * archi= fopen(archivo,"rb");
                 if(archi)
                 {
                     valor = menorArchivoRecursivo(archi);
                     fclose(archi);
                 }
                 printf("\nEl menor valor dentro del archivo es: %d\n", valor);
                 break;
             case 57:
                 elementos = cantidadElementosArchivo(archivo);
                 mostrarArchivo(archivo);
                 printf("\n\n");

                 FILE * archi = fopen(archivo,"ab");


                 if(archi)
                 {
                     invertirRegistrosArchivoRecur(archi,0,elementos);
                     fclose(archi);
                 }
                 mostrarArchivo(archivo);

                 break;
             case 97:
                 elementos = cantidadElementosArchivo(archivo);
                 mostrarArchivo(archivo);
                 printf("\n\n");

                 FILE * archi= fopen(archivo,"rb");


                 if(archi)
                 {
                     muestraArchivoInverRecursivo(archi,-1,elementos);
                     fclose(archi);
                 }

                 break;
             case 98:
                 mostrarArregloRecursivo(arreglo,validos,0);
                 break;
             case 99:
                 mostrarArregloRecursivo(arreglo,validos,0);
                 break;
             case 100:
                 mostrarArregloRecursivo(arreglo,validos,0);
                 break;*/

        }
        getch(); /// es una pausa

    }
    while(opcion!=27); /// 27 es el ESC. Mientras opcion sea distinta a 27.





    return 0;
}

// 1. De arreglo a Lista Simple.
nodoSimpleClientes * arreglo2Lista(stCliente arreglo[], int validos, nodoSimpleClientes* lista)
{
    for(int i=0; i<validos; i++)
    {
        lista = agregarPrincipio(lista,crearNodo(arreglo[i]));
    }

    return lista;
}
//2. De arreglo a lista Doble.
nodoDobleCliente * arreglo2ListaDoble (stCliente arreglo[], int validos, nodoDobleCliente*lista)
{
    for(int i=0; i<validos; i++)
    {
        lista = agregarPrincipio2(lista,crearNodo2(arreglo[i]));
    }
    return lista;
}

//3. Busca el nodo con menor dni de la lista
nodoDobleCliente * buscaMenorDni (nodoDobleCliente * lista)
{
    // stCliente menor;
    nodoDobleCliente* seg = lista;
    nodoDobleCliente * menorNodo = lista;

    if(lista)
    {
        seg = seg->siguiente;

        while(seg)
        {
            if(atoi(seg->dato.persona.dni) < atoi(menorNodo->dato.persona.dni))
            {
                menorNodo = seg;
            }
            seg = seg->siguiente;
        }
    }
    else
    {
        printf("\nLa lista esta vacia\n");
    }
    return menorNodo;
}

//4. Ordena una listaDoble por un parametro determinado -> DNI.
nodoDobleCliente *  ordenarPorDNIListasDobles(nodoDobleCliente * lista)
{
    nodoDobleCliente * posicionCurrent = lista;
    nodoDobleCliente * listaMenor = inializarLista2();


    if(!lista)
    {
        printf("\nla lista esta vacia\n");
    }
    else
    {
        while(posicionCurrent) // llegar hasta la anteultima posicion.
            {
                nodoDobleCliente * menor = buscaMenorDni(posicionCurrent);
                listaMenor = agregarEnOrdenDni2(listaMenor,crearNodo2(menor->dato));

                if(posicionCurrent->siguiente == NULL)
                {
                    posicionCurrent = borrarLista2(posicionCurrent);
                }
                else
                {
                    posicionCurrent = borrarNodo2ListaDni(posicionCurrent, menor->dato.persona.dni);
                }
            }

    }
    lista = listaMenor;

    return lista;
}




