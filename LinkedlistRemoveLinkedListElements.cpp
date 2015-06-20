
/*
	
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
	
*/


#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) 
{
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;
  
  ListNode* p = dummyHead;
  while(p && p->next)
  {
	  if(p->next->val == val)
	  {
		  ListNode* tmp = p->next;
		  p->next = p->next->next;
		  delete tmp;
	  }
	  else
	  {
	  	  p = p->next;
	  }
  }
  
  head = dummyHead->next;
  delete dummyHead;
  return head;
}

int main()
{
	
	
}