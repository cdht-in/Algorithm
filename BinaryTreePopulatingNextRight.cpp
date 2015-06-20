/*
  Given a binary tree

  struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  }
  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

  Initially, all next pointers are set to NULL.

  Note:

  You may only use constant extra space.
  You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
  For example,
  Given the following perfect binary tree,
  1
  /  \
  2    3
  / \  / \
  4  5  6  7
  After calling your function, the tree should look like:
  1 -> NULL
  /  \
  2 -> 3 -> NULL
  / \  / \
  4->5->6->7 -> NULL
*/

#include <queue>
#include <vector>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode* left, *right, *next;
  TreeLinkNode (int x) : val (x), left(), right(), next() {}
};

/*
//first implementation
void connect (TreeLinkNode* root)
{
  if (!root)
    return;
  queue<TreeLinkNode*> q;
  q.push (root);
  TreeLinkNode* p = root;
  bool head = true;
  int cur = 1;
  int next = 0;
  while (!q.empty() ) {
    TreeLinkNode* tmp = q.front();
    q.pop();
    cur--;
    if (tmp->left) {
      q.push (tmp->left);
      next++;
    }
    if (tmp->right) {
      q.push (tmp->right);
      next++;
    }
    if (head) {
      p = tmp;
      head = false;
    }
    else {
      p->next = tmp;
      p = p->next;
    }
    if (cur == 0) {
      head = true;
      cur = next;
      next = 0;
    }
  }
}
*/

//second implementation

void connect(TreeLinkNode *root) {
	if(root == 0)
		return;
	queue<TreeLinkNode*> q;
	q.push(root);
	
	//becasue it's a perfect binary tree, each eval has 2^levelCount-1 children
	int levelCount = 0;
	
	while(q.empty() == false)
	{
		TreeLinkNode* head = 0;
		int nNode = (1 << levelCount);
		//number of nodes on this level
		for(int i = 0; i < nNode; i++)
		{
			TreeLinkNode* node = q.front();
			q.pop();			
			
			//populate the next level, which would break at the outer loop when the entire tree is traversed
			if(node->left != 0)
				q.push(node->left);
			if(node->right != 0)
				q.push(node->right);
			
			//head
			if(i == 0)
			{
				head = node;
				continue;
			}
			
			head->next = node;
			head = head->next;
		}
		levelCount++;
	}
}






































//second implementation, this would work is the BST is complete
void connectI(TreeLinkNode *root) 
{
	TreeLinkNode* parent = 0;
	TreeLinkNode* node = root;
	while(node)
	{
		//first level only
		if(parent == 0)
		{
			parent = node;
			node = node->left;
		}
		else
		{
			TreeLinkNode* head = node;
			
			while(parent != 0)
			{
				if(parent->left != node)
				{
					node->next= parent->left;
					node = node->next;
				}
				else
				{
					node->next= parent->right;
					node = node->next;
					parent = parent->next;
				}	
			}
			
			parent = head;
			node = head->left;
		}
	}
}

int main()
{
}
