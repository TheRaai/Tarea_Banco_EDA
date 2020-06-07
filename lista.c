#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(){
  cliente* lista = (cliente*)malloc(sizeof(cliente));
}

void agregar_elemento_lista(cliente** h_ref,int id,char* nombre,char* apellido,char* email,char* genero,char* direccion){
  cliente* nuevo = (cliente*)malloc(sizeof(cliente));
  cliente* temp;
  //Crea la lista del nuevo cliente
  nuevo -> id = id;
  nuevo -> nombre = nombre;
  nuevo -> apellido = apellido;
  nuevo -> email = email;
  nuevo -> genero = genero;
  nuevo -> direccion = direccion;
  nuevo -> transacciones = crear_pila();
  nuevo -> next = NULL;
  nuevo -> key = apellido[0];
  agregar_elemento_pila(&nuevo->transacciones,0,0);
  
  if(*h_ref == NULL){
    nuevo -> next = *h_ref;
    *h_ref = nuevo;
    return;
  }

  temp = *h_ref;

  while(temp->next != NULL){
    temp = temp->next;
  }
  nuevo -> next = temp->next;
  temp->next = nuevo;
}

void eliminar_elemento_lista(cliente** h_ref,int id){
  cliente* temp = *h_ref;
  //Si la lista esta vacia, retorna
  if(*h_ref == NULL){
    return;
  }
  //Si se borra el primer elemento(head)
  if(id == 0){
    *h_ref = temp->next;
    free(temp);
    return;
  }
  //Recorre hasta la posicion que se quiere
  for(int i = 1;temp!=NULL && i<id-1;i++){
    temp = temp->next;
  }
  //Si nos pasamos del numero de elementos
  if(temp == NULL || temp->next == NULL){
    return;
  }
  //Elimina el dato
  cliente* next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

