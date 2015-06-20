/*
  Add number represented in linkdelist,and return the sum in a linked list
*/

#include <queue>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

/*
first implementation


//add two reversed list e.g 123 = 3->2->1
void AddReversedNumber (const SinglyLinkedlist* n1, const SinglyLinkedlist* n2)
{
  const Node* n1p = n1->Begin();
  const Node* n2p = n2->Begin();
  SinglyLinkedlist ret;
  //carry bit
  int carry = 0;
  //t digit
  int t = 0;
  //b digit
  int b = 0;
  //when not reach the end
  while (n1p != 0 || n2p != 0) {
    //if there are digits left in n1
    if (n1p != 0) {
      t = n1p->val;
      n1p = n1p->next;
    }
    //if there no digits, singly add 0
    else
      t = 0;
    if (n2p != 0) {
      b = n2p->val;
      n2p = n2p->next;
    }
    else
      b = 0;
    //if the sum is greater or equal to 10, save the carry
    if (t + b + carry >= 10) {
      //add those two digits and the carry from previous run
      ret.Push (t + b + carry - 10);
      carry = 1;
    }
    else {
      //add those two digits and the carry from previous run
      ret.Push (t + b + carry);
      carry = 0;
    }
  }
  //print out ret list
  ret.PrintList();
}


struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (NULL) {}
};


//return a third list for the sum
ListNode* addTwoNumbers (ListNode* l1, ListNode* l2)
{
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  int carry = 0;
  int tmp1 = 0;
  int tmp2 = 0;
  int rem = 0;
  ListNode* head = new ListNode (0);
  ListNode* ret = head;
  while (1) {
    if (!l1) {
      tmp1 = l1->val;
      l1 = l1->next;
    }
    else
      tmp1 = 0;
    if (!l2) {
      tmp2 = l2->val;
      l2 = l2->next;
    }
    else
      tmp2 = 0;
    carry = (tmp1 + tmp2) / 10;
    rem = (tmp1 + tmp2) % 10;
    ret->val = carry + rem;
    if (!l1 && !l2)
      break;
    ret->next = new ListNode (0);
    ret = ret->next;
  }
  return ret;
}

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//second implementation
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	if(l1 == 0 && l2 == 0)
		return 0;
	if(l1 == 0)
		return l2;
	if(l2 == 0)
		return l1;
	
	int carry = 0;
	ListNode* dummyHead = new ListNode(0);
	ListNode* p = dummyHead;
	
	ListNode* l1p = l1;
	ListNode* l2p = l2;
	
	while(l1p && l2p)
	{
		int digit = (l1p->val + l2p->val + carry) % 10;
		carry = (l1p->val + l2p->val + carry) / 10;
		p->next = new ListNode(digit);
		p = p->next;
		
		l1p = l1p->next;
		l2p = l2p->next;
	}
	
	
	//if l1p is longer
	while(l1p)
	{
		int digit = (l1p->val + carry) % 10;
		carry = (l1p->val + carry) / 10;
		p->next = new ListNode(digit);
		p = p->next;
		l1p = l1p->next;
	}
	
	//if l2p is longer
	while(l2p)
	{
		int digit = (l2p->val + carry) % 10;
		carry = (l2p->val + carry) / 10;
		p->next = new ListNode(digit);
		p = p->next;
		l2p = l2p->next;
	}
	
	if(carry)
	{
		p->next = new ListNode(carry);
		p = p->next;
	}
	
	
	ListNode* head = dummyHead->next;
	delete dummyHead;
	
	return head;
	
	/*	
	
	
	int l1n = 0;
	ListNode* p = l1;
	while(p)
	{
		l1n *= 10;
		l1n += p->val;
		p = p->next;
	}
	
	p = l2;
	int l2n = 0;
	while(p)
	{
		l2n *= 10;
		l2n += p->val;
		p = p->next;
	}
	
	int sum = l1n + l2n;
	
	int n = 1;
	int c = 0;
	while(sum / n >= 10)
	{
		n *= 10;
		c++;
	}
	ListNode* head = new ListNode(sum / n);
	n /= 10;
	p = head;
	//NOTE there c is 1 short of the number of digits of the sum
	//now get the digit from the most siginificant number first 
	for(int i = 0; i < c; i++)
	{
		p->next = new ListNode(sum / n % 10);
		n /= 10;
		p = p->next;
	}
	
	return head;
	*/
}

int main()
{
  
}
