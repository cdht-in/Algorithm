/*
  The gray code is a binary numeral system where two successive values differ in only one bit.

  Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

  For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

  00 - 0
  01 - 1
  11 - 3
  10 - 2
  Note:
  For a given n, a gray code sequence is not uniquely defined.

  For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

  For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include <vector>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

void GrayCode (vector<int>& container, int n)
{
  int count = 0x01 << n;
  //2^n numbers
  for (int i = 0 ; i < count; ++i) {
    //XOR
    container.push_back ( (i >> 1) ^ i);
  }
}

vector<int> grayCode(int n) {
  vector<int> container;
  int count = 0x01 << n;
  //2^n numbers
  for (int i = 0 ; i < count; ++i) 
  {
    //toggle with XOR
    container.push_back ( (i >> 1) ^ i);
  }
  return container;
}



int ConvertSeqToNumber(vector<int>& seq)
{
	int n = 0;
	for(int i = 0; i < seq.size(); i++)
	{
		n += seq[i] * pow(2,(seq.size() - 1) - i);
	}
	return n;
}

//second implementation, this is correct, but leetcode would only accept one sequence
vector<int> grayCodeI(int n) 
{
	vector<int> seq(n,0);
	
	//there are 2 * n different graycode
	int num = pow(2,n);
	
	vector<int> result;
	
	result.push_back(0);
	
	int p = seq.size() - 1;
	int digit = 1;
	int j = 0;
	
	for(int i = 1; i < num; i++)
	{
		seq[p--] = digit;
		
		/*
		for (int i = 0; i < seq.size(); i++) 
		{
	    	cout << seq[i] << " ";
	  	}
		cout << endl;
		*/
		
		result.push_back(ConvertSeqToNumber(seq));
		
		//wrap around, cut off duplicates
		if(p < j)
		{
			p = seq.size() - 1;
			//toggle between 0 and 1
			digit = abs(digit - 1);
			j++;
		}	
	}
	
	return result;
}


int main()
{
	vector<int> foo = grayCode (3);
	
	cout << endl;
	for (int i = 0; i < foo.size(); i++) 
	{
    	cout << foo[i] << endl;
  	}
	
}
