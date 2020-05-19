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
void agregar_cliente(cliente** h_ref,int id,char* nombre,char* apellido,char* email,char* genero,char* direccion);
void borrar_cliente(cliente** h_ref,int id);