/*
	
	Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


struct TreeNode
{
	int v;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	
	TreeNode(int value):v(value),left(),right(),parent(){};
};

TreeNode* sortedArrayToBSTHelper(vector<int> &num, TreeNode* parent,int l, int r)
{
	if(l > r)
		return 0;
	
	int mid = (l + r) / 2;
	
	TreeNode* node = new TreeNode(num[mid]);
	
	node->left = sortedArrayToBSTHelper(num,node,l,mid - 1);
	
	node->right = sortedArrayToBSTHelper(num,node,mid + 1,r);
	
	node->parent = parent;
	
	return node;
}

TreeNode *sortedArrayToBST(vector<int> &num) 
{
	return sortedArrayToBSTHelper(num,0,0,num.size() - 1);
}

TreeNode* FoundNode(TreeNode* root,int val)
{
	if(root == 0)
		return 0;
	
	//found the node
	if(root->v == val)
		return root;
	else if(root->v < val)
		return FoundNode(root->right,val);
	else 
		return FoundNode(root->left,val); 
}

bool father(TreeNode* n1, TreeNode* n2){
    if(n1 == 0)
		return false;
    else if(n1 == n2) 
		return true;
    else 
		return father(n1->left, n2) || father(n1->right, n2);
}

void first_ancestor2(TreeNode* head, TreeNode* n1, TreeNode* n2, TreeNode* &ans){
	
    if(head == 0 || n1 == 0 || n2 == 0)
		 return;
	
    if(head && father(head, n1) && father(head, n2))
	{
        ans = head;
        first_ancestor2(head->left, n1, n2, ans);
        first_ancestor2(head->right, n1, n2, ans);
    }
	
}

//bottom up appraoch O(n)
TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
	if(root == 0)
		return 0;
	if(root == node1 || root == node2)
		return root;
	
	TreeNode* lTree = LCA(root->left,node1,node2);
	
	TreeNode* rTree = LCA(root->right,node1,node2);
	
	if(lTree && rTree)
		return root;
	
	return (lTree)? lTree : rTree;
}

/*
int main()
{
	vector<int> foo;
	for(int i = 1; i <= 10; i++)
		foo.push_back(i);
	
	TreeNode* root = sortedArrayToBST(foo);
		
	TreeNode* node1 = FoundNode(root,8);
	
	TreeNode* node2 = FoundNode(root,6);
	
	TreeNode* parent = 0;
	first_ancestor2(root,node1,node2,parent);
	
	TreeNode* parent1 = LCA(root,node1,node2);
	
	cout << parent->v << " " << parent1->v << endl;
	
}
*/