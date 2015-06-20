	/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
	
*/

#include <map>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il,int ir, map<int,int>& index) 
{
	//nothing to construct
	if(pl > pr || il > ir)
		return 0;
	
	//the first node in preorder is always the root
	TreeNode* root = new TreeNode(preorder[pl]);
	
	int rootIndex = index[root->val];
	
	//inorder helps to determine how many nodes are in the left/right tree of the root
	int nLeftTreeNodes = rootIndex - il;
	
	int nRightTreeNodes = ir - rootIndex;
	
	//construct the left tree
	root->left = buildTreeHelper(preorder,inorder,pl + 1, pl + nLeftTreeNodes, il, rootIndex - 1, index);
	
	//construct the right tree
	root->right = buildTreeHelper(preorder,inorder,pr - nRightTreeNodes + 1, pr, rootIndex + 1,ir , index);
	
	return root;
}
  
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
{
    if(preorder.size() < 1 || inorder.size() < 1)
		return 0;
	
	map<int,int> index;
	//hash the nodes index in inorder 
	for(int i = 0; i < inorder.size(); i++)
	{
		index[inorder[i]] = i;
	}
	
	return buildTreeHelper(preorder,inorder,0,preorder.size() - 1, 0, inorder.size() - 1, index);
}

int main()
{
	
}