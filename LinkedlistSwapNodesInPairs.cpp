/*
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};

/*
first implementation

ListNode* swapPairs (ListNode* head)
{
  if (!head || !head->next)
    return head;
  ListNode* f = head->next;
  ListNode* s = head;
  int tmp = 0;
  do {
    tmp = f->val;
    f->val = s->val;
    s->val = tmp;
    if (!f->next || !f->next->next)
      break;
    f = f->next->next;
    s = s->next->next;
  }
  while (1);
  return head;
}

*/


//second implementation

ListNode *swapPairs(ListNode *head) {
        
}


int main()
{
}
