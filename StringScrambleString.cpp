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
*/

#include <string>
#include <iostream>

using namespace std;

/*
  bool isSrambleHelper (string& s1, string& s2, int begin, int end)
  {
  if (begin >= end) {
  if (s1 == s2)
  return true;
  return false;
  }
  int mid = (begin + end) / 2;
  //1. don't swap the left word
  //1.1 don't swap the right word
  if (isSrambleHelper (s1, s2, mid + 1, end) )
  return true;
  //1.2 swap the right word
  int tmpmid = (mid + 1 + end) / 2 + 1;
  string tmp = s1.substr(tmpmid,end - tmpmid);
  s1.erase(tmpmid,end - tmpmid);
  s1.insert(mid + 1,tmp);
  if (isSrambleHelper (s1, s2, begin, mid) )
  return true;

  //2 swap the left word
  tmpmid = (begin + mid) / 2;
  tmp = s1.substr(tmpmid,mid - tmpmid);
  s1.erase(tmpmid,mid - tmpmid);
  s1.insert(begin,tmp);
  if (isSrambleHelper (s1, s2, begin, mid))
  return true;
  return isSrambleHelper (s1, s2, mid + 1, mid);
  }


  bool isScramble (string s1, string s2)
  {
  return isSrambleHelper (s1, s2, 0, s1.size() );
  }
*/

/*
first implementation

bool isScramble (string s1, string s2)
{
  // Start typing your C/C++ solution below
  // DO NOT write int main() function

  if (s1 == s2)
    return true;
  int size = s1.size();
  int value1 = 0, value2 = 0;
  for (int i = 0; i < size; ++i) {
    value1 += (s1[i] - 'a');
    value2 += (s2[i] - 'a');
  }
  if (value1 != value2)
    return false;
  for (int i = 1; i < size; i++) {
    if (isScramble (s1.substr (0, i), s2.substr (0, i) ) && isScramble (s1.substr (i), s2.substr (i) ) )
      return true;
    if (isScramble (s1.substr (0, i), s2.substr (size - i) ) && isScramble (s1.substr (i), s2.substr (0, size - i) ) )
      return true;
  }
  return false;
}

*/

//second implementation

//简单的说，就是s1和s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22。
//那么要么s11和s21是scramble的并且s12和s22是scramble的；
//要么s11和s22是scramble的并且s12和s21是scramble的
bool isScramble (string s1, string s2)
{
	if(s1 == s2)
		return true;
	
	int size = s1.size();
	
	//this is one of the necessary condition for a scrambled string, and it cut down the recursion significantlly to pass the leetcode Time Limit Exceed
    int value1 = 0, value2 = 0;
    for (int i = 0; i < size; ++i) {
      value1 += (s1[i] - 'a');
      value2 += (s2[i] - 'a');
    }
    if (value1 != value2)
      return false;
	
	
	for(int i = 1; i < s1.size(); i++)
	{
		string s1Left = s1.substr(0, i);
		string s1Right = s1.substr(i);

		string s2Left = s2.substr(0, i);
		string s2Right = s2.substr(i);
		
		if(isScramble(s1Left,s2Left) && isScramble(s1Right,s2Right))
			return true;
		
		//if two parts are swapped => ab => ba
		if(isScramble(s1Left,s2.substr(size - i)) && isScramble(s1Right,s2.substr(0,size - i)))
			return true;
	}

	return false;
}








































//second implemenation

bool isScrambleI(string s1, string s2) {
	if(s1 == s2)
		return true;
	if(s1.size() != s2.size())
		return false;
	
	int n = s1.size();
	
    int value1 = 0, value2 = 0;
    for (int i = 0; i < n; ++i) {
      value1 += (s1[i] - 'a');
      value2 += (s2[i] - 'a');
    }
    if (value1 != value2)
      return false;
	
	for(int i = 1; i < n; i++)
	{
		if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
			return true;
		
		//example abc, bca, and ab, ba
		if(isScramble(s1.substr(0,i),s2.substr(n - i)) && isScramble(s1.substr(i),s2.substr(0,n - i)))
			return true;
	}
	return false;
}


int main()
{
  string s1 = "great";
  string s2 = "rgtae";
  cout << isScramble (s1, s2) << endl;
  
}
