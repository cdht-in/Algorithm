/*
  return the half position at the linked list
*/
#include <cstdio>

struct Node {
  static int size;
  static Node* head;
  static Node* insertPtr;
  int val;
  Node* next;

  Node() : val(), next (0) {}
  Node (int val) : val (val), next() {}

  static void Push (int val) {
    insertPtr->next = new Node (val);
    insertPtr = insertPtr->next;
    size++;
  }

  static void PrintList() {
    //get the first element
    Node* node = head->next;
    while (node != 0) {
      printf ("%d ", node->val);
      node = node->next;
    }
    printf ("\n");
  }

  static void Reverse() {
    if (head->next == 0)
      return;
    //first element of the list
    Node* p = head->next;
    //previous element
    Node* r = 0;
    //next element
    Node* n = 0;
    while (p != 0) {
      //record the next step
      n = p->next;
      //reverse the current pointer, pointing at the previous node
      p->next = r;
      //advance the previous pointer
      r = p;
      //advance the current pointer
      p = n;
    }
    //assign the last element
    head->next = r;
  }
};

int Node::size = 0;
Node* Node::head = new Node;
Node* Node::insertPtr = head;;

/*
  Reverse a linked list from position m to n. Do it in-place and in one-pass.

  For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,

  return 1->4->3->2->5->NULL.

  Note:
  Given m, n satisfy the following condition:
  1 ≤ m ≤ n ≤ length of list.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (NULL) {}
};

ListNode* reverseBetween (ListNode* head, int m, int n)
{
  if (!head || !head->next || (m == n) )
    return head;
  ListNode* newhead = new ListNode(0);
  newhead->next = head;
  ListNode* parent = newhead;
  ListNode* cur = head;
  for (int i = 0; i < m - 1; i++) {
    cur = cur->next;
    parent = parent->next;
  }
  
  ListNode* tail = cur;
  ListNode* prev = parent;
  ListNode* next = 0;
  for (int i = 0; i <= n - m; i++) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  parent->next = prev;
  tail->next = cur;
  head = newhead->next;
  delete newhead;
  return head;
}

int main()
{
}
