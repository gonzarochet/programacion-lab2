#include "ada.h"

int alta (stCelda ada[], int v, stEspecialidad e, stPaciente p)
{
    int pos = buscarPosicion(ada,v,e.especialidadMedica);
    if(pos==-1)
    {
        v = agregarEspecialidad(ada,v,e);
        pos = v-1;

    }
    ada[pos].arbol = agregarNodoArbol(ada[pos].arbol,p);
     printf("holaa");
    return v;
}

int buscarPosicion(stCelda ada[],int v, char nombreEspecialidad[]){
    int pos = -1;
    int i = 0;
    while(i<v && pos == -1){
        if(strcmp(ada[i].especialidad.especialidadMedica,nombreEspecialidad) == 0){
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarEspecialidad(stCelda ada[],int v, stEspecialidad e){
    ada[v].especialidad = e;
    ada[v].arbol = inicArbol();
    return v+1;
}

void mostrarCelda(stCelda c){
    printf("\n**********************************************\n");
    mostrarUnaEspecialidad(c.especialidad);
    printf("\n**********************************************\n");
    inOrden(c.arbol);
}
