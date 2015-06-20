/*
  Given two numbers represented as strings, return multiplication of the numbers as a string.

  Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <string>
#include <iostream>


using namespace std;

int ToInt(char c)
{
	return c - '0';
}

char ToChar(int i)
{
	return '0' + i;
}

string multiply(string num1, string num2) {
	
	if(num1.size() < num2.size())
	{
		string tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	
	string product(num1.size() + num2.size(),'0');
	//num2 is always with less digits
	
	
	//simulate multiplication
	for(int i = num2.size() - 1; i >= 0; i--)
	{
		int carry = 0;
		for(int j = num1.size() - 1; j >= 0; j--)
		{
			int lastDigit1 = ToInt(num1[j]);
			
			int lastDigit2 = ToInt(num2[i]);
		
			int subProduct = lastDigit1 * lastDigit2 + carry;
			
			int newCarry = (ToInt(product[i + j + 1]) + subProduct) / 10;
		
			product[i + j + 1] = ToChar((ToInt(product[i + j + 1]) + subProduct)  % 10);
			
			carry = newCarry;
		}
		
		if(carry != 0)
		{
			product[i] = ToChar(carry);
		}
	}
	
	int i = 0;
	for(; i < product.size() && product[i] == '0'; i++);
	if(i < product.size())
		return product.substr(i);
	return "0";
}

int main(){
	cout << multiply("9133","0") << endl;
}
