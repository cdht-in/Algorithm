/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
	
*/
#include <climits>

int Max(int a, int b, int c)
{
	a = (a > b)? a : b;
	return (a > c)? a : c;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};

void maxPathSumHelper(TreeNode *node, int& csum, int& max) {
    if (!node) {
      csum = 0;
      return;
    }
    int lsum = 0, rsum = 0;
    //get the left tree max
    maxPathSumHelper (node->left, lsum, maxsum);
    //get the right tree max
    maxPathSumHelper (node->right, rsum, maxsum);
    //get the bigger one of left or right tree, Note that the first comparison is needed if there are negative nodes in the tree
    csum = std::max (node->val, std::max (node->val + lsum, node->val + rsum) );
    //if the tree go throuh a root, there is a potential max sum too
    maxsum = std::max (maxsum, std::max (csum, node->val + lsum + rsum) );
}

int maxPathSum(TreeNode *root) {
    int csum = 0;
    int maxsum = INT_MIN;
    maxPathSumHelper (root, csum, maxsum);
    return maxsum;
}


/*
int maxPathSum (Node* root)
{
  int csum = 0;
  int maxsum = INT_MIN;
  maxPathSumHelper (root, csum, maxsum);
  return maxsum;
}

void maxPathSumHelper (Node* node, int& csum, int& maxsum)
{
  if (!node) {
    csum = 0;
    return;
  }
  int lsum = 0, rsum = 0;
  //get the left tree max
  maxPathSumHelper (node->left, lsum, maxsum);
  //get the right tree max
  maxPathSumHelper (node->right, rsum, maxsum);
  //get the bigger one of left or right tree, Note that the first comparison is needed if there are negative nodes in the tree
  csum = std::max (node->val, std::max (node->val + lsum, node->val + rsum) );
  //if the tree go throuh a root, there is a potential max sum too
  maxsum = std::max (maxsum, std::max (csum, node->val + lsum + rsum) );
}
*/

int main()
{
	
}