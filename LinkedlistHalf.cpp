
/*
  return the half position at the linked list
*/
#include <cstdio>


struct Node{
  static int size;
  static Node* head;
  int val;
  Node* next;

  Node(int val):val(val),next(){}

  static void Push(int val){
    if(size == 0){
      Node* newnode = new Node(val);
      head = newnode;
      size++;
    }
    else{
      Node* node = head;
      while(node->next != 0){
	node = node->next;
      }
      Node* newnode = new Node(val);
      node->next = newnode;
      size++;
    }
  }

  static void PrintList(){
    Node* node = head;
    for(int i = 0; i < size; i++){
      printf("%d ",node->val);
      node = node->next;
    }
    printf("\n");
  }

  //reverse two position in O(n)
  static void Swap(int x, int y){
    if(!(1 <= x && x <= y && y <= size))
      return;
    Node* node = head;
    Node* tmpx = 0;
    Node* tmpy = 0;
    for(int i = 1; i <= y; i++){
      if(i == x)
	tmpx = node;
      if(i == y){
	tmpy = node;
	break;
      }
      node = node->next;
    }
    int tmp = tmpx->val;
    tmpx->val = tmpy->val;
    tmpy->val = tmp;
  }

  static int Half(){
    if(size <= 2)
      return head->val;
    Node* f = head;
    Node* s = head;
    while(f){
      //take care of odd length case
      if(!f->next)
	break;
      f = f->next->next;
      s = s->next;
    }
    return s->val;
  }
};

int Node::size = 0;
Node* Node::head = 0;

int main(){
  for(int i = 1; i <= 3; i++)
    Node::Push(i);
  Node::PrintList();
  printf("%d\n",Node::Half());
}
