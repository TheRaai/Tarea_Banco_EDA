#include <stdio.h>
#include <stdlib.h>

typedef struct pila{
  int id;
  int cantidad;
  struct pila* next;
}pila;

pila* crear_pila();
int isEmpty(pila* top);
pila* crear_transaccion(int id, int transaccion);
void push(pila** top ,int id, int transaccion);
void pop(pila** top);
void eliminar_pila(pila* top);