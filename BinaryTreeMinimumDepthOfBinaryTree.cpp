/*
  Given a binary tree, find its minimum depth.
  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include <climits>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
first implementation
int minDepth (TreeNode* root)
{
  if (!root)
    return 0;
  int l = 1 + minDepth (root->left);
  int r = 1 + minDepth (root->right);
  //skewed tree
  if (l == 1)
    return r;
  else if (r == 1)
    return l;
  return (l < r) ? l : r;
}
*/

int minDepthHelper(TreeNode* node){
	//leaf
	if(node->left == 0 && node->right == 0)
		return 1;
	
	int lDep = INT_MAX;
	int rDep = INT_MAX;
	
	if(node->left)
	{
		lDep = minDepthHelper(node->left) + 1;
	}
	
	if(node->right)
	{
		rDep = minDepthHelper(node->right) + 1;
	}
	
	return (lDep < rDep)? lDep : rDep;
}

int minDepth(TreeNode *root) {
	if(root == 0)
		return 0;
	return minDepthHelper(root);
}









































//second implementation

int minDepthI(TreeNode *root) 
{
	if(root == 0)
	{
		return 0;
	}
	
	if(root->left == 0 && root->right == 0)
	{
		return 1;
	}
	
	int l = INT_MAX;
	if(root->left)
		l = minDepthI(root->left) + 1;
	
	int r = INT_MAX;
	if(root->right)
		r = minDepthI(root->right) + 1;
	
	return (l < r)? l : r;
}

int main()
{

}


