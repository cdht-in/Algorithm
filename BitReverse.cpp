#include <iostream>

using namespace std;

/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
	
*/

uint32_t reverseBits(uint32_t n) {
	int nshift = 31;
	unsigned int mask = 0x80000000;
	unsigned int result = 0;
	for(int i = 0 ; i <= nshift; i++)
	{
		unsigned int bit = (mask & n) >> nshift;
		result = result | (bit << i);
		n <<= 1;		
	}
	return result;
}

int main(){
	unsigned int n = 1;
	n = reverseBits(n);
	cout << "result " << n << endl;
	
}