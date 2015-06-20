/*
	
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
	
*/

#include <vector>
#include <iostream>

using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
	if(nums.size() == 0)
		return 0;
	int p = 0;
	for(int i = 0; i < k; i++)
	{
		int max = nums[p];
		int index = p;
		for(int j = p; j < nums.size(); j++)
		{
			if(nums[j] > max)
			{
				index = j;
				max = nums[j];
			}
		}
		
		int tmp = nums[index];
		nums[index] = nums[p];
		nums[p] = tmp;
		p++;
	}
	return nums[p - 1];
}

int main()
{
	vector<int> foo = {1};
	int k = 1;
	cout << findKthLargest(foo,k) << endl;
	
}