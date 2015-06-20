/*
  merge two sorted list into one
*/

/*
  #define NULL 0
  #include <cstdio>

  class Node {
  public:
  int value;
  Node* next;

  Node() {
  value = 0;
  next = NULL;
  }
  Node (int v, Node* n) {
  value = v;
  next = n;
  }
  };

  //two pointers pointing at the head of two list intially
  static Node* mergeLists (Node* head1, Node* head2)
  {
  //if head1 is null, return head2
  if (head1 == NULL)
  return head2;
  //if head2 is null, return head1
  if (head2 == NULL)
  return head1;
  //they are nodes in two lists
  Node* i = head1;
  Node* j = head2;
  Node* head = NULL;
  Node* headptr = NULL;
  //select the new head
  if (i->value < j->value) {
  head = new Node (i->value, NULL);
  i = i->next;
  headptr = head;
  }
  else {
  head = new Node (j->value, NULL);
  j = j->next;
  headptr = head;
  }
  //now traverse the two list at the same time to populate the new list
  while (i != NULL && j != NULL) {
  //append the smaller of the two pointers
  if (i->value < j->value) {
  headptr->next = new Node (i->value, NULL);
  i = i->next;
  }
  else {
  headptr->next = new Node (j->value, NULL);
  j = j->next;
  }
  headptr = headptr->next;
  }
  //head1 list first runs out of nodes
  if (i == NULL) {
  //append the rest of nodes from head2 to the new list
  while (j != NULL) {
  headptr->next = new Node (j->value, NULL);
  j = j->next;
  headptr = headptr->next;
  }
  }
  //head2 list first runs out of nodes
  else {
  while (i != NULL) {
  headptr->next = new Node (i->value, NULL);
  i = i->next;
  headptr = headptr->next;
  }
  }
  return head;
  }

  void print (Node* n)
  {
  while (n != NULL) {
  printf ("%d ", n->value);
  n = n->next;
  }
  printf ("\n");
  }
*/

/*

  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};

/*
first implementation


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if(!l1)
    return l2;
  if(!l2)
    return l1;
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  ListNode* head;
  if(p1->val < p2->val){
    head = new ListNode(p1->val);
    p1 = p1->next;
  }
  else{
    head = new ListNode(p2->val);
    p2 = p2->next;
  }
  ListNode* p = head;
  while(p1 && p2){
    if(p1->val < p2->val){
      p->next = new ListNode(p1->val);
      p1 = p1->next;
    }
    else{
      p->next = new ListNode(p2->val);
      p2 = p2->next;
    }
    p = p->next;
  }
  if(!p1){
    while(p2){
      p->next = new ListNode(p2->val);
      p = p->next;
      p2 = p2->next;
    }
  }
  else{
    while(p1){
      p->next = new ListNode(p1->val);
      p = p->next;
      p1 = p1->next;
    }
  }
  return head;
}


//O(nm(log(n))) == O(n^2 * log(n))
ListNode* mergeKLists (vector<ListNode*>& lists)
{
  //min-heap
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < lists.size(); i++) {
    ListNode* p = lists[i];
    while (p) {
      q.push (p->val);
      p = p->next;
    }
  }
  ListNode* head = new ListNode(0);
  ListNode* p = head;
  while(!q.empty()){
    ListNode* tmp = new ListNode(q.top());
    q.pop();
    p->next = tmp;
    p = tmp;
  }
  ListNode* tmp = head->next;
  delete head;
  return tmp;
}
*/


//second implementation

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if(l1 == 0 && l2 == 0)
		return 0;
	if(l1 == 0)
		return l2;
	if(l2 == 0)
		return l1;
	
	ListNode* dummyHead = new ListNode(0);
	ListNode* d = dummyHead;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	
	while(p1 && p2)
	{
		if(p1->val < p2->val)
		{
			d->next = new ListNode(p1->val);
			p1 = p1->next;
		}
		else
		{
			d->next = new ListNode(p2->val);
			p2 = p2->next;
		}
		d = d->next;
	}
	
	if(p1 == 0)
	{
		while(p2)
		{
			d->next = new ListNode(p2->val);
			p2 = p2->next;
			d = d->next;
		}
	}
	if(p2 == 0)
	{
		while(p1)
		{
			d->next = new ListNode(p1->val);
			p1 = p1->next;
			d = d->next;
		}
	}
	
	
	ListNode* head = dummyHead->next;
	delete dummyHead;
	return head;
	
}

int main()
{
  /*
    Node l1 (1, NULL);
    Node l2 (2, NULL);
    Node l3 (3, NULL);
    Node l4 (4, NULL);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    print (&l1);
    Node s1 (1, NULL);
    Node s2 (3, NULL);
    Node s3 (5, NULL);
    Node s4 (7, NULL);
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &s4;
    print (&s1);
    Node* head = mergeLists(&l1,&s1);
    print (head);
  */
}
