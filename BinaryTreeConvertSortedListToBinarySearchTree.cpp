/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};


struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next () {}
};


/*

first implementation

TreeNode* BuildBST (ListNode*& list, int start, int end)
{
  if (start > end)
    return 0;
  int mid = (start + end) / 2; //if use start + (end - start) >> 1, test case will break, strange!
  TreeNode* leftChild = BuildBST (list, start, mid - 1);
  TreeNode* parent = new TreeNode (list->val);
  parent->left = leftChild;
  list = list->next;
  parent->right = BuildBST (list, mid + 1, end);
  return parent;
}

TreeNode* sortedListToBST (ListNode* head)
{
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int len = 0;
  ListNode* p = head;
  while (p) {
    len++;
    p = p->next;
  }
  return BuildBST (head, 0, len - 1);
}


*/

//second implementation, bottom up construction
TreeNode *sortedListToBSTHelper(ListNode *node) {
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

TreeNode *sortedListToBST(ListNode *head) {
	if(head == 0)
		return 0;
	return sortedListToBSTHelper(head);
}


int main()
{
}

