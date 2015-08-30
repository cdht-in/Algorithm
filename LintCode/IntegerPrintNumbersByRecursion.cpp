/*
	
Print numbers from 1 to the largest number with N digits by recursion.

Have you met this question in a real interview? Yes
Example
Given N = 1, return [1,2,3,4,5,6,7,8,9].

Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].

Note
It's pretty easy to do recursion like:

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?

Challenge
Do it in recursion, not for-loop.
	
*/

#include "../commonHeader.h"

void numbersByRecursionHelper(vector<int>& result,int power,int digit)
{
	int min = pow(10,power - 1);
	int max = pow(10,power);
	
	for(int i = min; i < max; i++)
	{
		result.push_back(i);
	}
	
	if(power == digit)
	{
		return;
	}	
	
	numbersByRecursionHelper(result,power + 1, digit);
}

vector<int> numbersByRecursion(int n)
{
	vector<int> result;
	if(n == 0)
		return result;
	numbersByRecursionHelper(result,1,n);
	return result;
}

int main()
{
	vector<int> result = numbersByRecursion(3);
	for(auto i : result)
	{
		cout << i << endl;
	}
}