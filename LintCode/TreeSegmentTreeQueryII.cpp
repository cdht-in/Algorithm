/*
	
For an array, we can build a SegmentTree for it, each node stores an extra attribute count to denote the number of elements in the the array which value is between interval start and end. (The array may not fully filled by elements)

Design a query method with three parameters root, start and end, find the number of elements in the in array's interval [start, end] by the given root of value SegmentTree.

Have you met this question in a real interview? Yes
Example
For array [0, 2, 3], the corresponding value Segment Tree is:

                     [0, 3, count=3]
                     /             \
          [0,1,count=1]             [2,3,count=2]
          /         \               /            \
   [0,0,count=1] [1,1,count=0] [2,2,count=1], [3,3,count=1]
query(1, 1), return 0

query(1, 2), return 1

query(2, 3), return 2

query(0, 2), return 2
	
*/

#include "../commonHeader.h"

class SegmentTreeNode 
{
public:
    int start, end, count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int count) 
	{
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = 0;
    }
};

SegmentTreeNode * build(int start, int end,unordered_map<int,int>& map)
{	
	assert(start <= end);
	
	SegmentTreeNode* node = new SegmentTreeNode(start,end,0);
	if(start == end)
	{
		if(map.find(start) != map.end())
		{
			node->count = map[start];
		}
		return node;
	}
	
	int mid = start + (end - start) / 2;
	node->left = build(start,mid,map);
	node->right = build(mid + 1, end,map);
	
	assert(node->left && node->right);
	node->count = node->left->count + node->right->count;
	
	return node;
}

void PrintTree(SegmentTreeNode* root)
{
	if(root == 0)
		return;
	
	cout << root->start << " , " << root->end << " , " << root->count << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

//query the number of elements in the interval
//O(logn)
int query(SegmentTreeNode *root, int start, int end) 
{
	//out of bound query, assuming start <= end
	if(root == 0 || start > root->end || end < root->start)
		return 0;
	
	//partially inbound, adjust the bound
	if(start < root->start && end > root->start)
		start = root->start;
	else if(end > root->end && start < root->end)
		end = root->end;
	
	if(root->start == start && root->end == end )
	{
		return root->count;
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
	
	return max1 + max2;
}


int main()
{
	vector<int> vec = {10};
	int min = 0, max = 10;
	unordered_map<int,int> map;
	for(int i : vec)
	{
		map[i]++;
	}
	SegmentTreeNode* root = build(min,max,map);
	//PrintTree(root);
	cout << query(root,1,10) << endl;
	cout << query(root,9,5) << endl;
	cout << query(root,11,12) << endl;
}