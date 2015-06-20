/*
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

  You should preserve the original relative order of the nodes in each of the two partitions.

  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};

/*
first implementaion

ListNode* partition (ListNode* head, int x)
{
  if (!head || !head->next)
    return head;
  ListNode* newhead = new ListNode (0);
  newhead->next = head;
  ListNode* p = newhead;
  while (p->next) {
    if (p->next->val < x)
      p = p->next;
    else {
      for (ListNode* find = p->next->next, *paren = p->next ; find; find = find->next, paren = paren->next) {
        if (find->val < x) {
          //insert it before the partion pointer
          ListNode* tmp1 = find;
          paren->next = find->next;
          ListNode* tmp2 = p->next;
          p->next = tmp1;
          p->next->next = tmp2;
          break;
        }
      }
      p = p->next;
    }
  }
  head = newhead->next;
  delete newhead;
  return head;
}

*/

//second implementation, O(n + n) time, and O(n) space

/*
ListNode *partition(ListNode *head, int x) {
	if(head == 0 || head->next == 0)
		return head;
	vector<int> smaller;
	vector<int> greater;
	
	ListNode* p = head;
	while(p)
	{
		if(p->val < x)
			smaller.push_back(p->val);
		else
			greater.push_back(p->val);
	}
	
	p = head;
	int i = 0;
	int j = 0;
	while(p)
	{
		if(i < smaller.size())
		{
			p->val = smaller[i++];
		}
		if(j < greater.size())
		{
			p->val = greater[j++];
		}
		p = p->next;
	}
	return head;
}
*/

//second implementation II
ListNode *partition(ListNode *head, int x) {
	if(head == 0 || head->next == 0)
		return head;
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	
	ListNode* lastSmallerNode = dummyHead;
	ListNode* smallerP = head;
	ListNode* smallerPPrev = dummyHead;
	//scran through to find the node that is smaller or less than x
	while(smallerP)
	{
		if(smallerP->val <= x)
		{
			//remove smaller p
			ListNode* smallerPtmp = smallerP;
			smallerP = smallerP->next;
			smallerPPrev->next = smallerP;
			
			//insert smaller p
			ListNode* tmp = lastSmallerNode->next;
			lastSmallerNode->next = smallerPtmp;
			lastSmallerNode->next->next = tmp;
			lastSmallerNode = lastSmallerNode->next;
		}
		else
		{
			smallerPPrev = smallerP;
			smallerP = smallerP->next;
		}
	}
	
	//head = dummyHead->next;
	//delete dummyHead;
	return dummyHead;
}

int main()
{
  ListNode a (1);
  ListNode b (1);
  a.next = &b;
  b.next = 0;
  ListNode* head = partition (&a, 1);
  while (head) {
    printf ("%d ", head->val);
    head = head->next;
  }
  printf ("\n");
}
