/*
	
Invert a binary tree.

Have you met this question in a real interview? Yes
Example
  1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4
Challenge
Do it in recursion is acceptable, can you do it without recursion?
	
*/

class TreeNode 
{
	
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) 
	{
        this->val = val;
        this->left = this->right = 0;
    }
};

void invertBinaryTree(TreeNode *root) 
{
	if(root == 0)
		return;
	
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertBinaryTree(root->left);
	invertBinaryTree(root->right);
}

int main()
{
	
}