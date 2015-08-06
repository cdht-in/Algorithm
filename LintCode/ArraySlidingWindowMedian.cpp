/*

Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the median of the element inside the window at each moving. (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]

At first the window is at the start of the array like this

[ | 1,2,7 | ,8,5] , return the median 2;

then the window move one step forward.

[1, | 2,7,8 | ,5], return the median 7;

then the window move one step forward again.

[1,2, | 7,8,5 | ], return the median 7;


*/

#include "../commonHeader.h"

vector<int> medianSlidingWindow(vector<int> &nums, int k) 
{
	vector<int> result;
	int n = nums.size();
	if (n == 0)
	    return result;

	multiset<int> max, min;
	for (int i = 0; i < k; ++i)
	    max.insert(nums[i]);

	for (int i = 0; i < k / 2; ++i) 
	{
	    min.insert(*max.rbegin());
	    max.erase(max.lower_bound(*max.rbegin()));
	}

	for (int i = k; i < n; ++i) 
	{
	    result.push_back(*max.rbegin());
		
		//window's left border
	    if (max.find(nums[i - k]) != max.end())
		{
	        max.erase(max.find(nums[i - k]));
	        max.insert(nums[i]);
	    }
		else
		{
	        min.erase(min.find(nums[i - k]));
	        min.insert(nums[i]);
	    }
		
		//maintain that the biggest in max is always less or equal to the smallest in min
	    if (max.size() > 0 && min.size() > 0 && *max.rbegin() > *min.begin()) 
		{
			//swap the two tops
	        int tmp = *max.rbegin();
	        max.erase(max.lower_bound(*max.rbegin()));
			
	        max.insert(*min.begin());
	        min.erase(min.begin());
			
	        min.insert(tmp);
	    }
	}
	
	result.push_back(*max.rbegin());

	return result;
}

int main()
{
	
}