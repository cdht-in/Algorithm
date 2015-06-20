#include "Data Structure/BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> val = {1,2,3,4,5,6};
	
	BinarySearchTree bTree(val);
	
	TreeNode* node1 = bTree.FindValue(1);
	TreeNode* node2 = bTree.FindValue(7);
	
	TreeNode* p = bTree.LowestCommonAncestorInBinaryTree(node1,node2);
	 
	if(p)
	{
		cout << "lowest common ancestor is " <<  p->val << endl;
	}
	else
	{
		cout << "lowest common ancestor is none" << endl;
	}
	
}