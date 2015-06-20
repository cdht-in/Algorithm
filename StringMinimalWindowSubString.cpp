/*
  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

  For example,
  S = "ADOBECODEBANC"
  T = "ABC"
  Minimum window is "BANC".

  Note:
  If there is no such window in S that covers all characters in T, return the emtpy string "".

  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <climits>

using namespace std;


/*

first implementation

int MinWindow (const char* S, const char* T)
{
  unsigned char hasfound[256] = {0};
  unsigned char needfound[256] = {0};
  int i, j, c = 0, len = 0, min = 9999;
  for (i = 0; T[i] != '\0'; i++) {
    len++;
    needfound[T[i]]++;
  }
  for (i = 0, j = 0; S[j] != '\0'; j++) {
    if (needfound[S[j]]) {
      hasfound[S[j]]++;
      if (hasfound[S[j]] <= needfound[S[j]])
        c++;
      if (c == len) {
        //move the left end of the window
        while (needfound[S[i]] == 0 ||
               hasfound[S[i]] > needfound[S[i]]) {
          if (hasfound[S[i]] > needfound[S[i]])
            hasfound[S[i]]--;
          i++;
        }
        min = (min <= (j - i + 1) ) ? min : j - i + 1;;
      }
    }
  }
  return min;
}

string minWindow (string S, string T)
{
  if (S.size() < 1 || T.size() < 1 || (S.size() < T.size() ) )
    return "";
  char needfound[255] = {0};
  char hasfound[255] = {0};
  for (int i = 0; i < T.size(); i++)
    needfound[T[i]]++;
  int min = 9999;
  int begin = -1;
  int l = 0, r = 0, c = 0;
  for (; r < S.size(); r++) {
    if (needfound[S[r]]) {
      hasfound[S[r]]++;
      if (hasfound[S[r]] <= needfound[S[r]])
        c++;
    }
    if (c == T.size() ) {
      //move the left end of the window
      while (needfound[S[l]] == 0 ||
             hasfound[S[l]] > needfound[S[l]]) {
        //if (hasfound[S[l]] > needfound[S[l]])
        hasfound[S[l]]--;
        l++;
      }
      if (min > (r - l + 1) ) {
        min = r - l + 1;
        begin = l;
      }
    }
  }
  if (begin >= 0)
    return S.substr (begin, min);
  return string ("");
}

*/


/*
//leetcode accepted version for some reason
string minWindow(string S, string T) {

  if(S.size() == 0) return "";
  if(S.size() < T.size()) return "";
  int appearCount[256];
  int expectCount[256];
  memset(appearCount, 0, 256*sizeof(appearCount[0]));
  memset(expectCount, 0, 256*sizeof(appearCount[0]));
  for(int i =0; i < T.size(); i++)
    {
      expectCount[T[i]]++;
    }
  int minV = INT_MAX, min_start = 0;
  int wid_start=0;
  int appeared = 0;
  for(int wid_end = 0; wid_end< S.size(); wid_end++)
    {
      if(expectCount[S[wid_end]] > 0)// this char is a part of T
	{
	  appearCount[S[wid_end]]++;
	  if(appearCount[S[wid_end]] <= expectCount[S[wid_end]])
	    appeared ++;
	}
      if(appeared == T.size())
	{
	  while(appearCount[S[wid_start]] > expectCount[S[wid_start]]
		|| expectCount[S[wid_start]] == 0)
	    {
	      appearCount[S[wid_start]]--;
	      wid_start ++;
	    }
	  if(minV > (wid_end - wid_start +1))
	    {
	      minV = wid_end - wid_start +1;
	      min_start = wid_start;
	    }
	}
    }
  if(minV == INT_MAX) return "";
  return S.substr(min_start, minV);
}
*/

string minWindow(string S, string T) {
	string minWindow = "";
	if(S.size() < T.size())
		return minWindow;
	map<char,int> toBeFound;
	for(int i = 0; i < T.size(); i++)
	{
		if(toBeFound.find(T[i]) == toBeFound.end())
			toBeFound[T[i]] = 1;
		else
			toBeFound[T[i]]++;
	}
	
	int r = 0;
	int l = 0;
	int nFound = 0;
	int winSize = INT_MAX;
	int winStart = -1;
	while(r < S.size())
	{
		if(toBeFound.find(S[r]) != toBeFound.end())
		{
			toBeFound[S[r]]--;
			if(toBeFound[S[r]] >= 0)
				nFound++;
			
			//found all in T
			while(nFound == T.size())
			{
				int len = r - l + 1;
			
				if(winSize > len)
				{
					winSize = len;
					winStart = l;
				} 
			
				//now move the left boundary and maintain the window that contains all chars in T
				if(toBeFound.find(S[l]) != toBeFound.end())
				{
					toBeFound[S[l]]++;
					if(toBeFound[S[l]] > 0)
							nFound--;
				}
				l++;
			}
		}
		r++;
	}
	if(winStart != -1)
	{
		minWindow = S.substr(winStart,winSize);;
	}
	return minWindow;

}

int main()
{
  string S = "ADOBECODEBANC";
  string T = "ABC";
  cout << minWindow (S, T) << endl;
}
