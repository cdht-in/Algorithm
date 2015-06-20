/*
	
Invert Binary Tree Total Accepted: 2308 Total Submissions: 5960 My Submissions Question Solution 
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

struct TreeNode 
{

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(0), right(0) {}

};

TreeNode* invertTree(TreeNode* root) 
{
	if(root == 0)
		return 0;
	
	TreeNode* tmp = root->left;
	
	root->left = root->right;
	
	root->right = tmp;
	
	invertTree(root->left);
	invertTree(root->right);
	
	return root;
}

int main()
{
	
	
}