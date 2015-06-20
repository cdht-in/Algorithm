/*
  Given a binary tree, flatten it to a linked list in-place.

  For example,
  Given

  1
  / \
  2   5
  / \   \
  3   4   6
  The flattened tree should look like:
  1
  \
  2
  \
  3
  \
  4
  \
  5
  \
  6
*/

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};


/*
TreeNode* flattenHelper (TreeNode* node)
{
  if (!node)
    return 0;
  TreeNode* rtree = node->right;
  if(node->left){
    node->right = node->left;
    node->left = 0;
    node = flattenHelper(node->right);
  }
  //do the same thing for the right tree
  if(rtree){
    node->right = rtree;
    node = flattenHelper(node->right);
  }
  return node;
}

void flatten (TreeNode* root)
{
  if (!root)
    return;
  flattenHelper (root);
}
*/


//second implementation


void flattenHelper(TreeNode *node)
{
	//leaf node, nothing to do
	if(node->left == 0 && node->right == 0)
		return;
	
	//swap the left and right
	if(node->left != 0 && node->right == 0)
	{
		node->right = node->left;
		node->left = 0;
	}
	
	//no need to flatten the left part
	if(node->left == 0 && node->right != 0)
	{
		flattenHelper(node->right);
	}
	
	//append the original right part to the rightmost node
	if(node->left != 0 && node->right != 0)
	{
		TreeNode* rightTree = node->right;
		node->right = node->left;
		node->left = 0;
		
		//find the rightmost node of the new right tree
		TreeNode* rightMost = node->right;
		while(rightMost->right != 0)
		{
			rightMost = rightMost->right;
		}
		
		rightMost->right = rightTree;
		
		flattenHelper(node->right);
	}
}

void flatten(TreeNode *root) {
	if(root == 0)
		return;
	flattenHelper(root);
}





































//third implementation
TreeNode* flattenI(TreeNode *root) 
{
	while(root)
	{
	    if(root->left == 0)
		{
	        root = root->right;
		}
	    else 
		{
			//if there is a right tree to append to the left tree later
	        if(root->right)
			{
	            TreeNode *l = root->left;
				//find the rightmost of the leftTree
	            while(l->right)
				{
					l = l->right;
				}
	            l->right = root->right;
	        }
			
	        root->right = root->left;
	        root->left = 0;
	        root = root->right;
	    }
	}
}


int main()
{
  TreeNode a (1);
  TreeNode b (2);
  //TreeNode c(3);
  //a.left = &b;
  a.right = &b;
  flatten (&a);
  TreeNode* node = &a;
  while (node) {
    cout << node->val << endl;
    node = node->right;
  }
}




