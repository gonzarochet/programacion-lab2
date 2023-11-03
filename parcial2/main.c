#include <stdio.h>
#include <stdlib.h>
#include "ada.h"
#include "registroArchivo.h"
#include "stPaciente.h"
#include "especialidad.h"
#include "arbol.h"
#include "string.h"

int archivo2ADA(char nombreArchivo[],stCelda ada[], int v, int dim);
stPaciente getPaciente(stRegistroMedico aux);
stEspecialidad getEspecialidad(stRegistroMedico aux);
void muestraADA(stCelda ada[],int v);
int busquedaPacienteEnEspecialidad(stCelda ada[], int v , char nombre[],char apellido[], char nombreEspecialidad[]);
void muestraCantidadAtencionesPorEspecialidad(stCelda ada[],int v);
void guardarArchivoEspecialidad(stCelda ada[], int v , char nombreEspecialidad[], char nombreArchivo[]);


int main()
{
    stCelda ada[10];
    int  v = 0;
    v = archivo2ADA("registroMedico.dat",ada,v,10);
    muestraADA(ada,v);
    printf("\n\n");
    muestraCantidadAtencionesPorEspecialidad(ada,v);
    guardarArchivoEspecialidad(ada,v,"Pediatria general","pediatria.dat");



    return 0;
}

int archivo2ADA(char nombreArchivo[],stCelda ada[], int v, int dim){
    FILE * archi = fopen(nombreArchivo,"rb");
    stRegistroMedico aux;

    if(archi){
        while(v < dim && fread(&aux,sizeof(stRegistroMedico),1,archi)){
            stPaciente p = getPaciente(aux);
            stEspecialidad esp = getEspecialidad(aux);
            v = alta(ada,v,esp,p);

        }
        fclose(archi);
    }

    return v;
}

stPaciente getPaciente(stRegistroMedico aux){
    stPaciente p;

    p.idPaciente = aux.idPaciente;
    strcpy(p.nombrePaciente,aux.nombrePaciente);
    strcpy(p.apellidoPaciente,aux.apellidoPaciente);
    strcpy(p.nombreDoctor,aux.nombreDoctor);
    strcpy(p.fechaAtencion,aux.fechaAtencion);
    strcpy(p.diagnostico,aux.diagnostico);

    return p;
}
stEspecialidad getEspecialidad(stRegistroMedico aux){
    stEspecialidad e;
    e.idEspecialidad = aux.idEspecialidad;
    strcpy(e.especialidadMedica,aux.especialidadMedica);
    return e;
}

void muestraADA(stCelda ada[],int v){

    for(int i = 0; i<v;i++){
        mostrarCelda(ada[i]);
    }
}



int busquedaPacienteEnEspecialidad(stCelda ada[], int v , char nombre[],char apellido[], char nombreEspecialidad[]){
    int bus = -1;
    int flag = 0;

    bus = buscarPosicion(ada,v,nombreEspecialidad);

    if(bus!= -1){
        flag = buscaPaciente(ada[bus].arbol,nombre,apellido);
    }

    return flag;

}


void muestraCantidadAtencionesPorEspecialidad(stCelda ada[],int v){

    for(int i = 0; i<v; i++){
        mostrarUnaEspecialidad(ada[i].especialidad);
        printf("Cantidad de consultas %d \n", cuentaPacientes(ada[i].arbol));

    }
}

void guardarArchivoEspecialidad(stCelda ada[], int v , char nombreEspecialidad[], char nombreArchivo[]){
    int bus = -1;
    bus = buscarPosicion(ada,v,nombreEspecialidad);

    if(bus!= -1){
        FILE * archi = fopen(nombreArchivo,"wb");
        arbol2Archi(ada[bus].arbol,archi);
    }

}



