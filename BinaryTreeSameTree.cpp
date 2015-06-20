/*
  Given two binary trees, write a function to check if they are equal or not.

  Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (0), right (0) {}
};

/*
bool isSameTreeHelper (TreeNode* p, TreeNode* q)
{
  if (p->val != q->val)
    return false;
  if ( (p->left && !q->left) || (!p->left && q->left) )
    return false;
  if ( (p->right && !q->right) || (!p->right && q->right) )
    return false;
  bool ret = true;
  if (p->left && q->left)
    ret = ret && isSameTreeHelper (p->left, q->left);
  if (p->right && q->right)
    ret = ret && isSameTreeHelper (p->right, q->right);
  return ret;
}


bool isSameTree (TreeNode* p, TreeNode* q)
{
  if (!p && !q)
    return true;
  if ( (p && !q) || (!p && q) )
    return false;
  return isSameTreeHelper (p, q);
}

*/

//second implementation

bool isSameTree(TreeNode *lNode, TreeNode *rNode) {
	if(lNode == 0 && rNode == 0)
		return true;
	if(lNode == 0 || rNode == 0)
		return false;
	
	if(isSameTree(lNode->left,rNode->left) == false)
		return false;
	
	if(isSameTree(lNode->right,rNode->right) == false)
		return false;
	
	return lNode->val == rNode->val;
}









































//third implementation
bool isSameTreeI(TreeNode *p, TreeNode *q) 
{
	if(p == 0 && q == 0)
		return true;
	
	if(p == 0 || q == 0)
		return false;
	
	if(p->val != q->val)
		return false;
	
	return isSameTreeI(p->left,q->left) && isSameTreeI(p->right,q->right);
}

int main()
{
}
