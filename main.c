#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


void limpiar(){
  int i=0;
  while(i<26 && hashArray[i].head!=NULL){
    free(hashArray[i].head);
    i++;
  }
}

int main(void) {
  int choice = -1,i;
  //Inicializa la hashtable
  for(i=0;i<SIZE;i++){
    hashArray[i].head=NULL;
    hashArray[i].tail=NULL;
  }
  while(choice != 0){
    //Menu/////////
    printf("Administrador de personas. Banco EDA:\n================\n");
    printf("1.- Cargar archivo de clientes\n");
    printf("2.- Agregar cliente\n");
    printf("3.- Eliminar cliente del sistema\n");
    printf("4.- Buscar cliente por id, nombre o apellido\n");
    printf("5.- Agregar transaccion\n");
    printf("6.- Deshacer última transacción\n");
    printf("7.- Generar una lista de clientes según última transacción\n");
    printf("8.- Generar una lista con los clientes que tienen más dinero en el banco\n");
    printf("0.- Salir\n");
    ///////////////
    scanf("%d",&choice);
    if(choice == 0){
      break;
    }
    else if(choice == 1){
      leer_archivo("data.txt");
    }
    else if(choice == 2){
      char nom[20];
      char ape[30];
      char gen[6];
      char email[30];
      char dir[50];
      int id;
      char *choice;
      //Ingresar datos
      printf("Ingrese Id: ");
      scanf("%d",&id);
      printf("Ingrese nombre: ");
      scanf("%s",nom);
      printf("Ingrese apellido: ");
      scanf("%s",ape);
      printf("Ingrese email: ");
      scanf("%s",email);      
      printf("Ingrese Genero y direccion: \n");
      scanf("%s ",gen);
      fgets(dir,50,stdin);
      ////////
      //Validacion de datos
      printf("Estan correctos estos datos?\n");
      printf("Id: %d Nombre y apellido: %s %s Email: %s Genero: %s Direccion: %s",id,nom,ape,email,gen,dir);
      scanf("%s",choice);
      ///////
      if(strcmp(choice,"si")==0){
        agregar_elemento_hash(ape[0],id,nom,ape,email,gen,dir);//Ingresa la persona
      }
    }
    else if(choice == 3){
      int numero;
      //Pregunta por que opcion quiere
      printf("Desea eliminar por rut, nombre o apellido?\n\t Ingrese 1 para nombre, 2 para id, 3 para apellido\n");
      scanf("%d",&numero);
      if(numero == 1){
        //Busqueda por nombre
        char nombre[20];
        printf("Ingrese nombre a eliminar: ");
        scanf("%s",nombre);
        borrar_cliente_nombre(nombre);
      }
      if(numero==2){
        //Busqueda por id
        int id;
        printf("Ingrese id a eliminar: ");
        scanf("%d",&id);
        borrar_cliente_id(id);
      }
      if(numero == 3){
        //Busqueda por apellido
        char apellido[20];
        printf("Ingrese apellido a eliminar: ");
        scanf("%s",apellido);
        borrar_cliente_apellido(apellido);
      }
    }
    else if(choice == 4){
      int numero;
      cliente* res;
      //Pregunta por que opcion quiere
      printf("Desea buscar por rut, nombre o apellido?\n\t Ingrese 1 para nombre, 2 para id, 3 para apellido\n");
      scanf("%d",&numero);
      if(numero==1){
        //Busqueda por nombre
        char nombre[20];
        printf("Ingrese nombre a buscar: ");
        scanf("%s",nombre);
        res = search_nombre(nombre);
        if(res==NULL){
          printf("No se encontro\n");
        }
        else{
          printf("Nombre: %s %s\nid: %d\n",res->nombre,res->apellido,res->id);
          printf("Email: %s\n",res->email);
          printf("Genero: %s\n",res->genero);
          printf("Direccion: %s",res->direccion);
        }
      }
      if(numero==2){
        //Busqueda por id
        int id;
        printf("Ingrese id a buscar: ");
        scanf("%d",&id);
        res = search_id(id);
        if(res==NULL){
          printf("No se encontro\n");
        }
        else{
          printf("Nombre: %s %s\nid: %d\n",res->nombre,res->apellido,res->id);
          printf("Email: %s\n",res->email);
          printf("Genero: %s\n",res->genero);
          printf("Direccion: %s",res->direccion);
        }
      }
      if(numero==3){
        //Busqueda por apellido
        char apellido[20];
        printf("Ingrese apellido a buscar: ");
        scanf("%s",apellido);
        res = search_apellido(apellido);
        if(res==NULL){
          printf("No se encontro\n");
        }
        else{
          printf("Nombre: %s %s\nid: %d\n",res->nombre,res->apellido,res->id);
          printf("Email: %s\n",res->email);
          printf("Genero: %s\n",res->genero);
          printf("Direccion: %s",res->direccion);
        }
      }

    }
    else if(choice == 5){
      //Hacer transaccion
      int id,cant,client;
      printf("En que cliente desea agregar una transaccion? Ingrese un id: ");
      scanf("%d",&client);
      printf("Desea agregar o sacar dinero?\n\t1. Agregar 2. Sacar\n");
      scanf("%d",&id);
      if(id == 1){
        printf("Cuanto desea ingresar?\n");
        scanf("%d",&cant);
        ingresar_dinero(client,cant);
      }
      else if(id == 2){
        printf("Cuanto desea sacar?\n");
        scanf("%d",&cant);
        sacar_dinero(client,cant);
      }
      else{
        printf("opcion incorrecta.\n");
      }
    }
    else if(choice == 6){
      sacar_ultima();
    }
    else if(choice == 7){
      display_transacciones();
    }
    else if(choice == 8){
      crear_nueva_ordenada();
      ordenar();
      display_saldo();
    }
    else {
      printf("Opcion incorrecta.\n\n");
    }
  }
  limpiar();//Limpiar memoria
  return 0;
}