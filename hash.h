#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 26

typedef struct hash {
  cliente* head;   
  cliente* tail; 
  int n_elem;
}hash;

extern hash hashArray[SIZE];

void init_ar();
int hashCode(char key);
cliente* search(cliente* lista,int index);
void insert(char key,int id,char* nombre,char* apellido,char* email,char* genero,char* direccion);
void delete(hash* arreglo,char key);
void display();
void leer_archivo(char* filename);
cliente* search_apellido(char* apellido);