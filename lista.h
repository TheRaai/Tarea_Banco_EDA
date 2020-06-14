#include "pila.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct cliente{
  int id;
  char* nombre;
  char* apellido;
  char* email;
  char* genero;
  char* direccion;
  int saldo;
  char key;
  struct pila* transacciones;
  struct cliente* next;
}cliente;

void crear_lista();
cliente* agregar_elemento_lista(char key,int id,char* nombre,char* apellido,char* email,char* genero,char* direccion);
void eliminar_elemento_lista(cliente** h_ref,int id);