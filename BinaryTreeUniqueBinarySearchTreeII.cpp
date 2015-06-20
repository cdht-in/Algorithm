/*
  Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

  For example,
  Given n = 3, your program should return all 5 unique BST's shown below.

  1         3     3      2      1
  \       /     /      / \      \
  3     2     1      1   3      2
  /     /       \                 \
  2     1         2                 3
  confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (0), right (0) {}
};


//first implementation

vector<TreeNode*>* generate (int start, int end)
{
  vector<TreeNode*>* subTree = new vector<TreeNode*>();
  
  if (start > end) 
  {
    subTree->push_back (0);
    return subTree;
  }
  
  for (int i = start; i <= end; i++) 
  {
    vector<TreeNode*>* leftSubs = generate (start, i - 1);
	
    vector<TreeNode*>* rightSubs = generate (i + 1, end);
	
    for (int j = 0; j < leftSubs->size(); j++) 
	{
      for (int k = 0; k < rightSubs->size(); k++) 
	  {
        TreeNode* node = new TreeNode (i);
		
        node->left = (*leftSubs) [j];
        node->right = (*rightSubs) [k];
		
        subTree->push_back (node);
      }
    }
  }
  
  return subTree;
}

vector<TreeNode*> generateTrees (int n)
{
  if (n == 0)
    return *generate (1, 0);
  return *generate (1, n);
}











































vector<TreeNode *>* generateTreesHelper(int start, int end)
{
	vector<TreeNode *>* currentSubTree = new vector<TreeNode *>();
	if(start > end)
	{
		currentSubTree->push_back(0);
		return currentSubTree;
	}
	
	//use i as the root the generate each substree
	for(int i = start; i <= end; i++)
	{
		vector<TreeNode *>* leftTree = generateTreesHelper(start, i - 1);
		
		vector<TreeNode *>* rightTree = generateTreesHelper(i + 1, end);
		
		
		//use each leftTree and rightTree as the leftTree and RightTree
		for(int j = 0; j < leftTree->size(); j++)
		{
			for(int k = 0; k < rightTree->size(); k++)
			{
				TreeNode* root = new TreeNode(i);
				root->left = (*leftTree)[j];
				root->right = (*rightTree)[k];
				currentSubTree->push_back(root);
			}
		}
	}
	
	return currentSubTree;
}

//second implementation
vector<TreeNode *> generateTrees(int n) {
	return *generateTreesHelper(1,n);
}



int main()
{
  generateTrees(3);
}
