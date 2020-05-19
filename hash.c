#include "hash.h"

int hashCode(char key){
  return key % SIZE;
}
hash hashArray[SIZE];


void insert(char key,int id,char* nombre, char* apellido, char* email,char* genero, char* direccion){
  int index = hashCode(key);
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  temp->key = key;
  temp->id = id;
  temp->nombre = nombre;
  temp->apellido = apellido;
  temp->email = email;
  temp->genero = genero;
  temp->direccion = direccion;
  temp->saldo = 0;
  temp->transacciones = crear_pila();
  temp->next = NULL;
  if(hashArray[index].head == NULL){
    hashArray[index].head = temp;
    hashArray[index].tail = temp;
    hashArray[index].n_elem++;
    printf("Agregado: %s con llave: %c\n",hashArray[index].head->apellido,hashArray[index].tail->key);
  }
  else{
    hashArray[index].tail->next = temp;
    hashArray[index].tail = temp;
    hashArray[index].head->next = hashArray[index].tail;
    printf("Agregado: %s con llave: %c\n",hashArray[index].tail->apellido,hashArray[index].tail->key);
  }
  free(temp);

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

    id = atoi(strtok(aux,"\t"));
    nom = strtok(NULL,"\t");
    ape = strtok(NULL,"\t");
    email = strtok(NULL,"\t");
    gen = strtok(NULL,"\t");
    dir = strtok(NULL,"\t");
    if(ape[0]=='A'){
      insert('A',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='B'){
      insert('B',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='C'){
      insert('C',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='D'){
      insert('D',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='E'){
      insert('E',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='F'){
      insert('F',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='G'){
      insert('G',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='H'){
      insert('H',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='I'){
      insert('I',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='J'){
      insert('J',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='K'){
      insert('K',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='L'){
      insert('L',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='M'){
      insert('M',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='N'){
      insert('N',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='O'){
      insert('O',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='P'){
      insert('P',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Q'){
      insert('Q',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='R'){
      insert('R',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='S'){
      insert('S',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='T'){
      insert('T',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='U'){
      insert('U',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='V'){
      insert('V',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='W'){
      insert('W',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='X'){
      insert('X',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Y'){
      insert('Y',id,nom,ape,email,gen,dir);
    }
    else if(ape[0]=='Z'){
      insert('Z',id,nom,ape,email,gen,dir);
    }

  }
  fclose(arch);
}

cliente* search_apellido(char* apellido){
  cliente* temp = (cliente*)malloc(sizeof(cliente));
  int index = hashCode(apellido[0]);
  while(hashArray[index].head!=NULL){
    temp = hashArray[index].head;
    printf("apellido: %s\n",temp->apellido);
    if(temp->key ==apellido[0]){
      if(temp->apellido==apellido){
        return temp;
      }
    }
    temp = temp->next;
    
    ++index;
    index%=SIZE;
  }

  return NULL;
}

void display(){
  int i=0;
  cliente* temp;
  temp = hashArray[hashCode('A')].head;
  printf("%s\n",hashArray[hashCode('D')].head->nombre);
  if(temp->key == 'A'){
    printf("Nombre: %s Apellido : %s\n",temp->nombre,temp->apellido);
  }
  else{
    printf("Im gonna kms\n");
  }
  
}