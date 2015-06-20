/*
	
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

#include <vector>

using namespace std;

int rob(vector<int> &num) {	
	if(num.size() == 0)
		return 0;
	if(num.size() == 1)
		return num[0];
	vector<int> max(num.size() + 1,0);
	max[0] = 0;
	max[1] = num[0];
	
	for(int i = 2; i <= num.size(); i++)
	{
		int prev1 = max[i - 1];
		int prev2 = max[i - 2] + num[i - 1];
		max[i] = (prev1 > prev2)? prev1 : prev2;
	}
	return max[num.size()];
}




	
int main()
{
	
	
}