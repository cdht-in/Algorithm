/*
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

  Return a deep copy of the list.
*/

#include <map>
#include <iostream>
#include <cstdint>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(), random() {}
};

//DFS O(V) space and O(V+E) time
RandomListNode *copyRandomListHelper(RandomListNode *node,map<int64_t,RandomListNode*>& map) {
	//reached the end of the DFS
	if(node->next == 0 && node->random == 0)
	{
		RandomListNode* leafNode = new RandomListNode(node->label);
		//mark this visited
		map[(int64_t)node] = leafNode;
		return leafNode;
	}
	
	RandomListNode* newNode = new RandomListNode(node->label);
	//mark this node visited
	map[(int64_t)node] = newNode;
	
	if(node->next != 0)
	{
		RandomListNode* nextNode = 0;
		//if this node is visited
		if(map.find((int64_t)node->next) != map.end())
		{
			nextNode = map[(int64_t)node->next];
		}
		else
		{
			nextNode = copyRandomListHelper(node->next,map);
		}
		newNode->next = nextNode;
	}
	
	if(node->random != 0)
	{
		RandomListNode* randomNode = 0;
		//if this node is visited
		if(map.find((int64_t)node->random) != map.end())
		{
			randomNode = map[(int64_t)node->random];
		}
		else
		{
			randomNode = copyRandomListHelper(node->random,map);
		}
		newNode->random = randomNode;
	}
	
	return newNode;
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == 0)
		return head;
	map<int64_t, RandomListNode*> map;
	return copyRandomListHelper(head,map);
}

int main(){
  RandomListNode* a = new RandomListNode(-1);
  RandomListNode* b = new RandomListNode(-1);
  RandomListNode* c = new RandomListNode(-2);
  
  a->next = b;
  b->random = a;
  b->next = c;
  RandomListNode* node = copyRandomList(a);
  
  RandomListNode* p = node;
  
  while(p)
  {
	  cout << p->label << endl;
	  p = p->next;
  }
}
