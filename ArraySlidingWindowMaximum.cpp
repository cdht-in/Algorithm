/*
	
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

*/

#include <vector>
#include <queue>
#include <climits>

using namespace std;

//at most O(2*n) when the nums is monotomically increasing
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	vector<int> ret;
	if(nums.empty() || k == 0)
		return ret;
	
	deque<int> win;
	int l = 0, r = -1;
	while(r < (int)nums.size())
	{
		int len = r - l + 1;
		if(len == k)
		{
			ret.push_back(win.front());
			if(nums[l] == win.front())
				win.pop_front();
			l++;
		}
		
		r++;
		if(r < (int)nums.size())
		{
			//maintain a decresing stack
			while(win.empty() == false && nums[r] > win.back())
				win.pop_back();
			win.push_back(nums[r]);
		}
	}
	
	return ret;
}

int main()
{
	
}