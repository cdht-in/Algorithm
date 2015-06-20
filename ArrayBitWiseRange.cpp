/*

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

*/

#include <vector>
#include <iostream>

using namespace std;

//naive appraoch
int BitWiseAnd(int m, int n)
{
	int result = m;	
	for(int i = m + 1; i <= n; i++)
	{
		result &= i;
	}
	
	return result;
}

//the result of a range bitwise is the common 'left header' of m and n.
int BitWiseAndI(int m, int n)
{
	int c = 0;
	
	//extract the common left header
	while(m != n)
	{
		m >>= 1;
		n >>= 1;
		c++;
	}
	
	//restore the common left header
	return n << c;
}

int main()
{
	int m = 1;
	int n = 8;
	cout << BitWiseAnd(m,n) << " " << (m & n & 7) << endl;
	
}