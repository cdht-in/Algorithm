/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
	
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
	 trivial recursive solution
 
void postorderTraversalHelper(vector<int>& vec,TreeNode* node){
	if(node == 0)
		return;
	postorderTraversalHelper(vec,node->left);
	postorderTraversalHelper(vec,node->right);
	vec.push_back(node->val);
}
 
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	if(root == 0)
		return result;
	postorderTraversalHelper(result,root);
}

*/

//problem with this is that it can't mark each node as visited, result in a cycle when traverse the tree
 vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	if(root == 0)
		return result;
	stack<TreeNode*> st;
	st.push(root);
	while(st.empty() == false){
		
		//this is a child-less node
		if(st.top()->right == 0 && st.top()->left == 0)
		{
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			continue;
		}
		
		//this would result in a cycle here
		TreeNode* node = st.top();
		if(node->right != 0)
		{
			st.push(node->right);
		}
		if(node->left != 0)
		{
			st.push(node->left);
		}
	}
	return result;
}

//using two stacks
vector<int> postorderTraversalI(TreeNode *root) {
	vector<int> result;
	
	if (!root) 
		return result;
	  stack<TreeNode*> s;
	  stack<TreeNode*> output;
	  s.push(root);
	  
	  while (!s.empty()) {
	    TreeNode *curr = s.top();
	    output.push(curr);
	    s.pop();
	    if (curr->left)
	      s.push(curr->left);
	    if (curr->right)
	      s.push(curr->right);
	  }
	  while (!output.empty()) {
		  
		result.push_back(output.top()->val);
	    output.pop();
	  }
	  return result;
}



int main(){
	
	
	
};