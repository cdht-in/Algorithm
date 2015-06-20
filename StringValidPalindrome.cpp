/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.

  Note:
  Have you consider that the string might be empty? This is a good question to ask during an interview.
  For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool Palindromic(char* a, int s){
  int mid = s / 2;
  for(int i = 0; i < mid; i++){
    if(a[i] != a[s - i - 1])
      return false;
  }
  return true;
}

//A man, a plan, a canal: Panama
bool PalindromicWithPunc(const char* a, int s){
  if(s < 1)
    return true;
  int i = 0;
  int j = s;
  while(i <= j){
    while(ispunct(a[i]) || a[i] == ' ')
      i++;
    while(ispunct(a[j]) || a[j] == ' ')
      j--;
    if(i > j)
      break;
    if(tolower(a[i]) != tolower(a[j]))
      return false;
    i++;
    j--;
  }
  return true;
}

/*

bool isPalindrome(string a) {
  if(a.size() < 1)
    return true;
  int i = 0;
  int j = a.size() - 1;
  while(i <= j){
    while(ispunct(a[i]) || a[i] == ' ')
      i++;
    while(ispunct(a[j]) || a[j] == ' ')
      j--;
    if(tolower(a[i]) != tolower(a[j]))
      return false;
    i++;
    j--;
  }
  return true;
}
*/

//check if any integer is palindromic, mod 10 to get each number then reverse the interger to see if they are equal
bool PalindromicInt(int a){
  int n = a;
  int rev = 0;
  while(n > 0)
    {
      rev = rev * 10 + n % 10;
      n /= 10;
    }
  if(a == rev)
    return true;
  return false;
}

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
	
*/

inline bool IsAlphaNumeric(char c){
	int n = (int)c;
	if(('0' <= n && n <= '9') || ('A' <= n && n <= 'Z') || ('a' <= n && n <= 'z'))
		return true;
	return false;
}

inline char ToLower(char c)
{
	int n = (int)c;
	if('0' <= n && n <= '9'){
		return c;
	}
	if('a' <= n && n <= 'z')
	{
		return c;
	}
	return (char)(c + 32);
}


bool isPalindrome(string s) {
	if(s.size() == 0)
		return true;
	int l = 0;
	int r = s.size() - 1;
	
	while(l <= r)
	{
		while(l <= r && IsAlphaNumeric(s[l]) == false)
		{
			l++;
		}
		if(l > r)
			break;
		
		while(l <= r && IsAlphaNumeric(s[r]) == false)
		{
			r--;
		}
		if(l > r)
			break;
		
		char lChar = ToLower(s[l]);
		char rChar = ToLower(s[r]);
		if(lChar != rChar)
			return false;
		l++;
		r--;
	}
	return true;
}

int main(){
	string s = "a.";
	cout << isPalindrome(s) << endl;
  //int bar = 1221;
  //printf("%d\n",PalindromicInt1(bar));
}

