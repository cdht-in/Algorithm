/*
	
Sort a linked list in O(n log n) time using constant space complexity.

Have you met this question in a real interview? Yes
Example
Given 1-3->2->null, sort it to 1->2->3->null.
	
*/

#include "../commonHeader.h"

class ListNode 
{
public:
	
    int val;
    ListNode *next;
    ListNode(int val) 
	{
        this->val = val;
        this->next = 0;
    }
};

vector<int> sortListHelper(ListNode* start, ListNode* end)
{
	vector<int> ret;
	if(start == end || start->next == 0)
	{
		ret.push_back(start->val);
		return ret;
	}
	//start < end
	ListNode* f = start, *s = start;
	
	while(f)
	{
		if(f->next == end)
			break;
		f = f->next;
		if(f->next == end)
			break;
		f = f->next;
		s = s->next;
	}
	
	ListNode* mid = s;
	
	vector<int> l = sortListHelper(start,mid);
	vector<int> r = sortListHelper(mid->next,end);
	
	//merge two list
	int i = 0;
	int j = 0;
	while(i < l.size() && j < r.size())
	{
		if(l[i] < r[j])
		{
			ret.push_back(l[i++]);
		}
		else
		{
			ret.push_back(r[j++]);
		}
	}
	
	while(i < l.size())
	{
		ret.push_back(l[i++]);
	}
	
	while(j < r.size())
	{
		ret.push_back(r[j++]);
	}
	
	return ret;
}

//merge sort
ListNode *sortList(ListNode *head) 
{
	if(head == 0 || head->next == 0)
		return head;
	vector<int> ret = sortListHelper(head,0);
	ListNode* p = head;
	for(int i : ret)
	{
		p->val = i;
		p = p->next;
	}
	return head;
}

ListNode *sortListI(ListNode *head)
{
	vector<int> ret;
	ListNode* p = head;
	while(p)
	{
		ret.push_back(p->val);
		p = p->next;
	}
	sort(ret.begin(),ret.end());
	p = head;
	int i = 0;
	while(p)
	{
		p->val = ret[i++];
		p = p->next;
	}
	return head;
}

int main()
{
	
}