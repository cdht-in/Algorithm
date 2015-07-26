#include "CommonHeader.h"

void Swap(vector<int>& nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

//assume all unique
int findMissing(vector<int> &nums) 
{
	int actualSum = 0;
	int sum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		sum += i;
		actualSum += nums[i];
	}
	
	sum += nums.size();
	return sum - actualSum;
}

int main()
{
	
}