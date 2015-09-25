/*
	
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Have you met this question in a real interview? Yes
Example
Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.
	
*/

#include "../commonHeader.h"

class TreeNode 
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = 0;
    }
};

int isBalancedHelper(TreeNode *root) 
{
	if(root == 0)
		return 0;
	
	int l = isBalancedHelper(root->left);
	
	if(l == -1)
	{
		return l;
	}
	
	int r = isBalancedHelper(root->right);
	
	if(r == -1)
	{
		return r;
	}
	
	if(std::abs(l - r) > 1)
	{
		return -1;
	}
	
	return (l > r)? l + 1: r + 1;
	
}

bool isBalanced(TreeNode *root) 
{
	return (isBalancedHelper(root) != -1);
}

int main()
{
	
}