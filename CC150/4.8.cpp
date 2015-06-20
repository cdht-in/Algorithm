/*
	
	You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.

*/
#include "4.6.cpp"

//O(n ^ 2), this wouldn't print the "path" between two leaf node. However, if the definition of a path is between a node and its descendent, this would do fine
void PrintPathHelper(TreeNode* node,int sum,vector<int>& path,int level)
{
	if(node == 0)
		return;
	
	path.push_back(node->v);
	
	int tmp = 0;
	for(int i = level; i >= 0; i--)
	{
		tmp += path[i];
		if(tmp == sum)
		{
			//print the paths
			for(int j = i; j < path.size(); j++)
			{
				cout << path[j] << " ";
			}
			cout << endl;
		}
	}
	
	PrintPathHelper(node->left,sum,path,level + 1);
	
	PrintPathHelper(node->right,sum,path,level + 1);
	
	path.pop_back();
	
}

void PrintPath(TreeNode* root,int sum)
{
	vector<int> path;
	PrintPathHelper(root,sum,path,0);
}

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(2);
	
	node1->left = node2;
	node1->right = node3;
	
	int sum = 3;
	
	PrintPath(node1,sum);
}