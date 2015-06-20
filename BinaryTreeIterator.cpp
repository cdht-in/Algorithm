/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
	
*/
#include <vector>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator 
{
	vector<TreeNode*> nextQ;
	int p;
	
	//In order traversal produces the sorted values
	void IteratorHelper(TreeNode* node)
	{
		if(node->left == 0 && node->right == 0)
		{
			nextQ.push_back(node);
			return;
		}
		if(node->left)
		{
			IteratorHelper(node->left);
		}
		nextQ.push_back(node);
		if(node->right)
		{
			IteratorHelper(node->right);
		}
	}
	
public:
    
	BSTIterator(TreeNode *root):p() {
		if(root != 0)
			IteratorHelper(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(p < nextQ.size())
			return true;
		return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = nextQ[p++];
		return node->val;
    }
};

int main(){
	
	
}