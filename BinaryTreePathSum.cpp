/*
  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
  5
  / \
  4   8
  /   / \
  11  13  4
  /  \      \
  7    2      1
  return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
first implementation

bool hasPathSumHelper (TreeNode* node, int cur, int sum)
{
  cur += node->val;
  if (!node->left && !node->right) {
    if (cur == sum)
      return true;
  }
  if (node->left) {
    if (hasPathSumHelper (node->left, cur, sum) )
      return true;
  }
  if (node->right) {
    if (hasPathSumHelper (node->right, cur, sum) )
      return true;
  }
  cur -= node->val;
  return false;
}

bool hasPathSum (TreeNode* root, int sum)
{
  if (!root)
    return false;
  int cur = 0;
  return hasPathSumHelper (root, cur, sum);
}
*/

//second implementation

bool hasPathSumHelper(TreeNode *node, int sum, int localSum) 
{
	if(node->left == 0 && node->right == 0)
	{
		if(node->val + localSum == sum)
			return true;
		return false;
	}
	
	localSum += node->val;
	
	if(node->left != 0)
	{
		if(hasPathSumHelper(node->left,sum, localSum))
			return true;
	}
	
	if(node->right != 0)
	{
		if(hasPathSumHelper(node->right,sum,localSum))
			return true;
	}
	
	return false;
}		
	

bool hasPathSum(TreeNode *root, int sum) {
	if(root == 0)
		return false;
	return hasPathSumHelper(root,sum,0);
}



































bool hasPathSumIHelper(TreeNode* node, int curSum, int sum)
{
	if(node->left == 0 && node->right == 0)
	{
		if(node->val + curSum == sum)
			return true;
		return false;
	}
	
	if(node->left)
	{
		if(hasPathSumIHelper(node->left,curSum + node->val, sum))
			return true;
	}
	
	if(node->right)
	{
		if(hasPathSumIHelper(node->right,curSum + node->val, sum))
			return true;
	}
	
	return false;
}


//third implementation
bool hasPathSumI(TreeNode *root, int sum) 
{
     if(root == 0)
		 return false;
	 return hasPathSumIHelper(root,0,sum);
}



int main()
{
}

