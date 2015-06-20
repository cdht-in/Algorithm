/*
  Given a binary tree, find the maximum path sum.

  The path may start and end at any node in the tree.

  For example:
  Given the below binary tree,

  2
  / \
  1 3
  Return 6.
*/
#include <climits>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

int maxPathSumHelper (TreeNode* node, int& max)
{
  if (!node)
    return 0;
  int l = maxPathSumHelper (node->left, max) + node->val;
  int r = maxPathSumHelper (node->right, max) + node->val;
  int mid = l + r - node->val;
  int ret = (l > r) ? l : r;
  ret = (ret > node->val) ? ret : node->val;
  int local = (ret > mid) ? ret : mid;
  max = (max > local) ? max : local;
  return ret;
}

int maxPathSum (TreeNode* root)
{
  if (!root)
    return 0;
  int max = INT_MIN;
  maxPathSumHelper (root, max);
  return max;
}

int main()
{
  TreeNode node (1);
  cout << maxPathSum (&node) << endl;
}






