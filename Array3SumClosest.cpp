/*
	
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
 	if(num.size() < 3)
		return 0;
	sort(num.begin(),num.end());
	
	int distant = INT_MAX;
	int sum = 0;
	for(int i = 0; i < num.size() - 2; i++)
	{
		int l = i + 1;
		int r = num.size() - 1;
		//close in the gap
		while(l < r)
		{
			if(num[i] + num[l] + num[r] == target)
			{
				return target;
			}
			else if (num[i] + num[l] + num[r] < target)
			{
				int diff = target - (num[i] + num[l] + num[r]);
				if(distant > diff)
				{
					distant = diff;
					sum = num[i] + num[l] + num[r];
				}
				l++;
			}
			else
			{
				int diff = (num[i] + num[l] + num[r]) - target;
				if(distant > diff)
				{
					distant = diff;
					sum = num[i] + num[l] + num[r];
				}
				r--;
			}
		}
	}
	
	return sum;
}

int main()
{
	
	
}