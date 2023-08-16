#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"

typedef struct{
    char * firstName;
    char * lastName;
    char dni[12];
    int claification;
}stStudent;

stStudent loadStudent();
void readString(char ** string);
void showStudent(stStudent student);




#endif // STUDENT_H_INCLUDED
