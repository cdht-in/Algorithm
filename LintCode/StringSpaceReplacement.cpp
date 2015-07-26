/*
	
Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.

Have you met this question in a real interview? Yes
Example
Given "Mr John Smith", length = 13.

The string after replacement should be "Mr%20John%20Smith".

Note
If you are using Java or Python，please use characters array instead of string.

Challenge
Do it in-place.

*/

#include "commonHeader.h"

int replaceBlank(char*& string, int length) 
{
	int newLength = length * 3;
	int p = newLength - 1;
	
	for(int i = length - 1; i >= 0; i--)
	{
		if(string[i] != ' ')
		{
			string[p--] = string[i];
		}
		else
		{
			string[p--] = '0';
			string[p--] = '2';
			string[p--] = '%';
		}
	}
	
	p++;
	string += p;
	return newLength - p;
}

int main()
{
	char s[] = "hello world";
	int len = strlen(s);
	
	char* s1 = new char[len * 3];
	char* tmp = s1;
	strcpy(s1,s);
	
	int newLen = replaceBlank(tmp,len);
	for(int i = 0; i < newLen; i++)
	{
		cout << tmp[i];
	}
	cout << endl;
	
	delete[] s1;
}