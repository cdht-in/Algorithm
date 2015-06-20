/*

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

*/
#include <iostream>

using namespace std;

struct ListNode 
{
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(0) {}
};

//iterative
ListNode* reverseList(ListNode* head) 
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	
	ListNode* prev = 0;
	ListNode* cur = head;
	
	while(cur)
	{
		ListNode* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	
	head = prev;
	delete dummyHead;
	return head;
}

ListNode* reverseListIHelper(ListNode* node,ListNode*& head)
{
	if(node->next)
	{
		ListNode* nextNode = reverseListIHelper(node->next,head);
		nextNode->next = node;
	}
	else
	{
		head = node;
	}
	
	return node;
}

//recursive
ListNode* reverseListI(ListNode* head) 
{
	if(head == 0 || head->next == 0)
		return head;
	
	ListNode* newHead = 0;
	
	head = reverseListIHelper(head,newHead);
	head->next = 0;
	
	return newHead;
}

int main()
{
	
	
}