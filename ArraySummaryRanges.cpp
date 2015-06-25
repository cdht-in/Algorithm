#include <vector>
#include <iostream>

using namespace std;

/*
	
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
	
*/

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> result;
	
	for(int l = 0, r = 1; r <= nums.size(); r++)
	{
		if(r < nums.size() && nums[r] == nums[r - 1] + 1)
			continue;
		
		if(r - 1 == l || r - 1 - l != nums[r - 1] - nums[l])
		{
			result.push_back(to_string(nums[l]));
		}
		else
		{
			result.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));	
		}
		
		l = r;
	}
		
	return result;
        
}

int main()
{
	vector<int> vec = {4,5};
	vector<string> ret = summaryRanges(vec);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}