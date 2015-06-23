#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :
			val(x), left(), right()
	{
	}
};

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :
			val(x), next()
	{
	}
};

class BinarySearchTree
{

	TreeNode* mRoot;

	TreeNode* sortedArrayToBSTHelper(vector<int> &num, int l, int r)
	{
		if (l > r)
			return 0;
		int mid = (l + r) / 2;
		TreeNode* parentNode = new TreeNode(num[mid]);
		parentNode->left = sortedArrayToBSTHelper(num, l, mid - 1);
		parentNode->right = sortedArrayToBSTHelper(num, mid + 1, r);
		return parentNode;
	}

	TreeNode *sortedListToBSTHelper(ListNode *node)
	{
		if (node->next == 0)
		{
			return new TreeNode(node->val);
		}
		//find the mid point to be the parent
		ListNode* f = node;
		ListNode* s = node;
		ListNode* sPrev = 0;
		while (f)
		{
			f = f->next;
			if (f == 0)
				break;
			f = f->next;
			if (f == 0)
				break;
			sPrev = s;
			s = s->next;
		}

		ListNode* leftHalf = 0;
		//it has left tree
		if (sPrev != 0)
		{
			sPrev->next = 0;
			leftHalf = node;
		}

		//it has right tree
		ListNode* rightHalf = 0;
		if (s->next != 0)
		{
			rightHalf = s->next;
			s->next = 0;
		}

		TreeNode* parentNode = new TreeNode(s->val);

		if (leftHalf != 0)
			parentNode->left = sortedListToBSTHelper(leftHalf);
		if (rightHalf != 0)
			parentNode->right = sortedListToBSTHelper(rightHalf);

		return parentNode;

	}

	void KeysHelper(TreeNode* node, int key1, int key2,
			vector<TreeNode*>& nodes)
	{
		if (node == 0)
			return;

		KeysHelper(node->left, key1, key2, nodes);
		if (node->val >= key1 && node->val <= key2)
		{
			nodes.push_back(node);
		}
		KeysHelper(node->right, key1, key2, nodes);
	}

	TreeNode* MinHelper(TreeNode* node)
	{
		while (node)
		{
			if (node->left == 0)
				break;

			node = node->left;
		}

		return node;
	}

	TreeNode* DeleteHelper(TreeNode* node, int key)
	{
		if (node == 0)
			return node;
		if (node->val > key)
		{
			node->left = DeleteHelper(node->left, key);
		}
		else if (node->val < key)
		{
			node->right = DeleteHelper(node->right, key);
		}
		else
		{
			//found the target
			if (node->left == 0)
				return node->right;
			if (node->right == 0)
				return node->left;

			//two children
			TreeNode* tmp = node;
			node = MinHelper(tmp->right);
			node->right = DeleteMinHelper(tmp->right);
			node->left = tmp->left;
		}
		return node;
	}

	TreeNode* DeleteMaxHelper(TreeNode* node)
	{
		if (node->right == 0)
		{
			TreeNode* tmp = node->left;
			delete node;
			return tmp;
		}
		node->right = DeleteMaxHelper(node->right);
		return node;
	}

	TreeNode* DeleteMinHelper(TreeNode* node)
	{
		if (node->left == 0)
		{
			TreeNode* tmp = node->right;
			delete node;
			return tmp;
		}

		node->left = DeleteMinHelper(node->left);
		return node;
	}

	void PrintTreeInOrderHelper(TreeNode* node)
	{
		if (node == 0)
			return;
		PrintTreeInOrderHelper(node->left);
		cout << node->val << " ";
		PrintTreeInOrderHelper(node->right);
	}

//number of nodes in its subtree
	int Size(TreeNode* node)
	{
		if (node == 0)
			return 0;
		int l = Size(node->left);
		int r = Size(node->right);
		return 1 + l + r;
	}

	TreeNode* RankHelper(TreeNode* node, int k)
	{
		if (node == 0)
			return node;

		int t = Size(node->left);

		if (t == k)
		{
			return node;
		}
		else if (t > k)
		{
			return RankHelper(node->left, k);
		}
		else
		{
			return RankHelper(node->right, k - t - 1);
		}
	}

	TreeNode* FindValueHelper(TreeNode* node, int v)
	{
		if (node == 0)
			return node;

		if (node->val == v)
			return node;

		if (node->val < v)
		{
			return FindValueHelper(node->right, v);
		}

		return FindValueHelper(node->left, v);
	}

