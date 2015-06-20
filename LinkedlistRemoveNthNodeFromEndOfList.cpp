
/*
  return the nth node from the end from a singly linked list
*/
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

  static int NthFromEnd (int n) {
    //making sure if there are more nodes in the linkedlist
    if (n < size) {
      Node* p = head;
      for (int i = 0; i < n; i++)
        p = p->next;
      Node* nth = head;
      //when the faster pointer hit the end, the slower pointer is at the nth from the end
      while (p) {
        p = p->next;
        nth = nth->next;
      }
      return nth->val;
    }
    else
      return head->val;
  }

};

int Node::size = 0;
Node* Node::head = 0;

/*
  Given a linked list, remove the nth node from the end of list and return its head.
  For example,
  Given linked list: 1->2->3->4->5, and n = 2.
  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};

ListNode* removeNthFromEnd (ListNode* head, int n)
{
  if (!head)
    return head;
  ListNode* newhead = new ListNode (0);
  newhead->next = head;
  ListNode* p = head;
  //move ahead n - 1 steps to offset the newhead
  for (int i = 0; p->next && i < n - 1; i++) {
    p = p->next;
  }
  ListNode* q = newhead;
  while (p->next) {
    p = p->next;
    q = q->next;
  }
  q->next = q->next->next;
  head = newhead->next;
  delete newhead;
  return head;
}


//second implementation

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if(head == 0)
		return head;
	ListNode* f = head;
	for(int i = 0; f && i < n; i++)
	{
		f = f->next;
	}
	ListNode* s = head;
	ListNode* prev = 0;
	while(f)
	{
		f = f->next;
		prev = s;
		s = s->next;
	}
	
	
	//remove the head
	if(prev == 0)
	{
		head = head->next;
		return head;
	}
	
	prev->next = s->next;
	return head;
}


int main()
{
  for (int i = 1; i <= 10; i++) {
    Node::Push (i);
  }
  Node::PrintList();
  printf ("%d\n", Node::NthFromEnd (9) );
}
