/*
	
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/


#include <iostream>
#include <vector>

using namespace std;


int hammingWeight(uint32_t n) {

	int c = 0;
	while(n > 0)
	{
		n &= n - 1;
		c++;
	}
	return c;
}


int main(){
	
	cout << hammingWeight(11) << endl;
	
}