	TreeNode* LowestCommonAncestorInBinarySearchTreeHelper(TreeNode* node,
			TreeNode* node1, TreeNode* node2)
	{
		if (node == 0)
			return node;

		if (node1->val <= node->val && node->val <= node2->val)
			return node;

		if (node->val < node1->val)
			return LowestCommonAncestorInBinarySearchTreeHelper(node->right,
					node1, node2);

		return LowestCommonAncestorInBinarySearchTreeHelper(node->left, node1,
				node2);

	}

//note this one doesn't guarantee it's a BST
	TreeNode* LowestCommonAncestorInBinaryTreeHelper(TreeNode* node,
			TreeNode* node1, TreeNode* node2)
	{
		if (node == 0)
			return node;

		if (node->val == node1->val || node->val == node2->val)
			return node;

		TreeNode* lTree = LowestCommonAncestorInBinaryTreeHelper(node->left,
				node1, node2);

		TreeNode* rTree = LowestCommonAncestorInBinaryTreeHelper(node->right,
				node1, node2);

		if (lTree && rTree)
			return node;

		return (lTree) ? lTree : rTree;
	}

	void InsertHelper(TreeNode* node, TreeNode*& parent, int val)
	{
		if (node == 0)
		{
			parent = new TreeNode(val);
			return;
		}

		if (node->val == val)
			return;

		if (val < node->val)
		{
			InsertHelper(node->left, node->left, val);
		}
		else
		{
			InsertHelper(node->right, node->right, val);
		}
	}

	TreeNode* FloorHelper(TreeNode* node, int val)
	{
		if (node == 0 || node->val == val)
			return node;
		if (val < node->val)
		{
			return FloorHelper(node->left, val);
		}
		TreeNode* tmp = FloorHelper(node->right, val);
		if (tmp)
			return tmp;
		return node;
	}

	TreeNode* CeilHeler(TreeNode* node, int val)
	{
		if (node == 0 || node->val == val)
			return node;
		if (val < node->val)
		{
			TreeNode* tmp = FloorHelper(node->left, val);
			if (tmp)
				return tmp;
			return node;
		}
		return FloorHelper(node->right, val);
	}

public:

	BinarySearchTree(vector<int> &num) :
			mRoot(0)
	{
		if (num.size() == 0)
		{
			return;
		}

		mRoot = sortedArrayToBSTHelper(num, 0, num.size() - 1);
	}

	BinarySearchTree(ListNode* head) :
			mRoot(0)
	{
		if (head == 0)
		{
			return;
		}
		mRoot = sortedListToBSTHelper(head);
	}

	TreeNode* FindValue(int v)
	{
		return FindValueHelper(mRoot, v);
	}

	void Insert(int val)
	{
		InsertHelper(mRoot, mRoot, val);
	}

	TreeNode* Min()
	{
		return MinHelper(mRoot);
	}

	TreeNode* Max()
	{
		TreeNode* node = mRoot;
		if (node == 0)
			throw "empty tree";

		while (node && node->right)
		{
			node = node->right;
		}

		return node;
	}

	TreeNode* Floor(int val)
	{
		return FloorHelper(mRoot, val);
	}

	TreeNode* Ceil(int val)
	{
		return FloorHelper(mRoot, val);
	}

	void PrintTreeInOrder()
	{
		PrintTreeInOrderHelper(mRoot);
		cout << endl;
	}

//assuming both nodes are present
	TreeNode* LowestCommonAncestorInBinarySearchTree(TreeNode* node1,
			TreeNode* node2)
	{
		if (node1 == 0 || node2 == 0)
			return 0;

		if (node1->val > node2->val)
		{
			TreeNode* tmp = node1;
			node1 = node2;
			node2 = tmp;
		}

		return LowestCommonAncestorInBinarySearchTreeHelper(mRoot, node1, node2);
	}

//assuming both nodes are present
	TreeNode* LowestCommonAncestorInBinaryTree(TreeNode* node1, TreeNode* node2)
	{
		if (node1 == 0 || node2 == 0)
			return 0;

		return LowestCommonAncestorInBinaryTreeHelper(mRoot, node1, node2);
	}

	TreeNode* Rank(int k)
	{
		return RankHelper(mRoot, k);
	}

	void DeleteMin()
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteMinHelper(mRoot);
	}

	void DeleteMax()
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteMaxHelper(mRoot);
	}

	void Delete(int key)
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteHelper(mRoot, key);
	}

	vector<TreeNode*> Keys(int key1, int key2)
	{
		vector<TreeNode*> nodes;
		KeysHelper(mRoot, key1, key2, nodes);
		return nodes;
	}

};
