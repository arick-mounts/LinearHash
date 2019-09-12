#include <iostream>
#include <stdlib.h>

#define SIZE 100
#define EMPTYVAL '-';
#define EMPTYKEY -2
#define DELETEDKEY -1

/*
 *This program creates and manipulates structs consisting of and integer key, and a character value,
 *and utilizes linear hash probing to populate an array, it deletes all even numbered keys
 *and populates the array with 25 more structs
 *
 *Data Structures @ TCC
 *
 *Arick Mounts
 */

using namespace std;

struct HashStruct{
int key ;
char value;
};

void print_table(struct HashStruct * HashArray, int size);
void initialize_table(struct HashStruct * HashArray , int size);
int linear_probe(int key, int i, int size);
void linear_insert(struct HashStruct * HashArray, struct HashStruct Hash, int size);
void linear_delete(struct HashStruct * HashArray, int key, int size);
void print_hash(struct HashStruct structIn);
struct HashStruct build_rand_hashstruct();



int main(){
  
  srand (time(NULL));
  struct HashStruct HashArray[SIZE]; 

  initialize_table(HashArray, SIZE);
  
  for (int c = 0; c < 75; c++){
    linear_insert(HashArray, build_rand_hashstruct(),SIZE);
    
    
  }
  cout << "75 Random structs added" << endl << "_______"<< endl;
  print_table(HashArray, SIZE);
  
  for (int i = 0; i <99; i +=2){
      HashArray[i].value = EMPTYVAL;
      HashArray[i].key = DELETEDKEY;
  }
  cout << "Every even element removed" << endl << "_______"<< endl;
  print_table(HashArray, SIZE);

  for (int c = 0; c < 25; c++){
    linear_insert(HashArray, build_rand_hashstruct(),SIZE);
    //cout << "c == " << c << endl;
  }
  cout << "25 Random elements added" << endl << "_______"<< endl;
  print_table(HashArray, SIZE);

    
}

struct HashStruct build_rand_hashstruct(){
  struct HashStruct built;
  int randInt;
  char randChar;
  randInt = rand() % 1000 + 1;
  randChar = rand() % (122 + 1 - 97) + 97 ;
  built.key = randInt;
  built.value = randChar;
  return built;
}

void initialize_table(struct HashStruct * HashArray , int size){
  int i ;
  for (i = 0; i < size; i++){
    HashArray[i].value = EMPTYVAL;
    HashArray[i].key =  EMPTYKEY;
  }
  
}

void print_table(struct HashStruct * HashArray, int size){
int i;
for (i =0; i < size; i++){
  if(HashArray[ i ].key < 0){
    if(HashArray[ i ].key == EMPTYKEY ){
        cout << "Pos: " << i <<", key: EMPTY" << endl;
      }else if(HashArray[ i ].key == DELETEDKEY ){
        cout << "Pos: " << i << ", key: DELETED" << endl;
      }
   }else{
        cout << "Pos: " << i << ", key: " << HashArray[i].key << ", value: " << HashArray[i].value << endl;
      }
  }
  cout << endl << "---------------------------------------" << endl << endl;
}

int linear_probe(int key, int i, int size){
  int hash = (key + i) % size;
  return hash;
}

void linear_insert(struct HashStruct * HashArray, struct HashStruct Hash, int size){
  int i =0;
  int index= 0;

  while (i < size){
    index = linear_probe(Hash.key, i, size);
    if(HashArray[ index ].key < 0){
      HashArray[ index ] = Hash;
      //cout << Hash.value << " stored at index: " << index <<endl;
      return;
    }else{
      //cout << "failed indexing at position " <<index << endl;  
      i++;
      
    }
  }
  cout << "Hash table overflow." << endl;
}

void linear_delete(struct HashStruct * HashArray, int key, int size){
  int i = 0;
  int index = 0;

  do{
    index = linear_probe(key, i, size);
    if (HashArray[ index ].value == key){
      
    break;
    }else{
      i++;
    }
  }while(i< size && HashArray[index].key >= DELETEDKEY);

}




void print_hash(struct HashStruct structIn){
  cout << "Struct Key: " << structIn.key << ", Struct Value: " << structIn.value << endl;
}



