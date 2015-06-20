/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
	
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};

//this would reverse the linked list to {1,4,2,3}
void reorderListI(ListNode *head) {
	if(head == 0 || head->next == 0 || head->next->next == 0)
		return;
	ListNode* prev = head->next;
	ListNode* p = prev->next;
	prev->next = 0;
	while(p != 0)
	{
		ListNode* prevNext = p;
		ListNode* pNext = p->next;
		p->next = prev;
		p = pNext;
		prev = prevNext;
	}
	head->next = prev;
}

 void reorderList(ListNode *head) {
	 if(head == NULL) return;
	           // find the median node
	           ListNode* fast = head;
	           ListNode* slow = head;
	           while(true)
	           {
	               fast = fast->next;
	               if(fast == NULL)
	                  break;
	              fast = fast->next;
	              if(fast == NULL)
	                  break;
	              slow = slow->next;
	          }
	          
	          if(slow == NULL) return;
	          
	          // reverse second half of link list
	          ListNode* cur = slow;
	          ListNode* pre = slow->next;
	          cur->next = NULL;
	          while(pre!=NULL)
	          {
	              ListNode* temp = pre->next;
	              pre->next = cur;
	             cur = pre;
	              pre = temp;
	          }
	          
	          // merge two lists
	          ListNode* first = head;
	          ListNode* second = cur;
	          
	          while(second!= NULL&& first!=NULL && first!=second)
	          {
	              ListNode* temp = second->next;
	              second->next = first->next;
	              first->next = second;
	              first = second->next;
	              second = temp;
	          }
 }
 
int main(){
	
	
	
}