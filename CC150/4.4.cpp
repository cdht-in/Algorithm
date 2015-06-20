/*
	
	Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).

*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode
{
	int v;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int value):v(value),left(),right(){};
};

struct ListNode
{
	int v;
	ListNode* next;
	
	ListNode(int value):v(value),next(){};
};

vector<ListNode*> CreateList(TreeNode* root)
{
	vector<ListNode*> list;
	if(root == 0)
		return list;
	queue<TreeNode*> q;
	q.push(root);
	
	int curLevel = 1;
	int nextLevel = 0;
	
	ListNode* head = 0;
	
	while(q.empty() == false)
	{
		TreeNode* node = q.front();
		q.pop();
		curLevel--;
		
		if(head == 0)
		{
			head = new ListNode(node->v);
			list.push_back(head);
		}
		else
		{
			head->next = new ListNode(node->v);
			head = head->next;
		}
		
		if(node->left)
		{
			q.push(node->left);
			nextLevel++;
		}
		
		if(node->right)
		{
			q.push(node->right);
			nextLevel++;
		}
		
		if(curLevel == 0)
		{
			head = 0;
			curLevel = nextLevel;
			nextLevel = 0;
		}
	}
	
	return list;
}

int main()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	
	vector<ListNode*> lists = CreateList(&node1);
	
	for(int i = 0; i < lists.size(); i++)
	{
		ListNode* p = lists[i];
		while(p)
		{
			cout << p->v << " ";
			p = p->next;
		}
		cout << endl;
	}
	
}