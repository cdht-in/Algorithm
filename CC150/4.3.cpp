/*

	Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height
	
*/
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

TreeNode* sortedArrayToBSTHelper(vector<int> &num, int l, int r)
{
	if(l > r)
		return 0;
	
	int mid = (l + r) / 2;
	
	TreeNode* node = new TreeNode(num[mid]);
	
	node->left = sortedArrayToBSTHelper(num,l,mid - 1);
	
	node->right = sortedArrayToBSTHelper(num,mid + 1,r);
	
	return node;
}

TreeNode *sortedArrayToBST(vector<int> &num) 
{
	return sortedArrayToBSTHelper(num,0,num.size() - 1);
}
 
int main()
{
	
}