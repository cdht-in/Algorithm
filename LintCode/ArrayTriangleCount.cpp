/*
	
Hard Triangle Count

30% Accepted
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

Have you met this question in a real interview? Yes
Example
Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]
Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
	
*/

#include "../commonHeader.h"

//brute force
int triangleCount(vector<int> &S) 
{
	int c = 0;
	for(int i = 0; i < S.size(); i++)
	{
		for(int j = i + 1; j < S.size(); j++)
		{
			for(int k = j + 1; k < S.size(); k++)
			{
				if((S[i] + S[j] > S[k]) && (S[i] + S[k] > S[j]) && (S[j] + S[k] > S[i]))
					c++;
			}
		}
	}
	return c;
}

//O(n^2)
int triangleCountI(vector<int> &S)
{
	int c = 0;
	sort(S.begin(),S.end());
	int big = S.size() - 1;
	while(big >= 2)
	{
		int small = 0, middle = big - 1;
		while(small < middle)
		{
			if(S[small] + S[middle] <= S[big])
			{
				small++;
			}
			else
			{
				c += middle - small;
				middle--;
			}
		}
		big--;
	}
	
	return c;
}	 

int main()
{
	vector<int> foo = {4,4,4,4};
	//cout << triangleCount(foo) << endl;
	cout << triangleCountI(foo) << endl;
}