/*

Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root. For example, in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10). Expected time complexity is O(n).

*/
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):val(val),left(),right(){};
};

int MaximumPathHelper(TreeNode* node, int& max)
{
	if(node->left == 0 && node->right == 0)
	{
		return node->val;
	}
	
	int l = INT_MIN;
	if(node->left)
	{
		l = MaximumPathHelper(node->left,max);
	}
	
	int r = INT_MIN;
	if(node->right)
	{
		r = MaximumPathHelper(node->right,max);
	}
	
	if(l + r + node->val > max)
		max = l + r + node->val;
	
	return (l > r) ? l + node->val : r + node->val;
}

int MaximumPath(TreeNode* root)
{
	int max = INT_MIN;
	if(root == 0)
		return 0;
	MaximumPathHelper(root,max);
	return max;
}

int main()
{
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(-3);
	TreeNode* node3 = new TreeNode(3);
	node1->left = node2;
	node1->right = node3;
	
	
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node2->left = node4;
	node2->right = node5;
	cout << MaximumPath(node1) << endl;
}