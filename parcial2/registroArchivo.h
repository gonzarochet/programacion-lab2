#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

#define arRegistro "registroMedico.dat"

typedef struct{
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    int idEspecialidad;
    char especialidadMedica[30];
    char nombreDoctor[30];
} stRegistroMedico;

void mostrarUnRegistro(stRegistroMedico r);

#endif // REGISTROARCHIVO_H_INCLUDED
