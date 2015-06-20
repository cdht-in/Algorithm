#ifndef LINKEDLISTSINGLY_H
#define LINKEDLISTSINGLY_H

struct Node {
  int val;
  Node* next;
  Node();
  Node (int val);
};

struct SinglyLinkedlist {
  Node* head;
  Node* insertPtr;
  int size;
  SinglyLinkedlist();
  void Push(int val);
  void PrintList();
  inline const Node* Begin() const {
    if (size > 0)
      return head->next;
  }

  inline Node* Begin() {
    if (size > 0)
      return head->next;
  }
};

#endif
