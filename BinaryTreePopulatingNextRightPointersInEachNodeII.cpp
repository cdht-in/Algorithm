/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
	
*/

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(0), right(0), next(0) {}
  };

void connect(TreeLinkNode *root) {
	
	TreeLinkNode *leftMost = root;
        
	while(leftMost) 
	{
	    root = leftMost;
		
		//leaf node
	    while(root && root->left == 0 && root->right == 0)
			root = root->next;
	    if(root == 0)
			 return;
		
	    leftMost = root->left ? root->left : root->right;
	    TreeLinkNode *cur = leftMost;
    
	    while(root) 
		{
	        if(cur == root->left) 
			{  
	            if(root->right) 
				{
	                cur->next = root->right;
	                cur = cur->next;
	            }
	            root = root->next;
	        }
	        else if(cur == root->right) 
			{ 
	            root = root->next;
	        }
	        else 
			{ 
				// cur is the child of the previous node of the current root
				//skip those root with no children
	            if(root->left == 0 && root->right == 0) 
				{
	                root = root->next;
	                continue;
	            } 
	            cur->next = root->left ? root->left : root->right;    
	            cur = cur->next;
	        }
	    }
	} 
}








































//second implementation

void connectI(TreeLinkNode *root) 
{
	TreeLinkNode* parent = 0;
	TreeLinkNode* node = root;
	while(node)
	{
		
	} 
}

int main()
{
	
	
}