
#include <cstdio>
/*
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
  Return a deep copy of the list.
*/

struct Node {
  int val;
  Node* next;
  Node* random;
  Node() : val(), next(), random() {}
  Node (int val) : val (val), next(), random() {}
};

struct SinglyLinkedlist {
  int size;
  Node* head;
  Node* insertPtr;

  SinglyLinkedlist() : size(), head (new Node() ), insertPtr (head) {}

  void Push (int val) {
    insertPtr->next = new Node (val);
    insertPtr = insertPtr->next;
    size++;
  }

  void PrintList() {
    //get the first element
    Node* node = head->next;
    while (node != 0) {
      printf ("%d ", node->val);
      node = node->next;
    }
    printf ("\n");
  }

  //print the node sequentially, but follow the random pointer
  void PrintListWithRandom() {
    //get the first element
    Node* node = head->next;
    while (node != 0) {
      printf ("%d ", node->val);
      if (node->random != 0) {
        Node* r = node->random;
        while (r != 0) {
          printf ("r %d ", r->val);
          r = r->random;
        }
        printf ("\n");
      }
      node = node->next;
    }
    printf ("\n");
  }

  inline Node* getHead() {
    if (size > 0)
      return head->next;
    return 0;
  }

  inline Node* getInsertPtr() {
    return insertPtr;
  }
};

//return hops from the head to the current node
int //-1:cur points to 0, >=0: hops from the head
GetOffset (Node* head,
           Node* cur)
{
  int hop = 0;
  if (cur == 0)
    return -1;
  while (head != cur) {
    hop++;
    head = head->next;
  }
  return hop;
}

static SinglyLinkedlist* ListDeapCopy (SinglyLinkedlist* list)
{
  //cloned list
  SinglyLinkedlist* ret = new SinglyLinkedlist;
  Node* head = list->getHead();;
  Node* p = head;
  for (; p != 0; p = p->next) {
    //create anew node that is a clone of the node being copied
    ret->Push (p->val);
    //find the where the random pointer is pointing to in the original list, e.g offset from the list head
    int hop = GetOffset (head, p->random);
    if (hop >= 0) {
      //now the cloned node needs to point to the same location within the new list
      Node* j = ret->getHead();
      for (int i = 0; i < hop; i++)
        j = j->next;
      //point the current node to the node;
      ret->getInsertPtr()->random = j;
    }
    //random pointer of the original node points to 0
    else
      ret->getInsertPtr()->random = 0;
  }
  return ret;
}

int main()
{
  SinglyLinkedlist list;
  for (int i = 1; i <= 5; i++)
    list.Push (i);
  Node* second = list.getHead()->next;
  //points to the first element
  second->random = list.getHead();
  //pints to the third element
  Node* forth = list.getHead()->next->next->next;
  forth->random = second->next;
  list.PrintListWithRandom();
  SinglyLinkedlist* clonelist = ListDeapCopy (&list);
  clonelist->PrintListWithRandom();
}
