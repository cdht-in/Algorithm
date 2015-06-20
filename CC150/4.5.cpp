/*
	
	Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in a binary search tree where each node has a link to its parent.

*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode
{
	int v;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	
	TreeNode(int value):v(value),left(),right(),parent(){};
};

TreeNode* sortedArrayToBSTHelper(vector<int> &num, TreeNode* parent,int l, int r)
{
	if(l > r)
		return 0;
	
	int mid = (l + r) / 2;
	
	TreeNode* node = new TreeNode(num[mid]);
	
	node->left = sortedArrayToBSTHelper(num,node,l,mid - 1);
	
	node->right = sortedArrayToBSTHelper(num,node,mid + 1,r);
	
	node->parent = parent;
	
	return node;
}

TreeNode *sortedArrayToBST(vector<int> &num) 
{
	return sortedArrayToBSTHelper(num,0,0,num.size() - 1);
}

//assume val is aleady in the tree and there is no duplicates
TreeNode* FoundNode(TreeNode* root,int val)
{
	if(root == 0)
		return 0;
	
	//found the node
	if(root->v == val)
		return root;
	else if(root->v < val)
		return FoundNode(root->right,val);
	else 
		return FoundNode(root->left,val); 
}

//if the node has right children, then the next is the leftmost node of its right tree
//otherwise it is the first parent that is greater than it
TreeNode* NextNode(TreeNode* node)
{
	if(node == 0)
		return 0;
	if(node->right)
	{
		TreeNode* lNode = node->right;
		while(lNode->left)
		{
			lNode = lNode->left; 
		}
		return lNode;
	}
	
	//find the first parent that is greater than it
	TreeNode* p = node->parent;
	while(p && p->v < node->v)
	{
		p = p->parent;
	}
	return p;
}

int main()
{
	vector<int> foo;
	for(int i = 1; i <= 3; i++)
		foo.push_back(i);
	
	TreeNode* root = sortedArrayToBST(foo);
	
	TreeNode* node = FoundNode(root,2);
	
	TreeNode* nextNode = NextNode(node);
	
	if(nextNode == 0)
	{
		cout << "no next node" << endl;
	}		
	else
	{
		cout << nextNode->v << endl;
	}
}