/*
	
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
	
*/

#include <iostream>

using namespace std;

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};

bool isPalindrome(ListNode* head) 
{
	if(head == 0)
		return false;
	ListNode* f = head;
	ListNode* s = head;
	while(f)
	{
		if(f->next == 0)
			break;
		f = f->next;
		if(f->next == 0)
			break;
		f = f->next;
		s = s->next;
	}
	
	ListNode* prev = s;
	s = s->next;
	while(s)
	{
		ListNode* tmp = s->next;
		s->next = prev;
		prev = s;
		s = tmp;
	}
	
	//check for palindromic string
	ListNode* l = head;
	ListNode* r = prev;
	
	while(1)
	{
		if(l->val != r->val)
			return false;
		r = r->next;
		if(l == r)
			break;
		l = l->next;
		if(l == r)
			break;
	}
	
	return true;
}

int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	a->next = b;
	cout << isPalindrome(a) << endl;
}
