#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
	int key;
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int key,int val = 0) : key(key),
			val(val), left(), right()
	{
	}
};

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int val) :
			val(val), next()
	{
	}
};

class BinarySearchTree
{
	
protected:
	
	TreeNode* mRoot;
	int size;
	
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
		if (node->key >= key1 && node->key <= key2)
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
		if (node->key > key)
		{
			node->left = DeleteHelper(node->left, key);
		}
		else if (node->key < key)
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

	virtual TreeNode* DeleteMaxHelper(TreeNode* node)
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

	virtual TreeNode* DeleteMinHelper(TreeNode* node)
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
		{	
			return;
		}
			
		PrintTreeInOrderHelper(node->left);
		cout << node->key << " ";
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

	TreeNode* LowestCommonAncestorInBinarySearchTreeHelper(TreeNode* node,
			TreeNode* node1, TreeNode* node2)
	{
		if (node == 0)
			return node;

		if (node1->key <= node->key && node->key <= node2->key)
			return node;

		if (node->key < node1->key)
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

		if (node->key == node1->key || node->key == node2->key)
			return node;

		TreeNode* lTree = LowestCommonAncestorInBinaryTreeHelper(node->left,
				node1, node2);

		TreeNode* rTree = LowestCommonAncestorInBinaryTreeHelper(node->right,
				node1, node2);

		if (lTree && rTree)
			return node;

		return (lTree) ? lTree : rTree;
	}

	TreeNode* FloorHelper(TreeNode* node, int key)
	{
		if (node == 0 || node->key == key)
			return node;
		if (key < node->key)
		{
			return FloorHelper(node->left, key);
		}
		TreeNode* tmp = FloorHelper(node->right, key);
		if (tmp)
			return tmp;
		return node;
	}

	TreeNode* CeilHelper(TreeNode* node, int key)
	{
		if (node == 0 || node->key == key)
			return node;
		if (key < node->key)
		{
			TreeNode* tmp = CeilHelper(node->left, key);
			if (tmp)
				return tmp;
			return node;
		}
		return CeilHelper(node->right, key);
	}

public:

	BinarySearchTree():mRoot(),size(){}
		 
	BinarySearchTree(vector<int> &num) :
			mRoot(),size()
	{
		if (num.size() == 0)
		{
			return;
		}

		mRoot = sortedArrayToBSTHelper(num, 0, num.size() - 1);
	}

	BinarySearchTree(ListNode* head) :
			mRoot(),size()
	{
		if (head == 0)
		{
			return;
		}
		mRoot = sortedListToBSTHelper(head);
	}
	
	virtual bool Contain(int key)
	{
		try
		{
			Get(key);
			return true;
		}
		catch(...)
		{
			return false;
		}
	}

	virtual int Get(int key)
	{
		TreeNode* node = mRoot;
		
		while(node)
		{
			if(node->key == key)
			{
				return node->val;
			}
			else if(node->key > key)
				node = node->left;
			else
				node = node->right;
		}
		
		throw "key doesn't exist";
	}

	virtual void Insert(int key,int val = 0)
	{
		if(mRoot== 0)
		{
			mRoot = new TreeNode(key,val);
			size++;
			return;
		}
		
		TreeNode* node = mRoot;
		while(node)
		{
			if(node->key == key)
			{
				node->val = val;
				return;
			}
			else if(node->key > key)
			{
				if(node->left)
					node = node->left;
				else
				{
					node->left = new TreeNode(key,val);
					break;
				}
			}
			else
			{
				if(node->right)
					node = node->right;
				else
				{
					node->right = new TreeNode(key,val);
					break;
				}
			}
		}
		size++;
	}

	virtual TreeNode* Min()
	{
		return MinHelper(mRoot);
	}

	virtual TreeNode* Max()
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

	virtual TreeNode* Floor(int key)
	{
		return FloorHelper(mRoot, key);
	}

	virtual TreeNode* Ceil(int key)
	{
		return CeilHelper(mRoot, key);
	}

	void PrintTreeInOrder()
	{
		PrintTreeInOrderHelper(mRoot);
		cout << endl;
	}
	
	virtual int GetSize()
	{
		return size;
	}
	
	virtual bool IsEmpty()
	{
		return size == 0;
	}

//assuming both nodes are present
	virtual TreeNode* LowestCommonAncestorInBinarySearchTree(TreeNode* node1,
			TreeNode* node2)
	{
		if (node1 == 0 || node2 == 0)
			return 0;

		if (node1->key > node2->key)
		{
			TreeNode* tmp = node1;
			node1 = node2;
			node2 = tmp;
		}

		return LowestCommonAncestorInBinarySearchTreeHelper(mRoot, node1, node2);
	}

//assuming both nodes are present
	virtual TreeNode* LowestCommonAncestorInBinaryTree(TreeNode* node1, TreeNode* node2)
	{
		if (node1 == 0 || node2 == 0)
			return 0;

		return LowestCommonAncestorInBinaryTreeHelper(mRoot, node1, node2);
	}

	virtual TreeNode* Rank(int k)
	{
		return RankHelper(mRoot, k);
	}

	virtual void DeleteMin()
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteMinHelper(mRoot);
		size--;
	}

	virtual void DeleteMax()
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteMaxHelper(mRoot);
		size--;
	}

	virtual void Delete(int key)
	{
		if (mRoot == 0)
			return;
		mRoot = DeleteHelper(mRoot, key);
		size--;
	}

	virtual vector<TreeNode*> Keys(int key1, int key2)
	{
		vector<TreeNode*> nodes;
		KeysHelper(mRoot, key1, key2, nodes);
		return nodes;
	}
};
