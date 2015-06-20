/*
  Two elements of a binary search tree (BST) are swapped by mistake.
  Recover the tree without changing its structure.

  Note:
  A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
first implementation

void recoverTreeHelper (TreeNode* node, int& min, int& max, vector<TreeNode*>& vec)
{
  if (node->left) {
    recoverTreeHelper (node->left, min, node->val, vec);
  }
  if (node->val <= min || node->val >= max) {
    vec.push_back (node);
    
  }
  else{

  }
  if (node->right) {
    recoverTreeHelper (node->right, node->val, max, vec);
  }
}

void recoverTree (TreeNode* root)
{
  vector<TreeNode*> vec;
  if (!root)
    return;
  int min = INT_MIN;
  int max = INT_MAX;
  recoverTreeHelper (root, min, max, vec);
}

*/

//second implementation

//idea, inorder traverse the tree and swap the values that are out of place

void recoverTreeHelper(TreeNode *node,vector<TreeNode*>& inorder) {
	if(node == 0)
		return;
	
	recoverTreeHelper(node->left,inorder);
	
	inorder.push_back(node);
	
	recoverTreeHelper(node->right,inorder);
}

//n(nlogn) in time because of the sorting

//NOTE the O(1) space algorithm would use threaded binary tree
void recoverTree(TreeNode *root) {
	if(root == 0)
		return;
	vector<TreeNode*> inorder;
	
	recoverTreeHelper(root,inorder);
	
	vector<int> vals;
	for(int i = 0; i < inorder.size(); i++)
	{
		vals.push_back(inorder[i]->val);
	}
	
	sort(vals.begin(),vals.end());
	
	//this would take care of n wrong nodes as well
	for(int i = 0; i < inorder.size(); i++)
	{
		inorder[i]->val = vals[i];
	}
}










































//third implementation
//another approach http://yucoding.blogspot.com/2013/03/leetcode-question-75-recover-binary.html

int main()
{
	TreeNode* node1 = new TreeNode(0);	
	TreeNode* node2 = new TreeNode(1);
	node1->left = node2;
	recoverTree(node1);
	
	
}
