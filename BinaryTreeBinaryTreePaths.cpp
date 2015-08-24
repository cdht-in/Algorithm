/*
	
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/

#include "./commonHeader.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void binaryTreePathsHelper(string s,vector<string>& result,TreeNode* node)
{
	if(node == 0)
	{
		return;
	}
	
	if(node->left == 0 && node->right == 0)
	{
		s += to_string(node->val);
		result.push_back(s);
		return;
	}
	
	s += to_string(node->val) + "->";
	
	binaryTreePathsHelper(s,result,node->left);
	
	binaryTreePathsHelper(s,result,node->right);
	
}

vector<string> binaryTreePaths(TreeNode* root) 
{
	vector<string> ret;
	binaryTreePathsHelper("",ret,root);
	return ret;
}

int main()
{
	
}