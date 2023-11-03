#ifndef STPACIENTE_H_INCLUDED
#define STPACIENTE_H_INCLUDED

typedef struct
{
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];
} stPaciente;

void mostrarPaciente(stPaciente  p);
#endif // STPACIENTE_H_INCLUDED
