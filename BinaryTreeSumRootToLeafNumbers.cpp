/*
  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.

  Find the total sum of all root-to-leaf numbers.

  For example,

  1
  / \
  2   3
  The root-to-leaf path 1->2 represents the number 12.
  The root-to-leaf path 1->3 represents the number 13.

  Return the sum = 12 + 13 = 25.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
first implementation

void hasPathSumHelper (TreeNode* node, int cur, int& sum)
{
  cur *= 10;
  cur += node->val;
  if (!node->left && !node->right) {
    sum += cur;
    return;
  }
  if (node->left) {
    hasPathSumHelper (node->left, cur, sum);
  }
  if (node->right) {
    hasPathSumHelper (node->right, cur, sum);
  }
  cur %= 10;
}

int sumNumbers (TreeNode* root)
{
  if (!root)
    return 0;
  int cur = 0;
  int sum = 0;
  hasPathSumHelper (root, cur, sum);
  return sum;
}

*/

//second implementation

void sumNumbersHelper(TreeNode* node, int& sum, int curValue)
{
	if(node->left == 0 && node->right == 0)
	{
		int path = curValue * 10 + node->val;
		sum += path;
		return;
	}
	
	curValue = curValue * 10 + node->val;
	
	if(node->left != 0)
	{
		sumNumbersHelper(node->left,sum,curValue);
	}
	
	if(node->right != 0)
	{
		sumNumbersHelper(node->right,sum,curValue);
	}
}

int sumNumbers(TreeNode *root) {
    if(root == 0)    
		return 0;
	int sum = 0,curValue = 0;
	sumNumbersHelper(root,sum,curValue);
	return sum;
}







































void sumNumbersIHelper(TreeNode* node, int pathSum,int& sum)
{
	if(node->left == 0 && node->right == 0)
	{
		sum += (10 * pathSum + node->val);
		return;
	}
	
	pathSum = pathSum * 10 + node->val;
	
	if(node->left)
	{
		sumNumbersIHelper(node->left,pathSum, sum);
	}
	
	if(node->right)
	{
		sumNumbersIHelper(node->right,pathSum, sum);
	}
}

//third implementation
int sumNumbersI(TreeNode *root) 
{
	if(root == 0)
		return 0;
	
	int sum = 0;
	sumNumbersIHelper(root,0,sum);
	return sum;
}



int main()
{
}
