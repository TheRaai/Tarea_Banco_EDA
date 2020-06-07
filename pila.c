#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

pila* crear_pila(){
  pila* top = NULL;
  return top;
}

int isEmpty(pila* top) { //Revisa si esta vacia la pila
	return !top; 
} 

pila* crear_transaccion(int id, int transaccion){
  pila* transacciones = (pila*)malloc(sizeof(pila));
  transacciones->id  = id;
  transacciones->cantidad = transaccion;
  transacciones->next = NULL;
  return transacciones;
}

void agregar_elemento_pila(pila** top ,int id, int transaccion){
  pila* transacciones = crear_transaccion(id,transaccion);
  transacciones->next = *top;
  *top = transacciones;
}

void eliminar_elemento_pila(pila** top){
  pila* temp = *top;
  *top = (*top)->next;
  free(temp);
}

void eliminar_pila(pila* top){
  while(!isEmpty(top)){
    eliminar_elemento_pila(&top);
  }
}
