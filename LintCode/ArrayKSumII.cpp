/*
	
Given n unique integers, number k (1<=k<=n)  and target. Find all possible k integers where their sum is target.

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4], k=2, target=5, [1,4] and [2,3] are possible solutions.
	
*/

#include "../commonHeader.h"

void kSumIIHelper(vector<vector<int> >& ret, vector<int>& set, const vector<int>& A , int index, int sum, int k, int target)
{
	if(set.size() == k && sum == target)
	{
		ret.push_back(set);
		return;
	}
		
	if(set.size() == k)
	{
		return;
	}
	
	for(int i = index; i < A.size(); i++)
	{
		if(sum + A[i] > target)
			break;
		
		set.push_back(A[i]);
		kSumIIHelper(ret,set,A,i + 1,sum + A[i],k,target);
		set.pop_back();
	}
}

vector<vector<int> > kSumII(vector<int> A, int k, int target) 
{
	vector<vector<int> > ret;
	sort(A.begin(),A.end());
	vector<int> set;
	kSumIIHelper(ret,set,A,0,0,k,target);
	return ret;
}

int main()
{
	
}