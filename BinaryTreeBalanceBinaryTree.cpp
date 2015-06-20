/*
  Given a binary tree, determine if it is height-balanced.

  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left(), right() {}
};

/*
	first implementation

//make sure every subtree is balanced
int isBalancedHelper (TreeNode* node)
{
  if (!node)
    return 0;
  int l = 1;
  int tmp = isBalancedHelper (node->left);
  if (tmp == -1)
    return -1;
  l += tmp;
  int r = 1;
  tmp = isBalancedHelper (node->right);
  if (tmp == -1)
    return -1;
  r += tmp;
  if ( (l - r) > 1 || (r - l) > 1)
    return -1;
  return (l < r) ? r : l;
}

bool isBalanced (TreeNode* root)
{
  if (!root)
    return true;
  int l = isBalancedHelper (root->left);
  int r = isBalancedHelper (root->right);
  if (l == -1 || r == -1)
    return false;
  if ( (l - r) > 1 || (r - l) > 1)
    return false;
  return true;
}
*/


//second implementation

int isBalancedHelper(TreeNode *node){
		
	if(node->left == 0 && node->right == 0)
		return 1;
	
	int lDep = 1;
	int rDep = 1;
	
	if(node->left)
	{
		int lTmp = isBalancedHelper(node->left);
		if(lTmp == -1)
		{
			return -1;
		}
		lDep += lTmp;
	}
	
	if(node->right)
	{
		int rTmp = isBalancedHelper(node->right);
		if(rTmp == -1)
		{
			return -1;
		}
		rDep += rTmp;
	}
	
	//indicate an unbalanced tree
	if(lDep - rDep > 1 || rDep - lDep > 1)
		return -1;
	
	//return the maxDep tree
	return (lDep < rDep)? rDep : lDep;
}

bool isBalanced(TreeNode *root) {
	if(root == 0)
		return true;
	int l = 0;
	int r = 0;
	if(root->left)
		l = isBalancedHelper(root->left);
	if(root->right)
		r = isBalancedHelper(root->right);
	if(l == -1 || r == -1)
		return false;
	if(l - r > 1 || r - l > 1)
		return false;
	return true;
}








































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
	
	return (l > r)? l + 1 : r + 1;
}

//second implementation
bool isBalancedI(TreeNode *root) 
{
    int diff = level(root);
	if(diff == -2)
		return false;
	return true;
}


int main() {}



