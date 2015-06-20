/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
  3
  / \
  9  20
  /  \
  15   7
  return its bottom-up level order traversal as:
  [
  [15,7]
  [9,20],
  [3],
  ]
*/


#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (), right () {}
};

/*
frist implementation

vector<vector<int> > levelOrder (TreeNode* root)
{
  vector<vector<int> > ret;
  if (!root)
    return ret;
  vector<int> l;
  queue<TreeNode*> q;
  q.push (root);
  int cur = 1;
  int next = 0;
  while (!q.empty() ) {
    TreeNode* node = q.front();
    l.push_back (node->val);
    q.pop();
    cur--;
    if (node->left) {
      q.push (node->left);
      next++;
    }
    if (node->right) {
      q.push (node->right);
      next++;
    }
    if (cur == 0) {
      ret.push_back (l);
      l.clear();
      cur = next;
      next = 0;
    }
  }
  vector<vector<int> > retrev;
  for (int i = ret.size() - 1; i >= 0; i--) {
    retrev.push_back (ret[i]);
  }
  return retrev;
}
*/

//second implementation
vector<vector<int> > levelOrderBottom(TreeNode *root) 
{
	vector<vector<int> > result;
	if(root == 0)
		return result;
	
	queue<TreeNode*> q;
	vector<int> level;
	q.push(root);
	int curLevel = 1;
	int nextLevel = 0;
	
	
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
			result.push_back(level);
			level.clear();
			curLevel = nextLevel;
			nextLevel = 0;
		}
	}
	
	reverse(result.begin(),result.end());
	
	return result;
}


int main()
{
}
