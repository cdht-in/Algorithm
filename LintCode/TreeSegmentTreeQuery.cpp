/*
	
For an integer array (index from 0 to n-1, where n is the size of this array), in the corresponding SegmentTree, each node stores an extra attribute max to denote the maximum number in the interval of the array (index from start to end).

Design a query method with three parameters root, start and end, find the maximum number in the interval [start, end] by the given root of segment tree.

Have you met this question in a real interview? Yes
Example
For array [1, 4, 2, 3], the corresponding Segment Tree is:

                  [0, 3, max=4]
                 /             \
          [0,1,max=4]        [2,3,max=3]
          /         \        /         \
   [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]
query(root, 1, 1), return 4

query(root, 1, 2), return 4

query(root, 2, 3), return 3

query(root, 0, 2), return 4

Note
It is much easier to understand this problem if you finished Segment Tree Build first.
	
*/

#include "../commonHeader.h"

class SegmentTreeNode 
{
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) 
	{
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = 0;
    }
};

//O(n) to build the tree
SegmentTreeNode * build(int start, int end,vector<int>& vec)
{	
	assert(start <= end);
	
	SegmentTreeNode* node = new SegmentTreeNode(start,end,0);
	if(start == end)
	{
		node->max = vec[start];
		return node;
	}
	
	int mid = start + (end - start) / 2;
	node->left = build(start,mid,vec);
	node->right = build(mid + 1, end,vec);
	
	assert(node->left && node->right);
	node->max = std::max(node->left->max,node->right->max);
	
	return node;
}

//query the max in the interval [start,end]
//log(n)
int query(SegmentTreeNode *root, int start, int end) 
{	
	if(root->start == start && root->end == end)
	{
		return root->max;
	}
	
	int mid = root->start + (root->end - root->start) / 2;
	
	if(end <= mid)
	{
		return query(root->left,start,end);
	}
	//NOTE here the right child starts at mid + 1
	else if(start > mid)
	{
		return query(root->right,start,end);
	}
	
	//the interval spans over two children
	int max1 = query(root->left,start,mid);
	int max2 = query(root->right,mid + 1,end);
	
	return std::max(max1,max2);
}

int main()
{
	vector<int> vec = {1,4,2,3};
	SegmentTreeNode* root = build(0,vec.size() - 1, vec);
	cout << query(root,0,2) << endl;
}
