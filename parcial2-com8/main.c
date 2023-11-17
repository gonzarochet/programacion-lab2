#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

#include "listaEquipo.h"
#include "jugador.h"
#include "equipo.h"
#include "jugadorEquipo.h"



nodoEquipo * archivo2LDL(char nombreArchivo[],nodoEquipo * ldl);
nodoEquipo * agregarJugadores(nodoEquipo * ldl);
int arrayDejugadoresGoleadoresPorEquipo(nodoEquipo * ldl, stJugador ** arreglo);
void mostrarArreglo(stJugador arreglo[], int v);
void pasarDeEstructuraCompuestaAlArchivo (nodoEquipo * ldl , int nroCamiseta);
void mostrarArchivoJugadoresEquipo(char nombreArchivo[]);

int main()
{
    /// 1.
    nodoEquipo * ldl = inicListaEquipo();

    /// 2.
    ldl = archivo2LDL("registrojugador.dat",ldl);

    /// 3.
    //ldl = agregarJugadores(ldl);

    /// 4.
    mostrarListaEquipos(ldl);

    /// 5.
    stJugador  * arreglo = NULL;

    int v = arrayDejugadoresGoleadoresPorEquipo(ldl,&arreglo);
    mostrarArreglo(arreglo,v);

    /// 6.

    float p = porcentajeRepresentaUnEquipo(ldl,3);
    printf("\nEl porcentaje que representa el idEquipo 3 es de %.2f \n",p);

    /// 7.
    pasarDeEstructuraCompuestaAlArchivo(ldl,10);
    mostrarArchivoJugadoresEquipo("10.dat");




    return 0;
}


/***

2- Utilizando el archivo que se le entregó,
hacer una función que permita pasar todos los elementos desde el origen de datos
(archivo) a la estructura compuesta según corresponda,
invocando la/las funciones necesarias para lograrlo.

***/

nodoEquipo * archivo2LDL(char nombreArchivo[],nodoEquipo * ldl){
    FILE * archi = fopen(nombreArchivo,"rb");
    stJugadorEquipo aux;

    if(archi){
        while(fread(&aux,sizeof(stJugadorEquipo),1,archi)){
            stJugador j = getJugador(aux);
            stEquipo e = getEquipo(aux);
            ldl = alta(ldl,e,j);
        }

    }
    return ldl;
}

/***
3- Realizar las funciones necesarias para realizar el ALTA de jugadores al sistema.
Esta función debe interactuar con el usuario, solicitando la información para generar un nuevo registro en la estructura compuesta.
Cargará datos mientras el usuario así lo requiera.
Si el equipo no existe, deberá agregarlo.
**/

nodoEquipo * agregarJugadores(nodoEquipo * ldl){

    stJugador nuevoJug;
    stEquipo equi;
    int idEquipo;

    char option = 's';

    while(option=='s'){


    printf("\n Ingrese el ID  JUGADOR: ");
    scanf("%d",&nuevoJug.idJugador); // falta la verificación de univocidad.

    printf("\n Ingrese el NOMBRE del jugador:");
    fflush(stdin);
    gets(nuevoJug.nombreJugador);

    printf("\n Ingrese el DORSAL de la camiseta: ");
    scanf("%d",&nuevoJug.nroCamisetaJugador);

    printf("\n Ingrese los PUNTOS anotados: ");
    scanf("%d",&nuevoJug.puntosAnotados);

    printf("\n Ingrese el ID del EQUIPO al que pertenece: ");
    scanf("%d",&idEquipo);

    nodoEquipo * equipo = buscarEquipo(ldl,idEquipo);

    mostrarEquipo(equipo->dato);

    if(!equipo){

        printf("\n El equipo NO existe. Ingrese los datos necesarios para continuar\n");

        printf("\n Ingrese el NOMBRE del equipo:");
        fflush(stdin);
        gets(equi.nombreEquipo);

        printf("\n Ingrese el ID Equipo: ");
        scanf("%d",&equi.idEquipo); // falta la verificación de univocidad.

        equipo = crearNodoEquipo(equi);

    }

    nuevoJug.idEquipo = equipo->dato.idEquipo;

    ldl = alta(ldl,equipo->dato,nuevoJug);

    printf("\n Si desea continuar agregando jugadores, presione 's', sino cualquier otra tecla \n");
    option = getch();
    }



    return ldl;

}

/***
5- Realizar una función que pase a un arreglo de jugadores a los goleadores de cada equipo.
En el caso de haber 2 jugadores con el mismo puntaje seleccionar el que tenga el número de camiseta más alto.
Mostrar el arreglo de goleadores en el main()
Datos a mostrar: id jugador, nombre del jugador, cantidad de puntos anotados y número de camiseta.
***/


int arrayDejugadoresGoleadoresPorEquipo(nodoEquipo * ldl, stJugador ** arreglo){

    int v = cuentaEquipos(ldl);
    (*arreglo) = malloc(sizeof(stJugador)*v);

    for(int i = 0; i<v && ldl; i++){
        (*arreglo)[i] = jugadorGoleador(ldl->listaJugadores);
        ldl = ldl->sig;

    }

    return v;

}

void mostrarArreglo(stJugador arreglo[], int v){
    for(int i = 0; i<v;i++){
        mostrarJugador(arreglo[i]);
    }
}



/***
7- Realizar una función (o varias) que pase todos los jugadores del torneo que tengan un determinado
número de camiseta a un archivo binario y los guarde.
Desarrollar la función principal con el siguiente prototipado:
void pasarDeEstructuraCompuestaAlArchivo (estructuraCompuesta , nro de camiseta).
El archivo saliente debe ser del tipo stJugadorEquipo
***/
void pasarDeEstructuraCompuestaAlArchivo (nodoEquipo * ldl , int nroCamiseta){

    char nombreArchivo[10];

    itoa(nroCamiseta,nombreArchivo,10);

    FILE * archi = fopen(strcat(nombreArchivo,".dat"),"wb");

    stJugadorEquipo registro;
    stJugador jugAux;

    if(archi){
            while(ldl){
                jugAux = buscarJugadorXCamiseta(ldl->listaJugadores,nroCamiseta);
                if(jugAux.idJugador!=-1) // solo escribe si el jugador con ese nro de camiseta existe
                {

                    // se podria modularizar
                    registro.idEquipo = ldl->dato.idEquipo;
                    strcpy(registro.nombreEquipo, ldl->dato.nombreEquipo);
                    strcpy(registro.nombreJugador, jugAux.nombreJugador);
                    registro.idJugador = jugAux.idJugador;
                    registro.nroCamisetaJugador = jugAux.nroCamisetaJugador;
                    registro.puntosAnotados = jugAux.puntosAnotados;

                    fwrite(&registro,sizeof(stJugadorEquipo),1,archi);


                }

                ldl = ldl->sig;
            }
        fclose(archi);
    }else{
        printf("NO SE ABRIO");
    }

}
void mostrarArchivoJugadoresEquipo(char nombreArchivo[]){

    stJugadorEquipo r;
    FILE * archi = fopen(nombreArchivo,"rb");

    if(archi){
        while(fread(&r,sizeof(stJugadorEquipo),1,archi)){
            mostrarJugadorEquipo(r);
            printf("\n");
        }
        fclose(archi);
    }
}



