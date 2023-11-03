 #include "stPaciente.h"

void mostrarPaciente(stPaciente  p)
{
    printf("IdPaciente.......: %d\n",p.idPaciente);
    printf("Nombre...........: %s\n",p.nombrePaciente);
    printf("Apellido.........: %s\n",p.apellidoPaciente);
    printf("Fecha de atencion: %s\n",p.fechaAtencion);
    printf("Diagnóstico......: %s\n",p.diagnostico);
    printf("Nombre Doctor....: %s\n",p.nombreDoctor);
}
