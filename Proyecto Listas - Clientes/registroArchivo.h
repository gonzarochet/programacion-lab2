#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "cliente.h"
#include "utilidades.h"
#include "gotoxy.h"


#define arRegistro "clientes.dat" // define un archivo de clientes.

void ingresarRegistros();
stCliente ingresarUnRegistro();
void agregarRegistro(stCliente e);

void getNombre(char n[]);
void getApellido(char a[]);
void getDNI(char dni[]);
void getCUIT(char cuit[], char dni[]);
void getEmail(char email[], char nombre[], char apellido[]);
void getDomicilio(char c[]);
void getTelefono(char tel[]);

stCliente cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stCliente e);
void generaArchivoRandom(int cantidad);
void espera();
int buscaDNI(char dni[]);

#endif // REGISTROARCHIVO_H_INCLUDED
