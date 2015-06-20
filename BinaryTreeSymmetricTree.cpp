/*
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

  For example, this binary tree is symmetric:

  1
  / \
  2   2
  / \ / \
  3  4 4  3
  But the following is not:
  1
  / \
  2   2
  \   \
  3    3

  Note:
  Bonus points if you could solve it both recursively and iteratively.
*/

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*

//recursively
bool isSymmetricHelper (TreeNode* l, TreeNode* r)
{
  if (!l && !r)
    return true;
  if ( (l && !r) || (!l && r) )
    return false;
  if (l->val != r->val)
    return false;
  return isSymmetricHelper (l->left, r->right) && isSymmetricHelper (l->right, r->left);
}

bool isSymmetric (TreeNode* root)
{
  if (!root)
    return true;
  return isSymmetricHelper (root->left, root->right);
}

*/

//second implementation

bool isSymmetricHelper(TreeNode *lNode, TreeNode* rNode)
{
	if(lNode == 0 && rNode == 0)
		return true;
	if(lNode == 0 || rNode == 0)
		return false;
	
	if(isSymmetricHelper(lNode->right,rNode->left) == false)
		return false;
	
	if(isSymmetricHelper(lNode->left,rNode->right) == false)
		return false;
	
	return lNode->val == rNode->val;
}


bool isSymmetric(TreeNode *root) 
{
	if(root == 0)
		return true;
	return isSymmetricHelper(root->left, root->right);
}







































//O(n) in time, check each node only once
bool isSymmetricIHelper(TreeNode* node1, TreeNode* node2)
{
	if(node1 == 0 && node2 == 0)
		return true;
	if(node1 == 0 || node2 == 0)
		return false;
	
	return node1->val == node2->val && isSymmetricIHelper(node1->right,node2->left) && isSymmetricIHelper(node1->left,node2->right);
}

//second implementation
bool isSymmetricI(TreeNode *root) 
{
	if(root == 0)
		return true;
	return isSymmetricIHelper(root->left,root->right);
}

//interactive, simulate the recursion with stack
bool isSymmetricII(TreeNode *root) 
{
	if(root == 0)
		return true;
	
	stack<TreeNode*> st1;
	stack<TreeNode*> st2;
	st1.push(root);
	st2.push(root);
	
	while(st1.empty() == false && st2.empty() == false)
	{
		TreeNode* st1Node = st1.top();
		st1.pop();
		
		TreeNode* st2Node = st2.top();
		st2.pop();
		
		if(st1Node->val != st2Node->val)
			return false;
		
		if((st1Node->left == 0 && st2Node->right != 0) || (st1Node->left != 0 && st2Node->right == 0))
		{
			return false;
		}
		
		if((st1Node->right == 0 && st2Node->left != 0) || (st1Node->right != 0 && st2Node->left == 0))
		{
			return false;
		}
		
		if(st1Node->left && st2Node->right)
		{
			st1.push(st1Node->left);
			st2.push(st2Node->right);
		}
		
		if(st1Node->right && st2Node->left)
		{
			st1.push(st1Node->right);
			st2.push(st2Node->left);
		}		
	}
	
	return st1.empty()? st2.empty() : st1.empty();
}




int main()
{
}
