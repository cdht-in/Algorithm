#include "Linkedlist(singly).h"
#include <cstdio>

Node::Node (int val) : val (val), next() {}

Node::Node() : val(), next() {}

SinglyLinkedlist::SinglyLinkedlist() : size(), head (new Node() ), insertPtr (head) {}

void SinglyLinkedlist::Push (int val)
{
  insertPtr->next = new Node (val);
  insertPtr = insertPtr->next;
  size++;
}

void SinglyLinkedlist::PrintList()
{
  //get the first element
  Node* node = head->next;
  while (node != 0) {
    printf ("%d ", node->val);
    node = node->next;
  }
  printf ("\n");
}

/*
void foo (const SinglyLinkedlist* l)
{
  printf ("%d\n", * (l->Begin() ) );
}

int main()
{
  SinglyLinkedlist l;
  l.Push (1);
  l.Push (2);
  l.Push (3);
  l.PrintList();
  printf ("%d\n", *l.Begin() );
  //foo (&l);
}
*/
