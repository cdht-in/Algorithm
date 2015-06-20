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

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(), right() {}
};

void preorderTraversalHelper(TreeNode *node, vector<int>& cont) {
  if(!node)
    return;
  cont.push_back(node->val);
  preorderTraversalHelper(node->left,cont);
  preorderTraversalHelper(node->right,cont);
}

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ret;
  preorderTraversalHelper(root,ret);
  return ret;
}

vector<int> preorderTraversalIter(TreeNode *root) {
  vector<int> ret;
  vector<TreeNode*> st;
  if(root){
    st.push_back(root);
    while(!st.empty()){
      TreeNode* node = st.back();
      st.pop_back();
      ret.push_back(node->val);
      if(node->right)
	st.push_back(node->right);
      if(node->left)
	st.push_back(node->left);
    }
  }
  return ret;
}


int main(){

}
