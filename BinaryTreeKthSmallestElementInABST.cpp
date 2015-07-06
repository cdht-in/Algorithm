/*
	
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
	
*/

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};

int kthSmallestHelper(TreeNode* node)
{
	if(node == 0)
		return 0;
	int l = kthSmallestHelper(node->left);
	int r = kthSmallestHelper(node->right);
	return 1 + l + r;
} 

int kthSmallest(TreeNode* root, int k) 
{		
	int l = kthSmallestHelper(root->left);
	if(l == k - 1)
		return root->val;
	else if(l > k - 1)
		return kthSmallest(root->left,k);
	return kthSmallest(root->right,k - l - 1);
}

int main()
{
	
}