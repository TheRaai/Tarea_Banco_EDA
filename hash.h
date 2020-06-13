#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 65

typedef struct hash {
  cliente* head;   
  cliente* tail; 
}hash;

typedef struct lista{
  char* nombre;
  char* apellido;
  int saldo;
  int cantidad;
  int id_tran;
}lista;

extern hash hashArray[26];
int latest_id;
char sacado;


int hashCode(char key);
void agregar_elemento_hash(char key,int id,char* nomb,char* apellido,char* email,char* genero,char* direccion);
void display();
void leer_archivo(char* filename);
cliente* search_apellido(char* apellido);
cliente* search_id(int id);
cliente* search_nombre(char* nombre);
void ingresar_dinero(int id,int cant);
void sacar_dinero(int id,int cant);
void ingresar_nuevo(char* nombre,char* apellido,int saldo,int cantidad, int id);
void display_transacciones(int minimo);
void sacar_ultima(int id_buscado);
void crear_nueva_ordenada();
void ordenar();
void display_saldo(int cantidad);
void borrar_cliente_id(int id);
void borrar_cliente_apellido(char* apellido);
void borrar_cliente_nombre(char* nombre);