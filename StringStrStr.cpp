/*
  Question: Substring Write a program to determine whether an input string x is a substring of another input string y.  (For example, "bat" is a substring of "abate", but not of "beat".)  You may use any language you like.

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//to test if str2 is a substring of str1 method 1
int FindSubstring1 (char* str1, char* str2)
{
  //first test if they are empty string
  if (str1[0] == '\0' && str2[0] == '\0')
    return 1;
  //compare each char 1 by 1
  int i, j;
  for (i = 0, j = 0; * (str1 + i) != '\0';) {
    if (* (str1 + i) != * (str2 + j) ) {
      i++;
      j = 0;
    }
    else {
      i++;
      j++;
      //str2 is a substring of str1
      if (* (str2 + j) == '\0')
        return 1;
    }
  }
  return 0;
}

//standard method O(n^2)
int hasSubstring (const char* str, const char* find)
{
  if (str[0] == '\0' && find[0] == '\0')
    return 0;
  if (str[0] == '\0')
    return 0;
  if (find[0] == '\0')
    return 0;
  
  int i, j;
  for (i = 0; str[i] != '\0'; i++) 
  {
    int foundNonMatch = 0;
    for (j = 0; find[j] != '\0'; j++) 
	{
      if (str[i + j] != find[j]) 
	  {
        foundNonMatch = 1;
        break;
      }
    }
    if (!foundNonMatch)
      //return the starting index
      return i;
  }
  return 0;
}

//outer loop N - M + 1 times * M
const char* StrStr (const char* haystack, const char* needle)
{
  if (*needle == '\0')
    return haystack;
  const char* p1 = haystack;
  const char* p2 = needle;
  const char* p3 = p1;
  while (*++p2 != '\0') {
    p3++;
  }
  //make sure the rest loops N - M + 1 times
  while (*p3 != '\0') {
    const char* b = p1;
    p2 = needle;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    //found the substring
    if (*p2 == '\0')
      return b;
    p1 = b + 1;;
    p3++;
  }
  return 0;
}


char* my_strstr (char* str, char* sub)
{
  //if sub is null, return str
  if (*sub == '\0')
    return str;
  char* p1 = str;
  char* p2 = sub;
  char* p3 = p1;
  //the sub can't start at the position len(str) - len(sub) + 1, skip those
  while (*++p2 != '\0') {
    p3++;
  }
  while (*p3 != '\0') {
    char* tmp = p1;
    p2 = sub;
    //compare them one by one
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    //found the substring
    if (*p2 == '\0')
      return tmp;
    //else move to the next location in the str
    p1 = tmp + 1;;
    p3++;
  }
  //not in the str
  return 0;
}


//naive O(n^2) algorithm

int strStr(char *haystack, char *needle) {
	
	if(haystack[0] == '\0' && needle[0] == '\0')
		return 0;
	
	for(int i = 0; haystack[i] != '\0'; i++)
	{
		for(int j = 0;;j++)
		{
			//this would return the last index
			if(haystack[i + j] == '\0' && needle[j] == '\0')
			{
				return i;
			}
			
			if(haystack[i + j] != needle[j])
			{
				break;
			}
		}
		
	}
	return -1;
}

//linear KMP algorithm will be added
//http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

void computeLPSArray(const string& t, vector<int>& longestProperPrefix)
{
	longestProperPrefix[0] = 0; // longestProperPrefix[0] is always 0
    int len = 0;  // lenght of the previous longest prefix suffix
    
	// the loop calculates longestProperPrefix[i] for i = 1 to t.size() - 1
    for (int i = 1; i < t.size(); )
    {
       if (t[i] == t[len])
       {
         len++;
         longestProperPrefix[i] = len;
         i++;
       }
       else // (t[i] != t[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = longestProperPrefix[len - 1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           longestProperPrefix[i] = 0;
           i++;
         }
       }
	   
	   //print the longestProperPrefix after each iteration
	   for(int j = 0; j < t.size(); j++)
		   cout << longestProperPrefix[j] << " ";
	   cout << endl;
    }
}

//O(m + n) KMP Param: Text , Pattern
void KMP(const string& s, const string& t) 
{
	// create longestProperPrefix[] that will hold the longest prefix suffix values for pattern
	vector<int> longestProperPrefix(t.size(),0);
	
	// Preprocess the pattern (calculate longestProperPrefix[] array)
	computeLPSArray(t, longestProperPrefix);
 
	for (int i = 0, j = 0; i < s.size(); )
	{
	  if(s[i] == t[j])
	  {
		i++;
	    j++;
	  }
 
	  if (j == t.size())
	  {
	    printf("Found pattern at index %d \n", i - j);
	    j = longestProperPrefix[j - 1];
	  }
	  // mismatch after j matches
	  else if (i < s.size() && s[i] != t[j])
	  {
	    // Do not match longestProperPrefix[0..longestProperPrefix[j-1]] characters,
	    // they will match anyway
	    if (j != 0)
		{
	     	j = longestProperPrefix[j - 1];
	 	}
	    else
		{
			i++;
		}
	  }
	}
}

int main()
{
  string text = "aabbaaa";
  string pattern = "aa";
  KMP(text, pattern);
  
}
