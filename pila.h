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
void agregar_elemento_pila(pila** top ,int id, int transaccion);
void eliminar_elemento_pila(pila** top);
void eliminar_pila(pila* top);