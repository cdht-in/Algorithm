/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
	
*/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
};
  
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> > result;
	if(root == 0)
		return result;
	
	queue<TreeNode*> q;
	vector<int> level;
	q.push(root);
	int curLevel = 1;
	int nextLevel = 0;
	int leftToRight = true;
	
	while(q.empty() == false)
	{
		TreeNode* node = q.front();
		q.pop();
		curLevel--;
		
		level.push_back(node->val);
		
		if(node->left){
			q.push(node->left);
			nextLevel++;
		}
		
		if(node->right){
			q.push(node->right);
			nextLevel++;
		}
		
		if(curLevel == 0)
		{
			if(leftToRight)
			{
				result.push_back(level);
			}
			else
			{
				reverse(level.begin(), level.end());
				result.push_back(level);
			}
			
			level.clear();
			
			//toggle the direction
			leftToRight = (leftToRight == true)? false : true;
			
			curLevel = nextLevel;
			nextLevel = 0;
		}
	}
	
	return result;
}








































int main()
{
	
	
}