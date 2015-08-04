/*
	
Partition an integers array into odd number first and even number second.

Have you met this question in a real interview? Yes
Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]

Challenge
Do it in-place.
	
*/

#include "../commonHeader.h"

void partitionArray(vector<int> &nums) 
{
	int odd = 0;
	int even = nums.size() - 1;
	while(odd <= even)
	{
		if((nums[odd] & 0x01) == 1)
		{
			odd++;
		}
		else
		{
			int tmp = nums[even];
			nums[even] = nums[odd];
			nums[odd] = tmp;
			even--;
		}
	}
}

int main()
{
	vector<int> foo = {2147483644,2147483645,2147483646,2147483647};
	partitionArray(foo);
	for(int i : foo)
	{
		cout << i << " ";
	}
	cout << endl;
}