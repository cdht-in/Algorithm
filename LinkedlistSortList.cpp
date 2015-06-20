/*
	
	Sort a linked list in O(n log n) time using constant space complexity.
*/

struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(0) {}
};


ListNode* MergeLinkedList(ListNode* a, ListNode* b){
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	ListNode* node = 0;
	if(a->val <= b->val)
	{
		node = a;
		a = a->next;
	}
	else
	{
		node = b;
		b = b->next;
	}
	ListNode* head = node;
	while(a != 0 && b != 0)
	{
		if(a->val <= b->val)
		{
			head->next = a;
			a = a->next;
		}
		else
		{
			head->next = b;
			b = b->next;
		}
		head = head->next;
	}
	if(a == 0)
		head->next = b;
	else
		head->next = a;
	
	return node;
}

ListNode *sortList(ListNode *head) {
	if(head == 0 || head->next == 0)
		return head;
	ListNode* fastP = head;
	ListNode* slowP = head;
	
	while(fastP->next != 0)
	{
		fastP = fastP->next->next;
		if(fastP == 0)
			break;
		slowP = slowP->next;
	}
	//the slow pointer would stop at the half position of the list
	ListNode* rightP = slowP->next;
	slowP->next = 0;
	
	ListNode* leftHalf = sortList(head);
	ListNode* rightHalf = sortList(rightP);
	
	return MergeLinkedList(leftHalf,rightHalf);
}


int main(){
	
}