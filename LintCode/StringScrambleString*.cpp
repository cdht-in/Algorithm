/*
	
	
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Have you met this question in a real interview? Yes
Example
Challenge
O(n3) time
	
*/

#include "../commonHeader.h"


//naive approach
bool isScrambleHelper(string s1,string s2)
{
	if(s1.size() != s2.size())
		return false;
	if(s1 == s2)
		return true;
	int sum1 = 0;
	int sum2 = 0;
	for(int i = 0; i < s1.size(); i++)
	{
		sum1 += s1[i] - 'a';
		sum2 += s2[i] - 'a';
	}
	if(sum1 != sum2)
		return false;
	
	for(int i = 1; i < s1.size(); i++)
	{
		if(isScrambleHelper(s1.substr(0,i),s2.substr(0,i)) && isScrambleHelper(s1.substr(i),s2.substr(i)))
			return true;
		
		if(isScrambleHelper(s1.substr(0,i),s2.substr(s1.size() - i)) && isScrambleHelper(s1.substr(i),s2.substr(0, s1.size() - i)))
			return true;
	}
	
	return false;
}

bool isScramble(string& s1, string& s2) 
{
	return isScrambleHelper(s1,s2);
}

//http://www.cnblogs.com/lishiblog/p/4117859.html

int main()
{
	string s1 = "great";
	string s2 = "rgtae";
	cout << isScramble(s1,s2) << endl;
}