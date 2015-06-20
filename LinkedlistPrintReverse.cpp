#include "Linkedlist(singly).h"
#include <cstdio>
#include <stack>

//O(n) time and space,use system call stack
void PrintReverseI (Node* n)
{
  if (n->next != 0)
    PrintReverseI (n->next);
  printf ("%d\n", n->val);
}

//O(n) time and space,use system call stack
void PrintReverseII(Node* n){
  std::stack<Node*> s;
  while(n != 0){
    s.push(n);
    n = n->next;
  }
  while(!s.empty()){
    printf("%d\n",s.top()->val);
    s.pop();
  }
}

//constance space could be done by reverse the the pointers
int main()
{
  Node a (1);
  Node b (2);
  Node c (3);
  a.next = &b;
  b.next = &c;
  PrintReverseII(&a);
}

