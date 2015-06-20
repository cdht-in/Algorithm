/*
  shuffle a list of integers
*/
#include <stdio.h>

typedef struct Node Node;

struct Node {
  int val;
  Node* next;
};


void Print(Node* node){
  while(node){
    printf("%d ",node->val);
    node = node->next;
  }
  printf("\n");
}

int main()
{
  Node a;
  Node b;
  Node c;
  a.val = 1;
  a.next = &b;
  b.val = 2;
  b.next = &c;
  c.val = 3;
  c.next = 0;
  Print(&a);
}
