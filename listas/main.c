#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alumno.h"
#include "string.h"
#include "nodoAlumno.h"


int main()
{
    printf("Hello world!\n");

    nodoAlumno * lista = inicLista();

    nodoAlumno * alumno = crearNodo(loadStudent());
    nodoAlumno * alumno2 = crearNodo(loadStudent());
    nodoAlumno * alumno3 = crearNodo(loadStudent());

    lista = agregarPrincipio(lista,alumno);
    lista = agregarPrincipio(lista,alumno2);
    lista = agregarPrincipio(lista,alumno3);

    printf("La lista es: -------!\n");
    muestraLista(lista);

    lista = invertirElementosLista(lista);
    printf(" \n La lista invertida es : -------!\n");
    muestraLista(lista);
    return 0;
}
