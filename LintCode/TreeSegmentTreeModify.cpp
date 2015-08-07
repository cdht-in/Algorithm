/*
For a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.

Implement a modify function with three parameter root, index and value to change the node's value with [start, end] = [index, index] to the new given value. Make sure after this change, every node in segment tree still has the max attribute with the correct value.

Have you met this question in a real interview? Yes
Example
For segment tree:

                      [1, 4, max=3]
                    /                \
        [1, 2, max=2]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
if call modify(root, 2, 4), we can get:

                      [1, 4, max=4]
                    /                \
        [1, 2, max=4]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
or call modify(root, 4, 0), we can get:

                      [1, 4, max=2]
                    /                \
        [1, 2, max=2]                [3, 4, max=0]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]
Note
We suggest you finish problem Segment Tree Build and Segment Tree Query first.

Challenge
Do it in O(h) time, h is the height of the segment tree.

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

int modifyHelper(SegmentTreeNode *root, int index, int value)
{
	if(root->start == index && root->end == index)
	{
		root->max = value;
		return root->max;
	}
	
	int mid = root->start + (root->end - root->start) / 2;
	
	int newMax = INT_MIN;
	if(index <= mid)
	{
		newMax = modifyHelper(root->left,index,value);
		root->max = std::max(query(root->right,mid + 1,root->end),newMax);
	}
	//NOTE here the right child starts at mid + 1
	else if(index > mid)
	{
		newMax = modifyHelper(root->right,index,value);
		root->max = std::max(query(root->left,root->start,mid),newMax);
	}
	
	return root->max;
}

void modify(SegmentTreeNode *root, int index, int value) 
{
	//out of bound
	if(root == 0 || index > root->end || index < root->start)
		return;
	
	modifyHelper(root,index,value);
}


int main()
{
	vector<int> vec = {0,2,1,0,3};
	SegmentTreeNode* root = build(1,4,vec);
	modify(root,4,0);
	cout << query(root,1,2) << endl;
}