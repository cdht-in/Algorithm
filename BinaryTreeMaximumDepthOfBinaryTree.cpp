/*
  Given a binary tree, find its maximum depth.

  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
first implementation

int maxDepthHelper (TreeNode* node)
{

}


int maxDepth (TreeNode* root)
{
  if (!root)
    return 0;
  int max = 1,tmp = 0;
  if (root->left)
    max = 1 + maxDepth(root->left);
  if (root->right) 
    tmp = 1 + maxDepth(root->right);
  max = (max > tmp) ? max : tmp;
  return max;
}
*/

//second implementation, NOTE that simply reverse the comparion in the end wouldn't work on the minDepth
//for case like {0,1}
int maxDepth(TreeNode *root) {
	if(root == 0)
		return 0;
	
	int l = 1 + maxDepth(root->left);
	int r = 1 + maxDepth(root->right);
	
	return (l > r)? l : r;
}


















int main()
{
}
