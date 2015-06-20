
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

int majorityElement(vector<int> &num) {
	map<int, int> numberMap;
	int result = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (numberMap.find(num[i]) == numberMap.end())
		{
			numberMap[num[i]] = 1;
		}
		else{
			numberMap[num[i]]++;
		}
		if (numberMap[num[i]] > num.size() / 2)
		{
			result = num[i];
			break;
		}
	}
	return result;
}