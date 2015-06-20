/*
  g  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

  For example,
  Given 1->2->3->3->4->4->5, return 1->2->5.
  Given 1->1->1->2->3, return 2->3.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};

/*
first implementation

ListNode* deleteDuplicates (ListNode* head)
{
  if (!head || !head->next)
    return head;
  ListNode* newhead = new ListNode (0);
  newhead->next = head;
  ListNode* s = head;
  ListNode* p = newhead;
  while (s) {
    bool flag = false;
    while (s && s->next && s->val == s->next->val) {
      ListNode* tmp = s->next->next;
      delete s->next;
      s->next = tmp;
      flag = true;
    }
    if (flag) {
      ListNode* tmp = s;
      p->next = s->next;
      s = p->next;
      delete tmp;
    }
    else {
      p = p->next;
      s = s->next;
    }
  }
  ListNode* tmp = newhead->next;
  delete newhead;
  return tmp;
}

*/


//second implementation
ListNode *deleteDuplicates(ListNode *head) {
	if(head == 0 || head->next == 0)
		return head;
	
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	
	ListNode* prev = dummyHead;
	ListNode* p = head;
	
	while(p){
		bool run = false;
		while(p && p->next != 0 && p->val == p->next->val)
		{
			run = true;
			p = p->next;
		}
		
		if(run)
		{
			//NOTE here p can only be stop at the last node
			//removed the duplicate
			prev->next = p->next;
		}
		else
		{
			prev = p;	
		}
		p = p->next;
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;
}


int main()
{
}

