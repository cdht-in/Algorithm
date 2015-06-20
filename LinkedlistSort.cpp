/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};

ListNode* Split (ListNode* s, ListNode* e)
{
  ListNode* split = 0;
  if (!s) {
    split = 0;
    return split;
  }
  else if (!s->next) {
    split = s;
    return split;
  }
  else {
    ListNode* fast = s->next;
    ListNode* slow = s;
    while (fast){
      fast = fast->next;
      if (fast) {
        fast = fast->next;
        slow = slow->next;
      }
    }
    return slow;
  }
}

ListNode* MergeSorted (ListNode* h1, ListNode* h2)
{
  if (!h1)
    return h2;
  if (!h2)
    return h1;
  ListNode* h = 0;
  if (h1->val <= h2->val) {
    h = h1;
    h->next = MergeSorted (h1->next, h2);
  }
  else {
    h = h2;
    h->next = MergeSorted (h1, h2->next);
  }
  return h;
}

ListNode* MergeSort (ListNode* head, ListNode* tail)
{
  if (!head || !head->next)
    return head;
  ListNode* s = Split (head, tail);
  cout << "mid is " << s->val << endl;
  ListNode* h1 = MergeSort (head, s);
  ListNode* h2 = MergeSort (s->next, tail);
  return MergeSorted (h1, h2);
}


int main()
{
  ListNode a (2);
  ListNode b (3);
  ListNode c (1);
  ListNode d (4);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = 0;
  ListNode* l = MergeSort (&a, &d);
  cout << l->val << endl;
}
