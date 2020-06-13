#include "hash.h"


hash hashArray[26];
lista aux[1000];
lista aux2[1000];
int max = 1;

int hashCode(char key){//Consigue el index donde va la letra
  int z= (int)(key);
  return z%SIZE;
}

void agregar_elemento_hash(char key,int id,char* nombre, char* apellido, char* email,char* genero, char* direccion){
  int index=0;
  index=hashCode(key);
  //Crea cliente auxiliar con los datos a ingresar
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
  //////////
  if(hashArray[index].head == NULL){//Si es el primero en su letra en ser ingresado
    hashArray[index].head = temp;
    hashArray[index].tail = temp;
    //printf("index: %d Apellido: %s direccion: %s\n",id,hashArray[index].head->apellido,hashArray[index].head->direccion);
  }
  else{//Si ya existe alguien mas con su letra
    hashArray[index].tail->next = temp;
    hashArray[index].tail = temp;
    //printf("index: %d Apellido: %s direccion: %s\n",id,hashArray[index].tail->apellido,hashArray[index].tail->direccion);

  }
}

void leer_archivo(char* filename){
  FILE* arch = fopen(filename,"r");
  char aux[999];
  if (arch == NULL){
    printf("El archivo no se pudo leer\n"); /*Imprimir error si no se logra leer el archivo*/
  }
  cliente* lista_cliente;
  fgets(aux,999,arch);
  int id;
  char* nom,*ape,*email,*gen,*dir;
  while(fgets(aux,999,arch)){
    //consigue los datos
    id = atoi(strtok(aux,"\t"));
    nom = strtok(NULL,"\t");
    ape = strtok(NULL,"\t");
    email = strtok(NULL,"\t");
    gen = strtok(NULL,"\t");
    dir = strtok(NULL,"\t");
    /////////
    //Todos los casos posibles, viendo por primera letra del apellido
    if(ape[0]=='A'){
      agregar_elemento_hash('A',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='B'){
      agregar_elemento_hash('B',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='C'){
      agregar_elemento_hash('C',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='D'){
      agregar_elemento_hash('D',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='E'){
      agregar_elemento_hash('E',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='F'){
      agregar_elemento_hash('F',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='G'){
      agregar_elemento_hash('G',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='H'){
      agregar_elemento_hash('H',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='I'){
      agregar_elemento_hash('I',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='J'){
      agregar_elemento_hash('J',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='K'){
      agregar_elemento_hash('K',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='L'){
      agregar_elemento_hash('L',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='M'){
      agregar_elemento_hash('M',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='N'){
      agregar_elemento_hash('N',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='O'){
      agregar_elemento_hash('O',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='P'){
      agregar_elemento_hash('P',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Q'){
      agregar_elemento_hash('Q',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='R'){
      agregar_elemento_hash('R',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='S'){
      agregar_elemento_hash('S',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='T'){
      agregar_elemento_hash('T',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='U'){
      agregar_elemento_hash('U',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='V'){
      agregar_elemento_hash('V',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='W'){
      agregar_elemento_hash('W',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='X'){
      agregar_elemento_hash('X',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Y'){
      agregar_elemento_hash('Y',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Z'){
      agregar_elemento_hash('Z',id,nom,ape,email,gen,dir);
    }
    ///////
  }
  fclose(arch);
}

cliente* search_apellido(char* apellido){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(strcmp(temp->apellido,apellido)==0){//Revisa si es el apellido buscado
        return temp;
      }
      temp=temp->next;
    }
    i++;
  }
  return NULL;
}

cliente* search_id(int id){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(temp->id==id){//Revisa el id
        return temp;
      }
      temp=temp->next;
    }   
    i++;
  }
  return NULL;
}

cliente* search_nombre(char* nombre){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(strcmp(temp->nombre,nombre)==0){//Revisa nombre
        return temp;
      }
      temp=temp->next;
    }   
    i++;
  }
  return NULL;  
}

void ingresar_dinero(int id,int cant){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    while(temp!=NULL){
      if(temp->id == id){
        agregar_elemento_pila(&temp->transacciones,101,cant);
        temp->saldo+=cant;
        printf("Ingresado: $%d Saldo: $%d\n",temp->transacciones->cantidad,temp->saldo);
        ingresar_nuevo(temp->nombre,temp->apellido,temp->saldo,cant,101);
        sacado = 'I';
      }
      temp=temp->next;
    }
    i++;
  }
}

void sacar_dinero(int id,int cant){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    while(temp!=NULL){
      if(temp->id == id){
        if(temp->saldo-cant < 0){//Error si se intenta sacar mas saldo del que se tiene guardado
          printf("No se puede sacar mas de $%d\n",temp->saldo);
        }
        else{
          agregar_elemento_pila(&temp->transacciones,201,cant);
          temp->saldo-=cant;
          printf("Sacado: $%d Saldo: $%d\n",temp->transacciones->cantidad,temp->saldo);
          ingresar_nuevo(temp->nombre,temp->apellido,temp->saldo,cant,201);
          sacado = 'S';
        }

      }
      temp=temp->next;
    }
    i++;
  }
}

void ingresar_nuevo(char* nombre, char* apellido, int saldo,int cantidad, int id){//funcion para ingresar nuevo cliente a la lista de transacciones
  int i = 0;
  while(i<1000){
    if(aux[i].nombre == NULL){
      aux[i].nombre = nombre;
      aux[i].apellido = apellido;
      aux[i].saldo = saldo;
      aux[i].cantidad = cantidad;
      aux[i].id_tran = id;
      break;
    }
    else if(strcmp(aux[i].nombre,nombre)==0){
      aux[i].saldo = saldo;
      aux[i].cantidad = cantidad;
      aux[i].id_tran = id;
      break;
    }
    i++;
  }
  aux[i].nombre = nombre;
  aux[i].apellido = apellido;
  aux[i].saldo = saldo;
}

void display_transacciones(int minimo){
  int i=0;
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    while(temp!=NULL){
      if(temp->transacciones == NULL){
        temp = temp->next;
      }
      else{
        if(temp->transacciones->cantidad>minimo){
          printf("nombre: %s %s ha hecho una transaccion por: %d con id: %d y termino con saldo: %d\n",temp->nombre,temp->apellido,temp->transacciones->cantidad,temp->transacciones->id,temp->saldo);
        }
        temp = temp->next;
      }
    }
    i++;
  }
}

void sacar_ultima(int id_buscado){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  char* nombre = (char*)malloc(sizeof(char*));
  int i = 0;
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    while(temp!=NULL){
      if(temp->id == id_buscado){
        if(temp->transacciones->id==101){//Descuenta la transaccion al saldo
          temp->saldo-=temp->transacciones->cantidad;
        }
        else if(temp->transacciones->id==201){//Agrega el saldo sacado
          temp->saldo+=temp->transacciones->cantidad;
        }
        eliminar_elemento_pila(&temp->transacciones);//pop de la pila 
        strcpy(nombre,temp->nombre);
      }
      temp=temp->next;
    }
    i++;
  }
}

void crear_nueva_ordenada(){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  lista temporal;
  int i = 0,j=0;
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    while(temp!=NULL){
      if(temp->saldo > max){
        if(j>20){
          break;
        }
        temporal.nombre = temp->nombre;
        temporal.apellido = temp->apellido;
        temporal.saldo = temp->saldo;
        //max = temp->saldo;
        if(aux2[j].nombre==NULL){
          aux2[j] = temporal;
          j++;
        }
        else{
          j++;
        }
        
      }
      temp = temp->next;
    }
    i++;
  }
}

void ordenar(){
  int i = 0;
  for(i=0;i<1000;i++){
    for(int j=i+1;j<1000;j++){
      if(aux2[j].saldo > aux2[i].saldo){
        lista temp = aux2[i];
        aux2[i] = aux2[j];
        aux2[j] = temp;
      }
    }
  }
}

void display_saldo(int cantidad){
  int i=0;
  while(i<cantidad && aux2[i].nombre != NULL){
    printf("nombre: %s %s tiene saldo: %d\n",aux2[i].nombre,aux2[i].apellido,aux2[i].saldo);
    i++;
  }
}

void borrar_cliente_id(int id){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(temp->id==id){//Revisa el id
        if(temp->saldo==0){
          printf("Eliminado: %s %s\n",temp->nombre,temp->apellido);
          cliente* next = temp->next;
          free(temp);
          free(temp->nombre);
          free(temp->apellido);
          free(temp->email);
          free(temp->genero);
          free(temp->direccion);
          temp = next;
        }
        else{
          printf("no se puede eliminar, ya que su saldo es mayor a 0.\n");
        }
      }
      temp=temp->next;
    }   
    i++;
  }
}

void borrar_cliente_apellido(char* apellido){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(strcmp(temp->apellido,apellido)==0){//Revisa si es el apellido buscado
        if(temp->saldo==0){
          printf("Eliminado: %s %s\n",temp->nombre,temp->apellido);
          cliente* next = temp->next;
          free(temp);
          free(temp->nombre);
          free(temp->apellido);
          free(temp->email);
          free(temp->genero);
          free(temp->direccion);
          temp = next;
        }
        else{
          printf("no se puede eliminar, ya que su saldo es mayor a 0.\n");
        }
      }
      temp=temp->next;
    }
    i++;
  }
}

void borrar_cliente_nombre(char* nombre){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int i = 0;
  //Itera hasta que se acabe el arreglo
  while(hashArray[i].head!=NULL){
    temp = hashArray[i].head;
    //Itera toda la letra
    while(temp!=NULL){
      if(strcmp(temp->nombre,nombre)==0){//Revisa nombre
        if(temp->saldo==0){
          printf("Eliminado: %s %s\n",temp->nombre,temp->apellido);
          cliente* next = temp->next;
          free(temp);
          free(temp->nombre);
          free(temp->apellido);
          free(temp->email);
          free(temp->genero);
          free(temp->direccion);
          temp = next;
        }
        else{
          printf("no se puede eliminar, ya que su saldo es mayor a 0.\n");
        }        
      }
      temp=temp->next;
    }   
    i++;
  }  
  
}