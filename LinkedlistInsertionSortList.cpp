/*
	Sort a linked list using insertion sort.
*/
#include <climits>



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};
	  
//O(n^2)
ListNode *insertionSortList(ListNode *head) {
	if(head == 0 || head->next == 0)
		return head;
	ListNode* position = head;
	while(position != 0)
	{
		int min = position->val;
		ListNode* minP = position;
		
		ListNode* p = position->next;
		
		while(p != 0)
		{
			if(p->val < min)
			{
				min = p->val;
				minP = p;
			}
			p = p->next;
		}
		//swap the values
		int tmp = position->val;
		position->val = minP->val;
		minP->val = tmp;
		
		position = position->next;
	}
	return head;
}

int main(){

}