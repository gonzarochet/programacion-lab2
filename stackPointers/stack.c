#include "stack.h"

void initStack(StackStudent * s)
{
    s->dim = 50;
    s->student = (stStudent *) malloc(sizeof(stStudent)*(s->dim));
    s->nextPosition=0;
}
// apilar elemento
int pushStack(StackStudent * s, stStudent sv)
{
    int flag = 1;
    if(s->nextPosition==s->dim)
    {
        int newDim = s->dim * 2;
        stStudent * buffer = realloc(s->student, sizeof(stStudent)* newDim);
        if(buffer)
        {
            s->student = buffer;
        }
        else
        {
            flag = 0;
            //fprintf(stderr,"Memory reallocation failed\n");
        }
    }

    if(flag)
    {
        int index = s->nextPosition;
        s->student[index] = sv;
        s->nextPosition++;

    }

    return flag;
}

void showStack(StackStudent * s)
{
    for(int i = 0; i< s->nextPosition; i++)
    {
        showStudent(s->student[i]);
    }

}


// desapilar elemento
stStudent popStack(StackStudent * s)
{
    stStudent aux = s->student[s->nextPosition -1];
    s->nextPosition--;
    return aux;

}
// tope pila
stStudent peekStack(StackStudent * s)
{
    return s->student[s->nextPosition-1];
}
// esta vacia pila
int isEmptyStack(StackStudent * s)
{
    return (s->nextPosition == 0)? 1: 0;
}

// to Array

int stackStudentToArray(StackStudent * s, stStudent ** arr,int dim)
{
    if(dim > s->dim)
    {
        stStudent * buffer = (stStudent*)realloc(s->student,(sizeof(stStudent)*dim));
        if(buffer)
        {
        s->student = buffer;
        }
    }
    (*arr) = s->student;
    return s->nextPosition;
}

/*

void mostrar2(P_Pila p)
{
    int i;
    int max = valorEspacios(p);
    int espacio;

    printf("\n -TOPE- \n");

    for(i = p->postope; i > 0; i--)
    {
        espacio = max-cantidadCaracteres(p->valores[i-1]);

        printf("|");
        printf("%d", p->valores[i-1]);
        espacios(espacio);
        printf("| \n");
    }
    printf("\n -BASE-\n");

}

int valorEspacios(P_Pila p)
{

    int mayor;
    int i;

    for(i=0; i < p->postope; i++)
    {
        if(i == 0)
        {
            mayor =  p->valores[i];
        }
        else
        {
            if(p->valores[i] > mayor)
            {

                mayor = p->valores[i];
            }
        }
    }
    return cantidadCaracteres(mayor);
}

void espacios(int valor)
{
    for(int i = 0; i<valor; i++)
        printf(" ");
}

int cantidadCaracteres(int numero)
{
    int i = 1;
    while(numero>10)
    {
        numero = numero/10;
        i++;
    }
    return i;
}

*/
