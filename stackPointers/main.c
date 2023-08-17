#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "stack.h"

int main()
{
    printf("Hello world!\n");

    int num = 5;
    int * pNum = NULL;
    pNum = &num;
    printf("pNum %d - pNum %p\n",*pNum,pNum);

    stStudent student; // genero el student
    student = loadStudent(); // lo carg con informacion


    StackStudent s; // creo la pila

    initStack(&s); // incializo la pila

    pushStack(&s,student); // agrego elementos a la pila
    pushStack(&s,student);


    printf(" \nDESDE LA pila \n");
    showStack(&s); // muestro desde la pila

    stStudent * array = NULL;
    array = (stStudent*) malloc(sizeof(stStudent)*5); // genero el array dinámico

    int v = stackStudentToArray(&s,&array,5); // modifico el array pasandole los datos de la pila




    printf(" \nDesde el arreglo \n");
    for(int i = 0; i<v;i++){
        showStudent(array[i]);
    }

     printf(" \nDesde el la pila \n");
     showStack(&s);


//    char * name = NULL;
//    readString(&name);
//    //printf("The value of name is %s, and the position is %p",name,name);
//    printf("The value of name is %s, and the position is %p", name, (void *)name);



    return 0;
}
