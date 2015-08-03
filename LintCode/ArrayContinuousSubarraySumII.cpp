/*
	
	Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone. The answer can be rorate array or non- rorate array)

*/

#include "../commonHeader.h"

vector<int> continuousSubarraySumII(vector<int>& A) 
{
	int n = A.size();
	int subSum = 0;
	int max1 = INT_MIN;
	int begin1 = 0;
	int end1 = 0;
	int tmpStart = 0;
	//non circular
	for(int i = 0; i < A.size(); i++)
	{
		if(subSum + A[i] < A[i])
		{
			subSum = A[i];
			tmpStart = i;
		}
		else
		{
			subSum += A[i];
		}
		
		if(subSum > max1)
		{
			max1 = subSum;
			end1 = i;
			begin1 = tmpStart;
		}
	}	
	
	//wrap around situation
	vector<int> fromLeft(n,0);
	vector<int> fromLeftIndex(n,0);
	
	vector<int> fromRight(n,0);
	vector<int> fromRightIndex(n,0);
	
	int sum = A[0];
	fromLeft[0] = sum;
	for(int i = 1; i < n; i++)
	{
		sum += A[i];
		if(sum > fromLeft[i - 1])
		{
			fromLeft[i] = sum;
			fromLeftIndex[i] = i;
		}
		else
		{
			fromLeft[i] = fromLeft[i - 1];
			fromLeftIndex[i] = fromLeftIndex[i - 1];
		}
	}
	
	sum = 0;
	fromRight[n - 1] = sum;
	//fromRightIndex[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--)
	{
		sum += A[i + 1];
		if(sum > fromRight[i + 1])
		{
			fromRight[i] = sum;
			fromRightIndex[i] = i + 1;
		}
		else
		{
			fromRight[i] = fromRight[i + 1];
			fromRightIndex[i] = fromRightIndex[i + 1];
		}
		
	}
	
	int begin2 = 0, end2 = 0;
	int max2 = INT_MIN;
	//NOTE here i == n is covered in the previous case
	for(int i = 0; i < n; i++)
	{
		if(fromLeft[i] + fromRight[i] > max2)
		{
			max2 = fromLeft[i] + fromRight[i];
			begin2 = fromRightIndex[i];
			end2 = fromLeftIndex[i];
		}
	}
	
	if(max1 > max2)
	{
		return vector<int>({begin1,end1});
	}
	
	return vector<int>({begin2,end2});
}

int main()
{
	vector<int> A({-5,10,5,-3,1,1,1,-2,3,-4});
	vector<int> ret = continuousSubarraySumII(A);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}