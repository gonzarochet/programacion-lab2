#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    printf("Hello world!\n");

    int num = 5;
    int * pNum = NULL;
    pNum = &num;
    printf("pNum %d - pNum %p\n",*pNum,pNum);



//    stStudent student;
//    student = loadStudent();
//    showStudent(student);

    char * name = NULL;
    readString(&name);
    //printf("The value of name is %s, and the position is %p",name,name);
    printf("The value of name is %s, and the position is %p", name, (void *)name);


    return 0;
}
