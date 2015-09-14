/*
Medium Gray Code

35% Accepted
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, find the sequence of gray code. A gray code sequence must begin with 0 and with cover all 2n integers.

Have you met this question in a real interview? Yes
Example
Given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note
For a given n, a gray code sequence is not uniquely defined.

[0,2,3,1] is also a valid gray code sequence according to the above definition.

Challenge
O(2n) time.

*/

#include "../commonHeader.h"

//this is correct
vector<int> grayCode(int n) 
{
	/*
	
	when n == 3, it generates:
	000 
	001 
	011 
	111
	101 
	100 
	110 
	010
	
	*/
	vector<int> ret;
	ret.push_back(0);
	int num = 1 << n;
	unsigned int mask = 0x01;
	int c = 0;
	bool shift = true;
	for(int i = 0; i < num - 1; i++)
	{
		ret.push_back(ret.back() ^ mask);
		c++;
		if(shift)
		{
			mask <<= 1;
		}
		else
		{
			mask >>= 1;
		}
		if(c == (n - 1))
		{
			c = 0;
			shift = !shift;
		}
	}
	return ret;
}

int main()
{
	int n = 3;
	vector<int> ret = grayCode(n);
	for(auto i : ret)
	{
		cout << i << " ";
	}
	cout << endl;
}