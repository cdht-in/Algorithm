#include <vector>

using namespace std;

struct TreeNode 
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left(), right() {}
};

struct ListNode 
{
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};

class BinarySearchTree
{
	
	TreeNode* mRoot;
	
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
	
	TreeNode *sortedListToBSTHelper(ListNode *node) 
	{
		if(node->next == 0)
		{
			return new TreeNode(node->val);
		}
		//find the mid point to be the parent
		ListNode* f = node;
		ListNode* s = node;
		ListNode* sPrev = 0;
		while(f)
		{
			f = f->next;
			if(f == 0)
				break;
			f = f->next;
			if(f == 0)
				break;
			sPrev = s;
			s = s->next;
		}
	
		ListNode* leftHalf = 0;
		//it has left tree
		if(sPrev != 0){
			sPrev->next = 0;
			leftHalf = node;
		}
	
		//it has right tree
		ListNode* rightHalf = 0;
		if(s->next != 0)
		{
			rightHalf = s->next;
			s->next = 0;
		}

		TreeNode* parentNode = new TreeNode(s->val);
		
		if(leftHalf != 0)
			parentNode->left = sortedListToBSTHelper(leftHalf);	
		if(rightHalf != 0)
			parentNode->right  = sortedListToBSTHelper(rightHalf);
		
		return parentNode;
		
	}
	
	TreeNode* FindValueHelper(TreeNode* node, int v)
	{
		if(node == 0)
			return node;
		
		if(node->val == v)
			return node;
		
		if(node->val < v)
		{
			return FindValueHelper(node->right,v);
		}
		
		return FindValueHelper(node->left,v);
	}
	
	TreeNode* LowestCommonAncestorInBinarySearchTreeHelper(TreeNode* node,TreeNode* node1, TreeNode* node2)
	{
		if(node == 0)
			return node;
		
		if(node1->val <= node->val && node->val <= node2->val)
			return node;
		
		if(node->val < node1->val)
			return LowestCommonAncestorInBinarySearchTreeHelper(node->right,node1,node2);
		
		return LowestCommonAncestorInBinarySearchTreeHelper(node->left,node1,node2);	
		
	}
	
	TreeNode* LowestCommonAncestorInBinaryTreeHelper(TreeNode* node,TreeNode* node1, TreeNode* node2)
	{
		if(node == 0)
			return node;
		
		if(node->val == node1->val || node->val == node2->val)
			return node;
		
		TreeNode* lTree = LowestCommonAncestorInBinaryTreeHelper(node->left,node1,node2);
		
		TreeNode* rTree = LowestCommonAncestorInBinaryTreeHelper(node->right,node1,node2);
		
		if(lTree && rTree)
			return node;
		
		return (lTree)? lTree : rTree;
		
	}
	
public:
	
	BinarySearchTree(vector<int> &num):mRoot(0)
	{
		if(num.size() == 0)
		{
			return;
		}
		
		mRoot = sortedArrayToBSTHelper(num,0,num.size() - 1);	
	}
	
	BinarySearchTree(ListNode* head):mRoot(0)
	{
		if(head == 0)
		{
			return;
		}
		mRoot = sortedListToBSTHelper(head);
	}
	
	TreeNode* FindValue(int v)
	{
		return FindValueHelper(mRoot,v);
	}
	
	//assuming both nodes are present
	TreeNode* LowestCommonAncestorInBinarySearchTree(TreeNode* node1, TreeNode* node2)
	{
		if(node1 == 0 || node2 == 0)
			return 0;
		
		if(node1->val > node2->val)
		{
			TreeNode* tmp = node1;
			node1 = node2;
			node2 = tmp;
		}		
		
		return LowestCommonAncestorInBinarySearchTreeHelper(mRoot,node1,node2);
	}
	
	//assuming both nodes are present
	TreeNode* LowestCommonAncestorInBinaryTree(TreeNode* node1, TreeNode* node2)
	{
		if(node1 == 0 || node2 == 0)
			return 0;
			
		return LowestCommonAncestorInBinaryTreeHelper(mRoot,node1,node2);
	}
	
			
};


