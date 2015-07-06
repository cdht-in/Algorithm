/*	
	Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space

*/

#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) 
{
	vector<int> ret;
	if(nums.size() == 0)
		return ret;
	//there can be at most 2 majority elements
	int a = 0, b = 0;
	int ac = 0, bc = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(ac == 0)
		{
			a = nums[i];
		}
		if(bc == 0 && nums[i] != a)
		{
			b = nums[i];
		}
		if(nums[i] == a)
		{
			ac++;
		}
		if(nums[i] == b)
		{
			bc++;
		}
		
		if(ac && bc && nums[i] != a && nums[i] != b)
		{
			ac--;
			bc--;
		}
	}
	
	ac = 0;
	bc = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] == a)
			ac++;
		if(nums[i] == b)
			bc++;
	}
		
	if(ac > nums.size() / 3)
		ret.push_back(a);
	if(bc > nums.size() / 3 && a != b)
		ret.push_back(b);
	
	return ret;
}



int main()
{
	
}