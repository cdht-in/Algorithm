/*
  Given a binary tree, determine if it is a valid binary search tree (BST).

  Assume a BST is defined as follows:

  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.
*/
#include <climits>
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (0), right (0) {}
};

/*
first implementation

bool isValidBSTHelper(TreeNode* node, int min, int max){
  if(node->val > min && node->val < max){
      if(node->left)
	if(!isValidBSTHelper(node->left,min,node->val))
	  return false;
      if(node->right)
	if(!isValidBSTHelper(node->right,node->val,max))
	  return false;
      return true;
  }
  return false;
}


bool isValidBST (TreeNode* root)
{
  if(!root)
    return false;
  return isValidBSTHelper(root,INT_MIN,INT_MAX);
}

*/

//second implementation

//a valid binary search tree, parent's value is between two chidren, and it is bigger than the max from its left tree and is smaller than the min from its right tree
/*
int isValidBSTHelper(TreeNode *node) {
	if(node->left == 0 && node->right == 0)
		return node->val;
	
	int lMaxValue = INT_MIN;
	if(node->left)
	{
		//invalid tree
		int lValue = isValidBSTHelper(node->left);
		if(lValue == INT_MAX)
			return INT_MAX;
		
		lMaxValue = lValue;
	}
	
	int rMinValue = INT_MAX;
	if(node->right){
		//invalid tree
		int rValue = isValidBSTHelper(node->right);
		if(rValue == INT_MAX)
			return INT_MAX;
		
		rMinValue = rValue;
	}
	
	if(node->val > lMaxValue && node->val < rMinValue)
	{
		//inidicating the right tree is emtpy
		if(rMaxValue == INT_MAX)
			return node->val;
		return rMaxValue;
	}
	//indicate a failure case
	return INT_MAX;
}
*/

//inorder traversal of the tree, a valid tree node's value should only increse
bool isValidBSTHelper(TreeNode *node, int64_t& prev) {
	if(node == 0)
		return true;
	
	if(isValidBSTHelper(node->left,prev) == false)
		return false;
		
	
	//NOTE here need to conver node->val to int64_t to pass the leetcode test
	int64_t val = (int64_t)node->val;
	if (prev >= val)
		return false;
	
	prev = val;
	
	if(isValidBSTHelper(node->right,prev) == false)
		return false;
		
	return true;
}

bool isValidBST(TreeNode *root) {
    if(root == 0)
		return true;
	int64_t prev = LLONG_MIN;
	return isValidBSTHelper(root,prev);
}








































bool isValidBSTIHelper(TreeNode* node, int64_t lMax, int64_t rMax)
{
	if(node == 0)
		return true;
	
	if(node->left && node->left->val >= node->val)
		return false;
	
	if(node->right && node->right->val <= node->val)
		return false;
	
		
	if(node->val <= lMax)	
		return false;
	
	if(node->val >= rMax)
		return false;
	
	return isValidBSTIHelper(node->left,lMax,node->val) && isValidBSTIHelper(node->right,node->val,rMax);
}

//third implementation
bool isValidBSTI(TreeNode *root) 
{
	return isValidBSTIHelper(root,LLONG_MIN,LLONG_MAX);
}


int main()
{
	TreeNode* node1 = new TreeNode(0);
		
	cout << isValidBSTI(node1) << endl;
	
	int64_t prev = LLONG_MIN;	
	cout << prev << endl;
}
