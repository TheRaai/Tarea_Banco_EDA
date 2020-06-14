#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crear_lista(){
  cliente* lista = (cliente*)malloc(sizeof(cliente));
}

cliente* agregar_elemento_lista(char key,int id,char* nombre,char* apellido,char* email,char* genero,char* direccion){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  temp->nombre = (char*)malloc(sizeof(char*)*sizeof(nombre)+1);
  temp->apellido = (char*)malloc(sizeof(char*)*sizeof(apellido)+1);
  temp->email = (char*)malloc(sizeof(char*)*sizeof(email)+1);
  temp->genero = (char*)malloc(sizeof(char*)*sizeof(genero)+1);
  temp->direccion = (char*)malloc(sizeof(char*)*sizeof(direccion)+1);
  temp->key = key;
  temp->id = id;
  strcpy(temp->nombre,nombre);
  strcpy(temp->apellido,apellido);
  strcpy(temp->email,email);
  strcpy(temp->genero,genero);
  strcpy(temp->direccion,direccion);
  temp->saldo = 0;
  temp->transacciones = crear_pila();
  temp->next = NULL;
  return temp;
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

