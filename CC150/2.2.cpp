/*
	Implement an algorithm to find the nth to last element of a singly linked list
*/

struct ListNode
{
	int val;
	ListNode* next;
};


int findNthFromLast(ListNode* node,int n)
{
	int i = 0;
	ListNode* p = node;
	for(;p && i < n; i++)
	{
		p = p->next;
	}
	if(p == 0)
		return 0;
	ListNode* s = node;
	while(p)
	{
		p = p->next;
		s = s->next;
	}
	return s->val;
}
