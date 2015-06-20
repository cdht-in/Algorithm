/*
  Sort a linked list using insertion sort.
*/

#include <stack>
#include <cstdio>

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};


//O(n^2) time and O(n) space, in place
ListNode* insertionSortList (ListNode* head)
{
  if (!head || !head->next)
    return 0;
  std::stack<ListNode*> s;
  s.push (head);
  ListNode* p1 = head->next;
  ListNode* p;
  while (p1) {
    ListNode* p2 = (s.empty() ) ? head : s.top();
    //catch up the history
    while (p2->next != p1) {
      s.push (p2);
      p2 = p2->next;
    }
    //find the correct insertion spot by going ba
    p = p1;
    while (!s.empty() && s.top()->val > p->val) {
      int tmp = s.top()->val;
      s.top()->val = p->val;
      p->val = tmp;
      p = s.top();
      s.pop();
    }
    p1 = p1->next;
  }
  return head;
}


//not in place
ListNode* insertionSortListI (ListNode* head)
{
  if (!head)
    return 0;
  if (!head->next)
    return head;
  ListNode* p = head->next;
  ListNode* np = new ListNode (head->val);
  while (p) {
    if (p->val <= np->val) {
      //add it before the new head, and reassign the new head
      ListNode* tmp = new ListNode (p->val);
      tmp->next = np;
      np = tmp;
    }
    else {
      //add it after the biggest in the list
      ListNode* tmp = np;
      while (tmp->next && p->val >= tmp->next->val)
        tmp = tmp->next;
      //inserp->val < p->val && p->val < insertp->next->val
      ListNode* next = tmp->next;
      tmp->next = new ListNode (p->val);
      tmp->next->next = next;
    }
    p = p->next;
  }
  return np;
}

int main()
{
  ListNode a (4);
  ListNode b (2);
  ListNode c (1);
  ListNode d (3);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  ListNode* p = &a;
  while (p) {
    printf ("%d ", p->val);
    p = p->next;
  }
  printf ("\n");
  p = insertionSortListI (&a);
  while (p) {
    printf ("%d ", p->val);
    p = p->next;
  }
  printf ("\n");
}
