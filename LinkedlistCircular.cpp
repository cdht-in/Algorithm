#include <cstdio>

struct Node{
  int val;
  Node* next;
  Node():val(),next(0){}
  Node(int val):val(val),next(){}
};

struct SinglyLinkedlist{
  int size;
  Node* head;
  Node* insertPtr;
  
  SinglyLinkedlist():size(),head(new Node()),insertPtr(head){}
  
  void Push(int val){
    insertPtr->next = new Node(val);
    insertPtr = insertPtr->next;
    size++;
  }
  
  void PrintList(){
    //get the first element
    Node* node = head->next;
    while(node != 0)
      {
	printf("%d ",node->val);
	node = node->next;
      }
    printf("\n");
  }

  inline Node* getHead(){
    if(size > 0)
      return head->next;
  }
};

int main(){
  SinglyLinkedlist list;
  for(int i = 1; i <= 5; i++){
    list.Push(i);
  }
  list.PrintList();
}
