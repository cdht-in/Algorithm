/*
	
	Write code to remove duplicates from an unsorted linked list.
	
FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?

*/
#include <unordered_set>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
	

//approach 1 with hash table
void RemoveDuplicate(ListNode* node)
{
	ListNode* p = node;
	unordered_set<int> set;
	
	ListNode* prev = 0;
	while(p)
	{
		if(set.find(p->val) == set.end())
		{
			set.insert(p->val);
			prev = p;
			p = p->next;
		}
		else
		{
			ListNode* tmp = p;
			prev->next = p->next;
			delete tmp;
			p = prev->next;
		}
	}
}

//brute force apprach
void RemoveDuplicateI(ListNode* node)
{
	if(node == 0)
		return;
	ListNode* p = node;
	while(p)
	{
		ListNode* prev = p;
		for(ListNode* q = p->next; q ;)
		{
			if(q->val == p->val)
			{
				prev->next = q->next;
				delete q;
				q =  prev->next;
			}
			else
			{
				prev = q;
				q = q->next;
			}
		}
		
		p = p->next;
	}
	
}



int main()
{
	
	
}