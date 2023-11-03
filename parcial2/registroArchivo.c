#include "registroArchivo.h"

/// Se muestra un dato de tipo stRegistroMedico
void mostrarUnRegistro(stRegistroMedico r){
    printf("\n Id Registro.....................: %d",r.idRegistro);
    printf("\n Id Paciente.....................: %d",r.idPaciente);
    printf("\n Nombre paciente.................: %s",r.nombrePaciente);
    printf("\n Apellido paciente...............: %s",r.apellidoPaciente);
    printf("\n Diagnostico.....................: %s",r.diagnostico);
    printf("\n Fecha de Atencion...............: %s",r.fechaAtencion);
    printf("\n Id Especialidad.................: %d",r.idEspecialidad);
    printf("\n Especialidad medica.............: %s",r.especialidadMedica);
    printf("\n Nombre del medico...............: %s\n",r.nombreDoctor);

    printf("---------------------------------------------------------------------");
}

