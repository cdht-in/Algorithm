/*
	
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
	
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};

bool isPalindromeI(ListNode* head)
{
	ListNode* p = head;
	vector<int> ret;
	while(p)
	{
		ret.push_back(p->val);
		p = p->next;
	}
	
	for(int i = 0; i < ret.size() / 2 ; i++)
	{
		if(ret[i] != ret[ret.size() - 1 - i])
			return false;
	}
	
	return true;
}

//leetcode time list exceed for some reason
bool isPalindrome(ListNode* head) 
{	
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
	
	ListNode* mid = s;
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
	
	/*
	while(r != mid)
	{
		if(l->val != r->val)
			return false;
		r = r->next;
		l = l->next;
	}
	*/
	
	//restore the second half list
	r = prev;
	prev = 0;
	while(r != mid)
	{
		ListNode* tmp = r->next;
		r->next = prev;
		prev = r;
		r = tmp;
	}
	
	ListNode* tmp = head;
	while(tmp)
	{
		cout << tmp->val << endl;
		tmp = tmp->next;
	}
	
	return true;
}

int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	a->next = b;
	b->next = c;
	cout << isPalindrome(a) << endl;
}
