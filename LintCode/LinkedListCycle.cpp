/*
	
Medium Linked List Cycle

47% Accepted
Given a linked list, determine if it has a cycle in it.



Have you met this question in a real interview? Yes
Example
Given -21->10->4->5, tail connects to node index 1, return true

Challenge
Follow up:
Can you solve it without using extra space?
	
*/

#include "../commonHeader.h"

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) 
	{
        this->val = val;
        this->next = 0;
    }
};

//with extra space
bool hasCycle(ListNode *head) 
{
	unordered_set<ListNode*> set;
	ListNode* p = head;
	while(p)
	{
		if(set.find(p) == set.end())
		{
			set.insert(p);
		}
		else
		{
			return true;
		}
		
		p = p->next;
	}
	return false;
}

bool hasCycleI(ListNode *head)
{
	if(head == 0)
		return false;
	
	ListNode* s = head, *f = head->next;
	
	while(s && f != s)
	{
		if(f)
		{
			f = f->next;
		}
		
		if(f)
		{
			f = f->next;
		}
		
		if(s)
		{
			s = s->next;
		}
	}
	return (s != 0 && f == s);
}

int main()
{
	
}