#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


int main(void) {
  int choice = -1,i;
  for(i=0;i<SIZE;i++){
    hashArray[i].head=NULL;
    hashArray[i].tail=NULL;
    hashArray[i].n_elem=0;
  }
  while(choice != 0){
    //Menu/////////
    printf("Administrador de personas. Banco EDA:\n================\n");
    printf("1.- Cargar archivo de clientes\n");
    printf("2.- Agregar cliente\n");
    printf("3.- Eliminar cliente del sistema\n");
    printf("4.- Buscar cliente por rut, nombre o apellido\n");
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
      char* nom;
      char ape[30];
      char gen[6];
      char email[30];
      char dir[50];
      int id;
      char *choice;
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
      printf("Estan correctos estos datos?\n");
      printf("Id: %d Nombre y apellido: %s %s Email: %s Genero: %s Direccion: %s",id,nom,ape,email,gen,dir);
      scanf("%s",choice);
      insert('M',id,nom,"Moraga",email,gen,dir);
      if(strcmp(choice,"si")==0){
        insert(ape[0],id,nom,ape,email,gen,dir);
      }
    }
    else if(choice == 3){
      //foo
    }
    else if(choice == 4){
      cliente* res = search_apellido("Marran");
      if(res==NULL){
        printf("No se encontro\n");
      }
      else{
        printf("Apellido: %s",res->apellido);
      }
    }
    else if(choice == 5){
      int id,cant;
      printf("Desea agregar o sacar dinero?\n\t1. Agregar 2. Sacar\n");
      scanf("%d",&id);
      if(id == 1){
        printf("Cuanto desea ingresar?\n");
        scanf("%d",&cant);
      }
      else if(id == 2){
        printf("Cuanto desea sacar?\n");
        scanf("%d",&cant);
      }
      else{
        printf("opcion incorrecta.\n");
      }
    }
    else if(choice == 6){
      //foo
    }
    else if(choice == 7){
      //foo
    }
    else if(choice == 8){
      display();
    }
    else {
      printf("Opcion incorrecta.\n\n");
    }
  }
  return 0;
}