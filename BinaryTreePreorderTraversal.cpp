/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

*/

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> result;
	if(root == 0)
		return result;
	stack<TreeNode*> st;
	st.push(root);
	while(st.empty() == false)
	{
		TreeNode* node = st.top();
		result.push_back(node->val);
		st.pop();
		if(node->right)
			st.push(node->right);
		if(node->left)
			st.push(node->left);
		
	}
	return result;
}

int main(){
	
	
}