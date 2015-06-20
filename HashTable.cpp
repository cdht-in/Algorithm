/*
  simple hashtable implementation
*/

#include <cstdio>

struct LinkedList{
  int value;
  LinkedList* N;
  LinkedList():value(),N(0){}
};

class HashTable{
  int HashSlotSize;
  LinkedList** HashSlot;
  

  int HashFunction(int x){
    return x % HashSlotSize;
  }

public:
  HashTable(int* data, int size):HashSlotSize(10){
    HashSlot = new LinkedList*[HashSlotSize];
    for(int i=0;i<HashSlotSize;i++)
      HashSlot[i] = 0;
    for(int i=0;i<size;i++)
      Insert(data[i]); 
  }

  ~HashTable(){
  }

  void Insert(int x){
    int key = HashFunction(x);
    LinkedList* node = HashSlot[key];
    if(node != 0){
      //if presented, return
      do{
	if(node->value == x)
	  return;
	node = node->N;	
      }
      while(node->N != 0);
      //otherwise find the tail
      LinkedList* tmp = new LinkedList;
      tmp->value = x;
      node->N = tmp;
    }
    else
      {
	HashSlot[key] = new LinkedList;
	HashSlot[key]->value = x;
      }
  }

  
  int Remove(int x){
    int key = HashFunction(x);
    LinkedList* Parent = HashSlot[key];
    LinkedList* node = HashSlot[key];
    int i = 0;
    if(node != 0){
      do{
	if(i == 0 || node->value == x){
	  delete HashSlot[key];
	  HashSlot[key] = 0;
	  return x;
	}
	else{
	  LinkedList* tmp = node;
	  Parent->N = node->N;
	  delete tmp;
	  return x;
	}
	Parent = node;
	node = node->N;
	i++;
      }
      while(node != 0);
      return -1;
    }
    else
      //not in the hashtable
      return -1;
  }
  

  //print the table in no order
  void PrintHashTable(){
    for(int i=0;i<HashSlotSize;i++){
      if(HashSlot[i] != 0){
	for(LinkedList* node = HashSlot[i];node!=0;node=node->N)
	  printf("%d ",node->value);
      }
    }
    printf("\n");
  }
};

int main(){
  int foo[] = {1,2,3,4,5,6};
  HashTable bar(foo,sizeof(foo)/sizeof(int));
  bar.PrintHashTable();
  printf("%d\n",bar.Remove(3));
  printf("%d\n",bar.Remove(4)); 
  bar.PrintHashTable();
}
