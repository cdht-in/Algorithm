/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left(), right() {}
};

/*
first implementation

TreeNode* sortedArrayToBSTHelper (vector<int>& num, int l, int r)
{
  if (l > r)
    return 0;
  int mid = (l + r) / 2;
  TreeNode* node = new TreeNode (num[mid]);
  node->left = sortedArrayToBSTHelper (num, l, mid - 1);
  node->right = sortedArrayToBSTHelper (num, mid + 1, r);
  return node;
}

TreeNode* sortedArrayToBST (vector<int>& num)
{
  if (num.size() < 1)
    return 0;
  return sortedArrayToBSTHelper (num, 0, num.size() - 1);
}

*/

//second implementation

TreeNode* sortedArrayToBSTHelper(vector<int> &num, int l, int r)
{
	if(l > r)
		return 0;
	int mid = (l + r) / 2;
	TreeNode* parentNode = new TreeNode(num[mid]);
	parentNode->left = sortedArrayToBSTHelper(num,l,mid - 1);
	parentNode->right = sortedArrayToBSTHelper(num,mid + 1, r);
	return parentNode;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	if(num.size() == 0)
		return 0;
	return sortedArrayToBSTHelper(num,0,num.size() - 1);
}

int main()
{
}
