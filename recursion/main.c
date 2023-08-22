#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
float potencia(int n, int exp);
void showArrayRecursive(int array[],int v);
void showArrayRecursiveInverse(int array[],int v);
int isCapicua (int array[], int i, int v);
int addNumbersArray(int array[],int v);
int findLowerValuePosition(int array[],int pos, int v);

int main()
{
    printf("Hello world!\n");

    printf("El factorial de 5 es : %d \n",factorial(5));
    printf("La potencia de 5 a la 3  : %.1f \n",potencia(8,3));

    int array[6] = {3,4,5,1,7,8};
    showArrayRecursive(array,6);
    printf("\n");
    showArrayRecursiveInverse(array,6);

    int array2[6] = {3,2,1,1,2,3};
    printf("\n");
    showArrayRecursive(array2,6);
    printf("\nArray 1- Si es 1 el arreglo es capicua, si no es 0 ---> %d",isCapicua(array,0,6));
    printf("\nArray 2 - Si es 1 el arreglo es capicua, si no es 0 ---> %d",isCapicua(array2,0,6));

    printf("\nArray 1 - La suma del array es: %d",addNumbersArray(array,6));
    printf("\nArray 2- La suma del array es: %d",addNumbersArray(array2,6));


    printf("\nArray 1- La posicion del menor elemento del array es: %d",findLowerValuePosition(array,0,6));
    printf("\nArray 2- La posicion del menor elemento del array es: %d",findLowerValuePosition(array2,0,6));

    printf("\n");
    //arrayToArchi(array,6,"numeritos.dat");
    showArchi("numeritos.dat");
    printf("\n");
    printf("El valor menor de numeritos.dat es %d", testArchi("numeritos.dat"));

    testArchi2("numeritos.dat");
    printf("\n");
    showArchi("numeritos.dat");

    return 0;
}



/// 1. Calcular el factorial de un número en forma recursiva.

int factorial(int n)
{

    if(n == 1)
    {
        return 1;
    }
    else
    {
        return factorial(n-1)* n ;
    }
}

/// 2. Calcular la potencia de un número en forma recursiva.
float potencia(int n, int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    else
    {
        return (float)(n*(potencia(n,exp-1)));
    }

}

/// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void showArrayRecursive(int array[],int v)
{
    if(v>0)
    {
        //printf("%d \n",v);
        showArrayRecursive(array,v-1);
        printf("%d |", array[v-1]);
    }
}


/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).
void showArrayRecursiveInverse(int array[],int v)
{
    if(v>0)
    {
        printf("%d |",array[v-1]);
        return showArrayRecursiveInverse(array,v-1);
    }
}


/// 5. Determinar en forma recursiva si un arreglo es capicúa.
int isCapicua (int array[], int i, int v)
{
    if(i<v)
    {
        if(array[i] == array[v-1])
        {
            return isCapicua(array,i+1, v-1);
        }
        else
        {
            return 0;
        }

    }
    return 1;

}
/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
int addNumbersArray(int array[],int v)
{

    if(v==0)
    {
        return 0;
    }
    else
    {
        return addNumbersArray(array,v-1) + array[v-1];
    }
}

/// 7. Buscar el menor elemento de un arreglo en forma recursiva.
int findLowerValuePosition(int array[],int pos, int v)
{
    if(v==-1)
    {
        return pos;
    }
    else
    {
        if(array[v-1]<array[pos])
        {
            pos = v-1;
        }
        return findLowerValuePosition(array,pos,v-1);
    }

}

void arrayToArchi(int array[], int v, char nombreArchivo[])
{

    FILE * buffer = fopen(nombreArchivo,"wb");

    if(buffer)
    {
        for(int i = 0; i<v; i++)
        {
            fwrite(&array[i],1,sizeof(int),buffer);
        }
        fclose(buffer);
    }

}

void showArchi(char nombreArchivo[])
{
    FILE * buffer = fopen(nombreArchivo,"rb");
    int value;
    if(buffer)
    {
        while(fread(&value,1,sizeof(int),buffer)>0)
        {
            printf(" %d -", value);
        }
        fclose(buffer);
    }

}
/// 8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
int findLowerValueInFile(FILE * buffer,int currentValue)
{
    int readValue;
    if(fread(&readValue,1,sizeof(int),buffer)>0)
    {
        if(readValue < currentValue)
        {
            currentValue = readValue;
        }
        return findLowerValueInFile(buffer,currentValue);
    }
    else
    {
        return currentValue;
    }


}

int testArchi(char nameFile[])
{
    FILE * buffer = fopen(nameFile,"r+b");
    int value;
    if(buffer)
    {
        if(fread(&value,1,sizeof(int),buffer)>0)
        {
            value = findLowerValueInFile(buffer,value);
        }
        fclose(buffer);
    }
    return value;
}


/// 9. Invertir los elementos de un archivo de números enteros de forma recursiva.
void inverterValueFile(FILE * buffer, int posInit, int posEnd)
{

    if(posInit < posEnd)
    {
        int valueInit, valueEnd;

        // Mover el puntero al inicio y final respectivamente
        fseek(buffer,posInit * sizeof(int), SEEK_SET);
        fseek(buffer,posEnd * sizeof(int), SEEK_SET);

        // Leer los valores en esas posiciones
        fread(&valueInit, sizeof(int), 1, buffer);
        fread(&valueEnd, sizeof(int), 1, buffer);

        // Volver a las posiciones para escribir los valores invertidos
        fseek(buffer, posInit * sizeof(int), SEEK_SET);
        fwrite(&valueEnd, sizeof(int), 1, buffer);
        fseek(buffer, posEnd * sizeof(int), SEEK_SET);
        fwrite(&valueInit, sizeof(int), 1, buffer);

        // Llamada recursiva
        inverterValueFile(buffer, posInit + 1, posEnd - 1);

    }


}


int cuentaDatosArchivoBis(char nombreArchivo[])
{
    int cont=0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        fseek(archi,0,SEEK_END);
        cont = ftell(archi);
        fclose(archi);
    }
    return cont;
}

void testArchi2(char nameFile[])
{
    FILE * buffer = fopen(nameFile,"rb+");
    FILE * buffer2 = fopen(nameFile,"rb+");

    inverterValueFile(buffer,0,6);

    fclose(buffer);
    fclose(buffer2);
}







