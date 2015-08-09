/*
	
Medium Sort Letters by Case

38% Accepted
Given a string which contains only letters. Sort it by lower case first and upper case second.

Have you met this question in a real interview? Yes
Example
For "abAcD", a reasonable answer is "acbAD"

Note
It's not necessary to keep the original order of lower-case letters and upper case letters.

Challenge
Do it in one-pass and in-place.

*/

#include "../commonHeader.h"

void sortLetters(string &letters) 
{
	int l = 0, r = letters.size() - 1;
	while(l <= r)
	{
		if(isupper(letters[l]) == false)
		{
			l++;
		}
		else
		{
			char tmp = letters[r];
			letters[r] = letters[l];
			letters[l] = tmp;
			r--;
		}
	}
}

int main()
{
	
}