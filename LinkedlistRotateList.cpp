/*
  Given a list, rotate the list to the right by k places, where k is non-negative.

  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.
*/
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};

/*
first implementation

//O(n) in time and O(1) in space
ListNode* rotateRight (ListNode* head, int k)
{
  if (!head || !head->next || !k)
    return head;
  ListNode* s = head;
  ListNode* f = s;
  int len = 0;
  while (f) {
    len++;
    f = f->next;
  }
  if ( (k % len) == 0)
    return head;
  else {
    k = k % len;
    f = head;
    for (int i = 0; i < k; i++)
      f = f->next;
  }
  //less than k nodes in the list
  while (f->next) {
    f = f->next;
    s = s->next;
  }
  //now s is the pointer at k position from the end
  ListNode* newhead = s->next;
  s->next = 0;
  s = newhead;
  while (s->next)
    s = s->next;
  s->next = head;
  return newhead;
}

*/

//second implementation




ListNode *rotateRight(ListNode *head, int k) {
	if(head == 0 || head->next == 0)
		return head;
	int c = 0;
	ListNode* p = head;
	while(p)
	{
		c++;
		p = p->next;
	}		
	
	if(c < k){
		k = k % c;
	}
	
	//this would take care of when k > c
	if(c == k || k == 0)
		return head;
	
	p = head;
	ListNode* prev = head;
	for(int i = 0; p && i < c - k; i++)
	{
		prev = p;
		p = p->next;
	}
	
	prev->next = 0;
	ListNode* newHead = p;
	
	while(p->next)
	{
		p = p->next;
	}
	
	p->next = head;
	head = newHead;
	return head;
}

int main()
{
  ListNode a (1);
  ListNode b (2);
  ListNode c (3);
  ListNode d (4);
  ListNode e (5);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = 0;
  ListNode* head = rotateRight (&a, 10);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
