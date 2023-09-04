#include "alumno.h"
#include <conio.h>
#include "string.h"

stStudent loadStudent(){
    stStudent student;
    printf("Firstname student: \n");
    readString(&student.firstName);
    printf("LastName student: \n");
    readString(&student.lastName);
    printf("DNI student: \n");
    gets(student.dni);
    printf("Final Calification student: \n");
    scanf("%d",&student.claification);

    return student;
}


void readString(char ** string){

    char cad[100];
    gets(cad);

    *string = (char*) malloc((strlen(cad)+1)*sizeof(char));

    if(string){
        strcpy((*string),cad);
    }
}


void showStudent(stStudent student){
     printf("\n Firstname student: %s",student.firstName);
     printf("\n LastName student: %s",student.lastName);
     printf("\n DNI student: %s",student.dni);
     printf("\n Final Calification student: %d",student.claification);
}
