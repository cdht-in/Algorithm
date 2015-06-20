/*
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
*/

#include <cmath>
#include <cstdio>

struct Node {
  static int size;
  static Node* head;
  int val;
  Node* next;

  Node (int val) : val (val), next() {}

  static void Push (int val) {
    if (size == 0) {
      Node* newnode = new Node (val);
      head = newnode;
      size++;
    }
    else {
      Node* node = head;
      while (node->next != 0) {
        node = node->next;
      }
      Node* newnode = new Node (val);
      node->next = newnode;
      size++;
    }
  }

  static void PrintList() {
    Node* node = head;
    for (int i = 0; i < size; i++) {
      printf ("%d ", node->val);
      node = node->next;
    }
    printf ("\n");
  }

  //reverse two position in O(n)
  static void Swap (int x, int y) {
    if (! (1 <= x && x <= y && y <= size) )
      return;
    Node* node = head;
    Node* tmpx = 0;
    Node* tmpy = 0;
    for (int i = 1; i <= y; i++) {
      if (i == x)
        tmpx = node;
      if (i == y) {
        tmpy = node;
        break;
      }
      node = node->next;
    }
    int tmp = tmpx->val;
    tmpx->val = tmpy->val;
    tmpy->val = tmp;
  }

  //idea is to point two pointers to the first and second node, then move them, remove the frontal pointer if duplicates are found
  static void RemoveDuplicate() {
    if (size < 2)
      return;
    Node* f = head;
    Node* s = head->next;
    while (s != 0) {
      //duplicate, delete the one s is pointing at
      if (f->val == s->val) {
        f->next = s->next;
        delete s;
        s = f->next;
        size--;
      }
      //move both pointers forward
      else {
        f = f->next;
        s = s->next;
      }
    }
  }
};


int Node::size = 0;
Node* Node::head = 0;

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Have you been asked this question in an interview?
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (NULL) {}
};


/*

ListNode *deleteDuplicates(ListNode *head) {
  if(!head || !head->next)
    return head;
  ListNode* p = head;
  while(p && p->next){
    if(p->val == p->next->val){
      ListNode* tmp = p->next;
      p->next = p->next->next;
      delete tmp;
    }
    else
      p = p->next;
  }
  return head;
}

*/


//second implementation

ListNode *deleteDuplicates(ListNode *head) {
	if(head == 0 || head->next == 0)
		return head;
	
	ListNode* p = head;
	while(p && p->next != 0)
	{
		if(p->val == p->next->val)
		{
		   p->next = p->next->next;
		}
		else{
			p = p->next;
		}
	}
	return head;
}




int main()
{
  int foo[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 5};
  for (int i = 0; i < sizeof (foo) / sizeof (int); i++) {
    Node::Push (foo[i]);
  }
  Node::PrintList();
  Node::RemoveDuplicate();
  Node::PrintList();
}
