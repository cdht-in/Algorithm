/*
	
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller that the given integer.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]

Note
We suggest you finish problem Segment Tree Build and Segment Tree Query II first.

Challenge
Could you use three ways to do it.

Just loop
Sort and binary search
Build Segment Tree and Search.

*/

#include "../commonHeader.h"

//just loop O(n^2)
vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) 
{
	vector<int> ret;
	
	for(int i : queries)
	{
		int c = 0;
		for(auto j : A)
		{
			if(j < i)
				c++;
		}
		ret.push_back(c);
	}
	return ret;
}

int binarySearch(vector<int> &A,int val)
{
	int start = 0; 
	int end = A.size() - 1;
	int mid = 0;
	while(start <= end)
	{
		mid = start + (end - start) / 2;
		if(A[mid] == val)
		{
			//skip the duplicates
			while(mid >= 1 && A[mid] == A[mid - 1])
			{
				mid--;
			}
			return mid;
		}
		else if(A[mid] > val)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	
	//start will be the insertion point
	return start;
}

//binary search n(logn)
vector<int> countOfSmallerNumberI(vector<int> &A, vector<int> &queries)
{
	vector<int> ret;
	sort(A.begin(),A.end());
	
	for(int i : queries)
	{
		int number = binarySearch(A,i);
		ret.push_back(number);
	}
	
	return ret;
}

class SegmentTreeNodeI 
{
public:
    int start, end, count;
    SegmentTreeNodeI *left, *right;
    SegmentTreeNodeI(int start, int end, int count) 
	{
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = 0;
    }
};

SegmentTreeNodeI * build(int start, int end,unordered_map<int,int>& map)
{	
	if(map.size() == 0)
		return 0;
	
	assert(start <= end);
	
	SegmentTreeNodeI* node = new SegmentTreeNodeI(start,end,0);
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

int query(SegmentTreeNodeI *root, int start, int end) 
{
	//out of bound query, assuming start <= end
	if(root == 0 || start > root->end || end < root->start)
		return 0;
	
	//partially inbound, adjust the bound
	if(start <= root->start && end > root->start)
		start = root->start;
	else if(end > root->end && start <= root->end)
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

//with interval tree
//O(n) to build the tree and O(nlogn) to query
vector<int> countOfSmallerNumberII(vector<int> &A, vector<int> &queries)
{
	vector<int> ret;
	
	int min = INT_MAX;
	int max = INT_MIN;
	
	unordered_map<int,int> map;
	for(int i : A)
	{
		max = std::max(max,i);
		min = std::min(min,i);
		map[i]++;
	}
	
	SegmentTreeNodeI* root = build(min,max,map);
	
	for(auto i : queries)
	{
		//search the interval before it
		int c = query(root,min,i - 1);
		ret.push_back(c);
	}
	
	return ret;
}

int main()
{
	vector<int> foo = {30,87,56,25,36,69,47,49,28,3,59,61,16,63,77,63,83,27,15,31,38,81,45,4,93,16,82,24,12,99,18,21,44,69,60,60,86,19,88,62,86,98,58,53,35,24,59,46,67,21};
	vector<int> bar = {11,39,89,46,1,70,65,93,71,7};
	vector<int> ret = countOfSmallerNumberII(foo,bar);
	for(int i : ret)
	{
		cout << i << endl;
	}
}
