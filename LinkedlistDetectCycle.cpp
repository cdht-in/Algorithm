#include <cstdio>

struct ListNode {
  int value;
  ListNode* next;
};

/*if there exist a cycle inside the linked list, there are at least two nodes in the list. Therefore, firstly check if there are at least two nodes. If pass, then pick two pointers starting at the beginning of the list, one moves one step at a time, the other moves two steps at a time, if there is a cycle, eventually those two pointers will be pointing at a same memory location.

  Time Complexity: Since the two pointers move at the same time traversing the entire list, it takes O(n)
*/
bool hasLoops (ListNode* head)
{
  ListNode* fast, *slow;
  fast = slow = head;
  while (1) {
    //if the the fast pointer reaches the end, acyclic
    if ( !fast || !fast->next )
      return false;
    //else if the fast catch up with the slow one, cyclic
    else if ( fast == slow || fast->next == slow )
      return true;
    else {
      slow = slow->next;
      fast = fast->next->next;
    }
  }
}
//assume there is a loop in the list
ListNode* LoopBeginning (ListNode* mylist, int& len)
{
  //slow ptr
  ListNode* sptr = mylist;
  //fast ptr
  ListNode* fptr = sptr;;
  //if the slow ptr reachs the end of the linkedlist and hit meeting with the fast pointer, there is no cycle
  while (sptr != 0) {
    //move one step at a time
    sptr = sptr->next;
    //move two steps at a time
    fptr = fptr->next->next;
    //if they meet
    if (sptr == fptr)
      break;
  }
  //now take the fast ptr back to the origin and moves at one step at a time,
  //the next time when those two pointers meet, it is the beginning
  fptr = mylist;
  while (fptr != sptr) {
    fptr = fptr->next;
    sptr = sptr->next;
  }
  //now find the length of the cycle,traverse one pointer one step at a time until it hit where it came from
  int tmplen = 1;
  sptr = sptr->next;
  while (fptr != sptr) {
    sptr = sptr->next;
    tmplen++;
  }
  len = tmplen;
  return fptr;
}

/*
  Given a linked list, determine if it has a cycle in it.
  Follow up:
  Can you solve it without using extra space?
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};

bool hasCycle (ListNode* head)
{
  if(!head || !head->next)
    return false;
  ListNode* f = head;
  ListNode* s = head;
  while(f){
    if(f->next)
      f = f->next;
    if(f)
      f = f->next;
    if(s->next)
      s = s->next;
    if(f == s)
      return true;
  }
  return false;
}

int main()
{
  ListNode a;
  a.value = 1;
  ListNode b;
  b.value = 2;
  a.next = &b;
  printf ("%d\n", hasLoops (&a) );
  //int len = 0;
  //ListNode* start = LoopBeginning (&a, len);
s  //printf ("loop starts at %d with len %d\n", start->value, len);
}


