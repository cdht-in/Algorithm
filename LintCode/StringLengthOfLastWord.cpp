/*
	
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Have you met this question in a real interview? Yes
Example
Given s = "Hello World", return 5.

Note
A word is defined as a character sequence consists of non-space characters only.
	
*/

#include "..commonHeader.h"

int lengthOfLastWord(string& s) 
{
	int p = s.size() - 1;
	while(p >= 0 && s[p] == ' ')
	{
		p--;
	}	
	
	int end = p;
	while(p >= 0 && s[p] != ' ')
	{
		p--;
	}
	
	return end - p;
}

int main()
{
	
}