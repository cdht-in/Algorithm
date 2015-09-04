/*
	
Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]

Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Challenge
O(logN) time for each query
	
*/

#include "../commonHeader.h"

class Interval 
{
public:
	int start, end;
	Interval(int start, int end) 
	{
	    this->start = start;
	    this->end = end;
	}
};

class SegmentTreeNode 
{
public:
    int start, end;
	long long sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, long long sum) 
	{
        this->start = start;
        this->end = end;
        this->sum = sum;
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
		node->sum = vec[start];
		return node;
	}
	
	int mid = start + (end - start) / 2;
	node->left = build(start,mid,vec);
	node->right = build(mid + 1, end,vec);
	
	assert(node->left && node->right);
	node->sum = node->left->sum + node->right->sum;
	
	return node;
}

long long query(SegmentTreeNode *root, int start, int end) 
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
		return root->sum;
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
	long long sum1 = query(root->left,start,mid);
	long long sum2 = query(root->right,mid + 1,end);
	
	return sum1 + sum2;
}


vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) 
{
	vector<long long> sum;
	if(A.size() < 1)
		return sum;
	
	SegmentTreeNode* root = build(0,A.size() - 1,A);
	for(auto i : queries)
	{
		sum.push_back(query(root,i.start,i.end));
	}
	return sum;
}

int main()
{
	vector<int> vec = {1,2,7,8,5};
	vector<Interval> queries = {Interval(0,4),Interval(1,2),Interval(2,4)};
	
	vector<long long> ret = intervalSum(vec,queries);
	for(auto i : ret)
	{
		cout << i << endl;
	}
}
