/*
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You must do this in-place without altering the nodes' values.

  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
#include <cstdio>
#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};


void Print (ListNode* p)
{
  while (p) {
    printf ("%d ", p->val);
    p = p->next;
  }
  printf ("\n");
}

void reorderList (ListNode* head)
{
  if (head == 0 || head->next == 0)
    return;
  ListNode* p = head;
  ListNode* q = p;
  //find the mid
  while (q->next && q->next->next) {
    p = p->next;
    q = q->next->next;
  }
  //find the end
  if(q->next)
    q = q->next;
  //reverse the second half
  ListNode* prev = 0;
  ListNode* next = 0;
  ListNode* cur = p->next;
  p->next = 0;
  while(cur)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
  //traverse from the back to add each one to back to the list
  ListNode* tmp = 0;
  while(q)
    {
      tmp = q->next;
      q->next = head->next;
      head->next = q;
      //printf("%d ",q->val);
      head = head->next->next;
      q = tmp;
    }
}

//naive O(n^2)
void reorderListI(ListNode* head){
  if (head == 0 || head->next == 0 || head->next->next == 0)
    return;
  ListNode* p = head;
  while(p->next && p->next->next){
    ListNode* q = p;
    while(q->next->next)
      {
	q = q->next;
      }
    q->next->next = p->next;
    p->next = q->next;
    q->next = 0;
    p = p->next->next;
  }
}

int main()
{
  ListNode a (1);
  ListNode b (2);
  ListNode c (3);
  a.next = &b;
  b.next = &c;
  reorderList (&a);
  Print (&a);
}
