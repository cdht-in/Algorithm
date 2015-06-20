/*
	
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
	
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

//O(logn^2), at each level there is logn calculation to get the height and the height is logn, thus the overall time complexity is logn^2
int countNodes(TreeNode* root) 
{
    if(root == 0) 
		return 0;

    int hl = 0, hr = 0;

    TreeNode *l = root, *r = root;

    while(l) 
	{
		hl++;
		l = l->left;
	}

    while(r) 
	{
		hr++;
		r = r->right;
	}

	//full tree
    if(hl == hr) 
		return (1 << hl) - 1;
	
	//at least one of the subtree is a full tree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
	
}