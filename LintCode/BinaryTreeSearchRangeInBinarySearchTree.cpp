/*
	
Medium Search Range in Binary Search Tree

36% Accepted
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.

Have you met this question in a real interview? Yes
Example
If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].

    20
   /  \
  8   22
 / \
4   12
	
*/

#include "../commonHeader.h"

class TreeNode 
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void searchRangeHelperI(TreeNode* node, int k1, int k2, vector<int>& range)
{
	if(node == 0)
	{
		return;
	}
		
	if(node->val < k1)
	{
		searchRangeHelperI(node->right,k1,k2,range);
		return;
	}
	
	if(node->val > k2)
	{
		searchRangeHelperI(node->left,k1,k2,range);
		return;
	}
	
	searchRangeHelperI(node->left,k1,k2,range);
	range.push_back(node->val);
	searchRangeHelperI(node->right,k1,k2,range);
}

vector<int> searchRange(TreeNode* root, int k1, int k2) 
{
	vector<int> range;
	
	searchRangeHelperI(root,k1,k2,range);
	
	return range;
}

int main()
{
	
}