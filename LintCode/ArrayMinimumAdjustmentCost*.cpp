/*

Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|

Have you met this question in a real interview? Yes
Example
Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.

Return 2.

Note
You can assume each number in the array is a positive integer and not greater than 100.

*/

#include "../commonHeader.h"

//note here the array B is crucial to record the previous step, which may effect the next step
void MinAdjustmentCostHelper(const vector<int>& A,vector<int>& B,int index,int target,int& min, int sum)
{
	if(index >= A.size())
	{
		min = std::min(min,sum);
		return;
	}
	
	for(int i = 1; i <= 100; i++)
	{	
		//note here B[index - 1] is used instead of A[index - 1] because it records the previous steps
		if(index > 0 && std::abs(B[index - 1] - i) > target)
		{
			continue;
		}
		
		B[index] = i;
		int diff = std::abs(A[index] - B[index]);
		MinAdjustmentCostHelper(A,B,index + 1,target,min,sum + diff);
	}
}

//with modification but still exceed time limit
void MinAdjustmentCostHelperI(const vector<int>& A,vector<int>& B,int index,int target,int& min, int sum)
{
	if(index >= A.size())
	{
		min = std::min(min,sum);
		return;
	}
	
	int begin = 0;
	int end = 0;
	
	if(index == 0)
	{
		begin = 1;
		end = 100;		
	}
	else
	{
		begin = B[index - 1] - target;		
		end = B[index - 1] + target;
	}
	
	for(int i = begin; i <= end; i++)
	{
		B[index] = i;
		int diff = std::abs(A[index] - B[index]);
		MinAdjustmentCostHelperI(A,B,index + 1,target,min,sum + diff);
	}
}

//with further modification but still exceed time limit
void MinAdjustmentCostHelperII(const vector<int>& A,vector<int>& B,int index,int target,int& min, int sum)
{
	if(index >= A.size())
	{
		min = std::min(min,sum);
		return;
	}
	
	int begin = 0;
	int end = 0;
	
	if(index == 0)
	{
		begin = 1;
		end = 100;		
	}
	else
	{
		begin = B[index - 1] - target;		
		end = B[index - 1] + target;
	}
	
	for(int i = begin; i <= end; i++)
	{
		B[index] = i;
		int diff = std::abs(A[index] - B[index]);
		
		if(sum + diff >= min)
		{
			continue;
		}
		
		MinAdjustmentCostHelperII(A,B,index + 1,target,min,sum + diff);
	}
}

int MinAdjustmentCost(vector<int> A, int target) 
{
	if(A.size() <= 1)
		return 0;
	
	vector<int> B(A.size(),0);
	int min = INT_MAX;
	//vector<vector<int> > memory(A.size(),vector<int>(101,INT_MAX));
	MinAdjustmentCostHelperII(A,B,0,target,min,0);
	return min;
}

//backpack problem
int MinAdjustmentCostII(vector<int> A, int target) 
{
	if(A.size() <= 1)
		return 0;
	
	vector<vector<int> > dp(A.size() + 1,vector<int>(101,0));
	for(int i = 1; i <= A.size(); i++)
	{
		//if we make the A[i] to be j
		for(int j = 1; j <= 100; j++)
		{
			dp[i][j] = INT_MAX;
			//then j can be changed to k between two bounds
			int begin = std::max(1,j - target);
			int end = std::min(100,j + target);
			//then the previous number i - 1 could only be chosen from [begin,end]
			for(int k = begin; k <= end; k++)
			{
				dp[i][j] = std::min(dp[i][j],dp[i - 1][k] + std::abs(A[i - 1] - j));
			}
		}
	}
	
	int min = INT_MAX;
	for(int i = 1; i <= 100; i++)
	{
		min = std::min(min,dp[A.size()][i]);
	}
	
	return min;
}


int main()
{
	vector<int> A = {1,4,2,3};
	int target = 1;
	cout << MinAdjustmentCostII(A,target) << endl;
}