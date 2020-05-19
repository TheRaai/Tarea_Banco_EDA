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

void push(pila** top ,int id, int transaccion){
  pila* transacciones = crear_transaccion(id,transaccion);
  transacciones->next = *top;
  *top = transacciones;
}

void pop(pila** top){
  pila* temp = *top;
  *top = (*top)->next;
  free(temp);
}

void eliminar_pila(pila* top){
  while(!isEmpty(top)){
    pop(&top);
  }
}
