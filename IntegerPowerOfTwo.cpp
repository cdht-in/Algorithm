/*
	
Given an integer, write a function to determine if it is a power of two.

*/
#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) 
{
	if(n < 1)
		return false;
	
	return (n & (n - 1)) == 0;
}

int main()
{
	cout << isPowerOfTwo(2) << endl;
}