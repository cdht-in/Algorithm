/*
	
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
	
*/

#include <map>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> vec;
	if(numbers.size() == 0)
		return vec;
	
	map<int,int> map;
	for(int i = 0; i < numbers.size(); i++)
	{
		if(map.find(numbers[i]) == map.end())
		{
			map[numbers[i]] = i;
		}
	}
	
	for(int i = 0; i < numbers.size(); i++)
	{
		if(map.find(target - numbers[i]) != map.end())
		{
			if(map[target - numbers[i]] != i)
			{
				if(i + 1 < map[target - numbers[i]] + 1)
				{
					vec.push_back(i + 1);
					vec.push_back(map[target - numbers[i]] + 1);
				}
				else
				{
					vec.push_back(map[target - numbers[i]] + 1);
					vec.push_back(i + 1);
				}	
				break;
			}
		}
	}
	return vec;
}

int main()
{
	
	
}