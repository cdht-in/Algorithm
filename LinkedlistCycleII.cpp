/*
	Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
  };
  
ListNode *detectCycle(ListNode *head) {
	if(head == 0 || head->next == 0)
		return 0;
	
	ListNode* fastP = head;
	ListNode* slowP = head;
	int fastPPath = 0;
	int slowPPath = 0;
	while(1)
	{
		//no cycle
		fastP = fastP->next;
		fastPPath++;
		if(fastP == 0){
			break;
		}
		fastP = fastP->next;
		fastPPath++;
		if(fastP == 0){
			break;
		}
		
		slowP = slowP->next;
		slowPPath++;	
		
		//detact a cycle
		if(slowP == fastP)
		{
			//find where the cycle starts
			slowP = head;
			while(slowP != fastP)
			{
				slowP = slowP->next;
				fastP = fastP->next;
				c++;
			}
			return slowP;
		}
	}
	return 0;
}

int main(){
	
	
}