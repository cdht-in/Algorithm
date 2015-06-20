/*

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
	
*/

#include <vector>
#include <climits>

using namespace std;

//O(n) in time
int minSubArrayLen(int s, vector<int>& nums) 
{	
	int len = nums.size();
	int sum = 0;
	int l = 0;
	int r = 0;
	while(r < nums.size())
	{
		sum += nums[r];
		
		if(sum >= s)
		{
			//find the minimal windows
			while(l < r && sum - nums[l] >= s)
			{
				sum -= nums[l];
				l++;
			}
			
			len = (len < r - l + 1)? len : r - l + 1;
			
		}
		
		r++;
	}
	
	return (len == nums.size())? 0 : len;
}

int minSubArrayLenIHelper(int s, vector<int>& nums, int start, int end,int& len)
{
	
}

int minSubArrayLenI(int s, vector<int>& nums) 
{
	int len = num.size();
	minSubArrayLenIHelper(s,nums,0,num.size() - 1,len);
	
}

int main()
{
	
	
}