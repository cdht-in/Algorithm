/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
	
*/

#include <vector>
#include <map>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};
  
TreeNode* buildTreeHelper(vector<int> &postorder, vector<int> &inorder, int pl, int pr, int il,int ir, map<int,int>& index) {
	//nothing to construct
	if(pl > pr || il > ir)
		return 0;
	
	//the last node in postorder is always the root
	TreeNode* root = new TreeNode(postorder[pr]);
	
	int rootIndex = index[root->val];
	
	//inorder helps to determine how many nodes are in the left/right tree of the root
	int nLeftTreeNodes = rootIndex - il;
		
	//postorder left tree comes in first
	root->left = buildTreeHelper(postorder,inorder,pl, pl + nLeftTreeNodes - 1, il, rootIndex - 1, index);
	
	//postorder right tree comes in second
	root->right = buildTreeHelper(postorder,inorder, pl + nLeftTreeNodes, pr - 1 , rootIndex + 1,ir,index);
	
	return root;
}
    
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  
    if(postorder.size() < 1 || inorder.size() < 1)
		return 0;
	
	map<int,int> index;
	//hash the nodes index in inorder 
	for(int i = 0; i < inorder.size(); i++)
	{
		index[inorder[i]] = i;
	}
	
	return buildTreeHelper(postorder,inorder,0,postorder.size() - 1, 0, inorder.size() - 1, index);
}
  
int main(){
	
	
}