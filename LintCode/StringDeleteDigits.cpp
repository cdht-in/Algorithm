/*

Medium Delete Digits

16% Accepted
Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer.

Find the smallest integer after remove k digits.

N <= 240 and k <= N,

Have you met this question in a real interview? Yes
Example
Given an integer A = "178542", k = 4

return a string "12"
	
*/

#include "../commonHeader.h"

string DeleteDigits(string A, int k) 
{
	//quick select the largest k numbers
	string s = A;
	for(int i = 0; i < k; i++)
	{
		//find the first decedent subarray from the left because cut from the left results in the most number shrinking
		int j = 0;
		while(j < s.size() - 1 && s[j] <= s[j + 1])
		{
			j++;
		}

		s.erase(j,1);
	}
	
	int i = 0;
	while(i < s.size() && s[i] == '0')
	{
		i++;
	}
	
	return s.substr(i);
}

int main()
{
	string A = "178542";
	int k = 4;
	cout << DeleteDigits(A,k) << endl;
}