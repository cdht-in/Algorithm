/*
  Given a number represented as an array of digits, plus one to the number.

*/
#include <stdio.h>
#include <vector>

using namespace std;


/*

first implementation

void PlusOne (int* number, int len)
{
  int i = len - 1;
  if (number[i] + 1 <= 9) {
    number[i] += 1;
    return;
  }
  number[i] = number[i] + 1 - 10;
  int carry = 1;
  i--;
  while (i >= 0) {
    if (number[i] + carry > 9) {
      number[i] = number[i] + carry - 10;
      i--;
    }
    else {
      number[i] = number[i] + carry;
      return;
    }
  }
}


Given a non-negative number represented as an array of digits, plus one to the number.
  The digits are stored such that the most significant digit is at the head of the list.

vector<int> plusOne (vector<int>& digits)
{
  if (digits.size() < 1) {
    digits.push_back (1);
    return digits;
  }
  int i = digits.size() - 1;
  if(digits[i] + 1 < 10)
    {
      digits[i] += 1;
      return digits;
    }
  int carry = 1;
  digits[i] = digits[i] + carry - 10;
  i--;
  for(; i >= 0 && carry; i--){
    if(digits[i] + carry >= 10){
      digits[i] = digits[i] + carry - 10;
    }
    else{
      digits[i] = digits[i] + carry;
      carry = 0;
    }
  }
  if(carry)
    digits.insert(digits.begin(),carry);
  return digits;
}

*/

//second implementation

vector<int> plusOne(vector<int> &digits) {
	vector<int> result(digits.size(),0);
	vector<int> ones(digits.size(),0);
	ones[digits.size() - 1] = 1;
	int carry = 0;
	for(int i = digits.size() - 1; i >= 0; i--)
	{
		int digit = digits[i] + ones[i] + carry;
		if(digit <= 9)
		{
			result[i] = digit;
			carry = 0;
		}
		else
		{
			result[i] = digit % 10;
			carry = 1;
		}	
	}
	if(carry == 1)
		result.insert(result.begin(),1);
	return result;
}



int main()
{
  int foo[] = {1, 9, 9};
  int size = sizeof (foo) / sizeof (int);
  PlusOne (foo, size);
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", foo[i]);
  printf ("\n");
}

