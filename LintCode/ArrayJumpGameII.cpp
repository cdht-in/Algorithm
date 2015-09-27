/*
	
Medium Jump Game II

33% Accepted
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Have you met this question in a real interview? Yes
Example
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/

#include "../commonHeader.h"

//assumption is it can reach the end
int jump(vector<int> A) 
{
	int c = 0;
	if(A.size() == 1)
		return c;
	
	int cur = 0;
	while(cur < A.size())
	{	
		//one jump
		if(cur + A[cur] >= A.size() - 1)
		{
			c++;
			break;
		}
		
		int max = INT_MIN;
		//two jump
		for(int i = 0; i <= A[cur]; i++)
		{
			max = std::max(max,cur + i + A[cur + i]);
		}
		
		c += 2;
		cur = max;
	}
	return c;
}

int main()
{
	vector<int> A = {13,46,6,21,30,15,99,9,12,9,7,74,14,5,3,24,1,31,40,35};
	cout << jumpI(A) << endl;
}