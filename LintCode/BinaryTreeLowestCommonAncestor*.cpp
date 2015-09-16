
/*
	
Medium Lowest Common Ancestor

34% Accepted
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Have you met this question in a real interview? Yes
Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
	
*/

class TreeNode 
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = 0;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) 
{
	if(root == 0 || root == A || root == B)
		return root;
	
	TreeNode* l = lowestCommonAncestor(root->left,A,B);
	TreeNode* r = lowestCommonAncestor(root->right,A,B);
	
	if(l && r)
		return root;
	
	return (l == 0)? r : l;
}

int main()
{
	
}