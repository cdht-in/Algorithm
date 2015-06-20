/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
	
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};
  
ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(m == n)
		return head;
	if(head == 0 || head->next == 0)
		return head;
			
	ListNode* reversedListHead = head;
	ListNode* p = head->next;
	
	int c = 1;
	while(p && c <= m)
	{
		reversedListHead = p;
		p = p->next;
		c++;
	}
	
	ListNode* reversedListTail = p;
	
	ListNode* Prev = 0;
	
	//reverse the [m,n] portition of the linked list
	while(p && c <= n)
	{
		ListNode* tmp = p->next;
		p->next = Prev;
		Prev = p;
		p = tmp;
		c++;
	}

	reversedListTail->next = p;

	//now the p should stop at the n position
	reversedListHead->next = Prev;
	//ListNode* pNext = p->next;
	
	return head;
	
}

int main(){
	
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(5);
	
	node1->next = node2;
	
	ListNode* head = reverseBetween(node1,1,2);
}