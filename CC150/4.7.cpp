/*
	
	You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1

*/
#include "4.6.cpp"

bool isEqual(TreeNode* root1, TreeNode* root2)
{
	if(root1 == 0 && root2 == 0)
		return true;
	
	if(root1 == 0 || root2 == 0)
		return false;
	
	return root1->v == root2->v && isEqual(root1->left,root2->left) && isEqual(root1->right,root2->right);
	
}

//brute force O(n^2), compare each node of root1 to root2, then recursively compare its subtree
bool isSubtree(TreeNode* root1, TreeNode* root2)
{
	if(root2 == 0)
		return true;
	
	if(root1 == 0)
		return false;
	
	if(isEqual(root1,root2))
		return true;
	
	return isSubtree(root1->left,root2) || isSubtree(root1->right, root2);
}

//adding the special character "#" to the sequence would help identify if root2 is present in roo1 but not as its subtree

void PreOrder(TreeNode* node, string& seq)
{
	if(node == 0)
	{
		seq += "#";
		return;
	}
	seq += to_string(node->v);
	PreOrder(node->left,seq);
	PreOrder(node->right,seq);
}

void InOrder(TreeNode* node, string& seq)
{
	if(node == 0)
	{
		return;
	}

	InOrder(node->left,seq);
	seq += to_string(node->v);
	InOrder(node->right,seq);
}

//O(m + n) in time and O(n) in space
//The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree.
bool isSubtreeI(TreeNode* root1, TreeNode* root2)
{
	string root1Inorder = "";
	InOrder(root1,root1Inorder);
	
	string root2Inorder = "";
	InOrder(root2,root2Inorder);
	
	cout << root1Inorder << " " << root2Inorder << endl;
	if(root1Inorder.find(root2Inorder) == string::npos)
		return false;
	
	string root1Preorder = "";
	PreOrder(root1,root1Preorder);
	
	string root2Preorder = "";
	PreOrder(root2,root2Preorder);
	
	cout << root1Preorder << " " << root2Preorder << endl;
	return (root1Preorder.find(root2Preorder) != string::npos);
}

int main()
{
	/*
	vector<int> foo;
	for(int i = 1; i <= 10; i++)
		foo.push_back(i);
	
	TreeNode* root = sortedArrayToBST(foo);
		
	TreeNode* node1 = FoundNode(root,7);
	
	TreeNode* node2 = FoundNode(root,10);
	
	*/
	
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	node1->right = node2;
	node2->right = node3;
		

	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(2);
	node4->right = node5;
	
	cout << isSubtree(node1,node4) << endl;
	cout << isSubtreeI(node1,node4) << endl;
	
}