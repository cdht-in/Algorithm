/*
  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?

  confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


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
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (0), right (0) {}
};

/*
first implementation

vector<int> inorderTraversal (TreeNode* root)
{
  vector<int> ret;
  if (!root)
    return ret;
  stack<TreeNode*> st;
  st.push (root);
  //trace flag
  bool flag = true;
  while (!st.empty() ) {
    TreeNode* node = st.top();
    if (node->left && flag) {
      st.push (node->left);
    }
    else {
      ret.push_back (node->val);
      st.pop();
      if (node->right){
	flag = true;
        st.push (node->right);
      }
      else
	flag = false;
    }
  }
  return ret;
}
*/

//second implementation

//alway push the left most tree
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> inorder;
	if(root == 0)
		return inorder;
	
	stack<TreeNode*> st;
	TreeNode* node = root;
	
	while(node)
	{
		st.push(node);
		node = node->left;
	}
	
	while(st.empty() == false)
	{
		TreeNode* node = st.top();
		st.pop();
		inorder.push_back(node->val);
		
		if(node->right)
		{
			node = node->right;
			while(node)
			{
				st.push(node);
				node = node->left;
			}
		}
	}
	
	return inorder;
}

int main()
{
	
}
