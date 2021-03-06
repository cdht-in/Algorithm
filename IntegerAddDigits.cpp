/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?Show More Hint 
	
*/

#include "./commonHeader.h"

//log(n) in time
int addDigits(int num) 
{
	while(num >= 10)
	{
		int sum = 0;
		while(num)
		{
			sum += (num % 10);
			num /= 10;
		}
		
		num = sum;
	}
	
	return num;
}

//https://en.wikipedia.org/wiki/Digital_root
int addDigitsI(int num) 
{
	return num - 9 * ((num - 1) / 9);
}

int main()
{
	
}