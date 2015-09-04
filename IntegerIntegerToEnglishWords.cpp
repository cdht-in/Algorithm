/*
	
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
	
*/

#include "./commonHeader.h"

unordered_map<int,string> digitMap({{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},{50,"Fifty"},{60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"}});

vector<string> carry({"","Thousand","Million","Billion"});

string hundred(int num)
{
	string s = "";
	
	if(num == 0)
		return s;
	
	if(num < 100)
	{
		int dividend = 10;
		if(digitMap.find(num) == digitMap.end())
		{
			s += digitMap[num - num % dividend] + " ";
			s += digitMap[num % dividend];
		}
		else
		{
			s += digitMap[num];
		}
		return s;
	}
	
	int dividend = 100;
	for(int i = 0; i < 2 && num; i++)
	{
		int digit = num / dividend;
		if(i == 0)
		{
			s += digitMap[digit] + " Hundred";
		}
		else
		{
			if(digitMap.find(num) == digitMap.end())
			{
				s += " " + digitMap[num - num % dividend];
				s += " " + digitMap[num % dividend];
			}
			else
			{
				s += " " + digitMap[num];
			}
		}
		num %= dividend;
		dividend /= 10;
	}
	return s;
}

string numberToWords(int num) 
{
	if(num == 0)
		return "Zero";
	string s = "";
	
	int p = 0;
	while(num)
	{
		int number = 0;
		int remainder = 0;
		for(int i = 0; i < 3 && num; i++)
		{
			remainder = num % 10;
			num /= 10;
			number += remainder * pow(10,i);
		}
		
		string tmp = hundred(number);
		
		if(tmp != "")
			s.insert(0,tmp + " " + carry[p] + " ");
		p++;
	}
	
	int i = s.size() - 1;
	while(i >= 0 && s[i] == ' ')
		i--;
	return s.substr(0,i + 1);
}

int main()
{
	cout << numberToWords(123) << endl;
}