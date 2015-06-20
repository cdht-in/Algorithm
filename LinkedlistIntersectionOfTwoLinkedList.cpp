/*
	
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA == 0 || headB == 0)
		return 0;
	int lenA = 0;
	ListNode* p = headA;
	while(p != 0)
	{
		lenA++;
		p = p->next;
	}
	int lenB = 0;
	p = headB;
	while(p != 0)
	{
		lenB++;
		p = p->next;
	}
	
	if(lenA >= lenB)
	{
		int diff = lenA - lenB;
		for(int i = 0; i < diff; i++)
			headA = headA->next;
		while(headA && headB)
		{
			//intersection
			if(headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
	}
	//LenA < LenB
	else
	{
		int diff = lenB - lenA;
		for(int i = 0; i < diff; i++)
			headB = headB->next;
		while(headA && headB)
		{
			//intersection
			if(headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
	}
	//no intersection
	return 0;
}


int main(){
	
	
}