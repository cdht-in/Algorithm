/*
	
Easy Reverse Words in a String

23% Accepted
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Have you met this question in a real interview? Yes
Example
Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
	
*/

#include "../commonHeader.h"

void Swap(string& s, int l, int r)
{
	for(int i = 0; i < (r - l + 1) / 2; i++)
	{
		char tmp = s[l + i];
		s[l + i] = s[r - i];
		s[r - i] = tmp;
	}
}

string reverseWords(string s)
{
	//remove the leading and trailing white spaces
	int l = 0, r = s.size() - 1;
	while(l < s.size() && s[l] == ' ')
	{
		l++;
	}
	
	while(r >= 0 && s[r] == ' ')
	{
		r--;
	}
	
	//trim the in-between spaces
	string newS = "";
	bool flag = true;
	for(int i = l; i <= r; i++)
	{
		if(s[i] != ' ')
		{
			newS += s[i];
			flag = true;
		}
		else
		{
			if(flag)
			{
				newS += s[i];
				flag = false;
			}
		}
	}
	
	l = 0, r = 0;
	
	while(r < newS.size())
	{
		while(r < newS.size() && newS[r] != ' ')
		{
			r++;
		}
		
		//a word
		Swap(newS,l,r - 1);
		
		r++;
		l = r;
	}
	
	Swap(newS,0,newS.size() - 1);
	
	return newS;
}

int main()
{
	string s = "  hello          world!!  ";
	cout << reverseWords(s) << endl;
}