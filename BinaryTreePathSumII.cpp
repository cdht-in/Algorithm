/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
  5
  / \
  4   8
  /   / \
  11  13  4
  /  \    / \
  7    2  5   1
  return
  [
  [5,4,11,2],
  [5,8,4,5]
  ]
*/
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val (x), left (0), right (0) {}
};

/*
first implementation

void hasPathSumHelper (TreeNode* node, int cur, int sum, vector<int>& vec, vector<vector<int> >& ret)
{
  cur += node->val;
  vec.push_back (node->val);
  if (!node->left && !node->right) {
    if (cur == sum) {
      ret.push_back (vec);
    }
  }
  if (node->left) {
    hasPathSumHelper (node->left, cur, sum, vec, ret);
  }
  if (node->right) {
    hasPathSumHelper (node->right, cur, sum, vec, ret);
  }
  cur -= node->val;
  vec.pop_back();
}

vector<vector<int> > pathSum (TreeNode* root, int sum)
{
  vector<vector<int> > ret;
  if (!root)
    return ret;;
  int cur = 0;
  vector<int> vec;
  hasPathSumHelper (root, cur, sum, vec, ret);
  return ret;
}

*/

//second implementation
void hasPathSumHelper(TreeNode *node, int sum, int localSum,vector<vector<int> >& paths, vector<int>& path) 
{
	if(node->left == 0 && node->right == 0)
	{
		if(node->val + localSum == sum)
		{
			path.push_back(node->val);	
			paths.push_back(path);
			
			//delete the leaf node from the path
			path.pop_back();
		}
	}
	
	
	localSum += node->val;
	path.push_back(node->val);
	
	if(node->left != 0)
	{
		hasPathSumHelper(node->left,sum, localSum,paths,path);
	}
	
	if(node->right != 0)
	{
		hasPathSumHelper(node->right,sum,localSum,paths,path);
	}
	
	//delete this node from the path
	path.pop_back();	
}		

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > paths;
	vector<int> path;
	if(root == 0)
		return paths;
	hasPathSumHelper(root,sum,0,paths,path);
	return paths;
}








































void pathSumIHelper(TreeNode* node, int curSum, int sum,vector<int>& path, vector<vector<int> >& paths)
{
	if(node->left == 0 && node->right == 0)
	{
		if(node->val + curSum == sum)
		{
			path.push_back(node->val);
			
			paths.push_back(path);
			
			path.pop_back();
		}
		return;
	}
	
	path.push_back(node->val);
	
	if(node->left)
	{
		pathSumIHelper(node->left,curSum + node->val, sum,path,paths);
	}
	
	if(node->right)
	{
		pathSumIHelper(node->right,curSum + node->val, sum,path,paths);
	}
	
	path.pop_back();
}

//third implementation
vector<vector<int> > pathSumI(TreeNode *root, int sum) 
{
	vector<vector<int> > paths;
	vector<int> path;
    if(root == 0)
	 	return paths;
	
	 pathSumIHelper(root,0,sum,path,paths);
	 return paths;
}


int main()
{
}
