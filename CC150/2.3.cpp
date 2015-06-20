/*
	
Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.

EXAMPLE

Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e

*/
struct ListNode{
	int val;
	ListNode* next;
};

ListNode* removeMiddle(ListNode* node)
{
	if(node == 0 || node->nex)
	{
		return 0;
	}
	
	ListNode* f = node;
	ListNode* s = node;
	ListNode* prev = 0;
	while(f)
	{
		f = f->next;
		if(f == 0)
			break;
		f = f->next;
		if(f == 0)
			break;
		prev = s;
		s = s->next;
	}
	
	//s is at the middle
	ListNode* tmp = s;
	prev->next = s->next;
	delete tmp;
	return node;
}

//now node is the middle node
bool removeMiddle(ListNode* c)
{
	//swap the values after it and delete the next value
	if(c==0 || c->next==0) 
		return false;
	node *q = c->next;
	c->data = q->data;
	c->next = q->next;
	delete q;
	return true;
}




int main()
{
	
	
}