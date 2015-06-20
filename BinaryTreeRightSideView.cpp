#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};



vector<int> rightSideView(TreeNode *root) {
	vector<int> ret;
	if(root == 0)
		return ret;
	
	TreeNode* node = root;
	
	queue<TreeNode*> q;
	q.push(root);
	bool levelFirstNode = true;
	int curLevel = 1;
	int nextLevel = 0;
	while(q.empty() == false)
	{
		TreeNode* node = q.front();
		q.pop();
		curLevel--;
		
		if(levelFirstNode)
		{
			ret.push_back(node->val);
			levelFirstNode = false;
		}
		
		if(node->right)
		{
			q.push(node->right);
			nextLevel++;
		}
		
		if(node->left)
		{
			q.push(node->left);
			nextLevel++;
		}
		
		if(curLevel == 0)
		{			
			curLevel = nextLevel;
			levelFirstNode = true;
			nextLevel = 0;
		}
	}
	
	return ret;
}


int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
		
	vector<int> ret = rightSideView(root);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}	
	cout << endl;
}