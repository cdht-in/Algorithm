/*
	Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.

*/

#include <iostream>


using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int level(TreeNode* node)
{
	if(node == 0)
		return 0;
	
	int l = level(node->left);
	
	if(l == -2)
		return -2;
	
	int r = level(node->right);
	
	if(r == -2)
		return -2;
	
	if (std::abs(l - r) > 1)
	{
		return -2;
	}
	
	//computer the higher height
	return (l > r)? l + 1 : r + 1;
}

bool isBalanced(TreeNode* root)
{
	int diff = level(root);
	if(diff == -2)
		return false;
	return true;
}

int main()
{
	
	
}