/*
	
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

*/

#include <string>
#include <climits>
#include <iostream>


using namespace std;

int CharToInt(char c)
{
	if(c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return 0; 
}

int atoi(string str) {
	if(str.size() == 0)
		return 0;
	
	bool pos = true;
	
	int i = 0;
	for(; i < str.size(); i++)
	{
		if(str[i] != ' ')
			break;
	}
	
	if(str[i] == '-')
	{
		pos = false;
		i++;
	}
	else if(str[i] == '+')
	{
		i++;
	}
	
	int result = 0;
	for(int j = i; j < str.size(); j++)
	{
		if('0' <= str[j] && str[j] <= '9')
		{
			//check for integer overflow
			if(result > INT_MAX / 10)
			{
				if(pos == false)
					return INT_MIN;
				return INT_MAX;
			}
			
			result *= 10;
			
			if(result > INT_MAX - CharToInt(str[j]))
			{
				if(pos == false)
					return INT_MIN;
				return INT_MAX;
			}
				
			result += CharToInt(str[j]);
		}
		else
			break;
	}
	if(pos == false)
		result = -result;
	return result;
}

int main()
{
	cout << atoi("+-2") << endl;
	
}