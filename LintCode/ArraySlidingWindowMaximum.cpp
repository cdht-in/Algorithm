/*
	
Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving.

Have you met this question in a real interview? Yes
Example
For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]

At first the window is at the start of the array like this

[|1, 2, 7| ,7, 8] , return the maximum 7;

then the window move one step forward.

[1, |2, 7 ,7|, 8], return the maximum 7;

then the window move one step forward again.

[1, 2, |7, 7, 8|], return the maximum 8;

Challenge
o(n) time and O(k) memory
	
*/

#include "../commonHeader.h"

//O(nlog(n)) in time and O(k) in space
vector<int> maxSlidingWindow(vector<int> &nums, int k) 
{
	vector<int> ret;
	multiset<int> window;
	
	int i = 0, j = 0;
	for(; j < nums.size() && j < i + k; j++)
	{
		window.insert(nums[j]);
	}
	//find the max
	if(window.empty() == false)
	{
		ret.push_back(*window.lower_bound(*window.rbegin()));
	}
	
	while(j < nums.size())
	{
		//remove the left one
		window.erase(window.find(nums[j - k]));
		window.insert(nums[j]);
		
		//find the max
		ret.push_back(*window.lower_bound(*window.rbegin()));
		j++;
	}
	
	return ret;
}

int main()
{
	vector<int> vec = {1,2,7,7,8};
	int k = 8;
	vector<int> ret = maxSlidingWindow(vec,k);
	for(auto& i : ret)
		cout << i << " ";
	cout << endl;
}