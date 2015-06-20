/*
  find the longest palindromic substr
*/

/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
*/

#include <string>
#include <iostream>

using namespace std;


//O(n^2) in time
string longestPalindrome (string s)
{
  if (s.size() < 0)
    return string ("");
  //interleaved with imaginary #
  int n = s.size() * 2 + 1;
  int longest = 0;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      int len = 1;
      int j = i - 2;
      int k = i + 2;
      while (j >= 0 && k < n && s[ (j - 1) / 2] == s[ (k - 1) / 2]) {
        len += 2;
        j = j - 2;;
        k = k + 2;
      }
      if (len > longest) {
        longest = len;
        index = (i - 1) / 2;
      }
    }
    else {
      int len = 0;
      int j = i - 1;
      int k = i + 1;
      while (j >= 0 && k < n && s[ (j - 1) / 2] == s[ (k - 1) / 2]) {
        len += 2;
        j -= 2;
        k += 2;
      }
      if (len > longest) {
        longest = len;
        index = (i + 1) / 2;
      }
    }
  }
  cout << "indext at " << index << " " << longest << endl;
  return s.substr (index - longest / 2, longest);
}


string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) 
  {
    l--;
    r++;
  }
  return s.substr(l + 1, r - l - 1);
}

/*
	second implementation, O(n^2), expand from the center

We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.

You might be asking why there are 2N-1 but not N centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as “abba”) and its center are between the two ‘b’s.

N numbers + N - 1 gaps

*/

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";
    string longest = s.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n - 1; i++) 
	{
	  //odd palindrome
      string p1 = expandAroundCenter(s, i, i);
      if (p1.length() > longest.length())
        longest = p1;
 	 	
	  //even palindrome
      string p2 = expandAroundCenter(s, i, i+1);
      if (p2.length() > longest.length())
        longest = p2;
    }
    return longest;       
}

//linear approach
//http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html


int main()
{
  char s[] = "bb";
  cout << longestPalindrome (s) << endl;
}

/*
void LongestPalindome (char* s, int size)
{
  //populate N + N - 1 centers
  int size1 = 2 * size + 1;
  char* s1 = (char*) malloc (size1);
  int i = 0;
  int j = 0;
  for (; i < size1; i++) {
    if ( (i & 0x01) == 0x01)
      s1[i] = s[j++];
    else
      s1[i] = '#';
  }
  s1[i] = '\0';
  i = 0;
  for (; i < size1; i++ ) {
    printf ("%c ", s1[i]);
  }
  printf ("\n");
  imum length of S is 1000, and there exists one unique longest palindromic substring.

    Discuss
    //print all palindromes
  int k;
  int count = 0;
  for (i = 0; i < size1; i++ ) {
    k = 1;
    while (i - k >= 0 && i + k < size1) {
      if (s1[i - k] == s1[i + k] && s1[i - k] != '#') {
        count++;
      }
      k++;
    }
  }
  printf ("%d\n", count + size);
  free (s1);
}

int min (int a, int b)
{
  return (a < b) ? a : b;
}

void foo (char* s)
{
  //Input and transform to s
  int p[1000], mx = 0, id = 0;
  memset (p, 0, sizeof (p) );
  int i;
  for (i = 1; s[i] != '\0'; i++) {
    p[i] = mx > i ? min (p[2 * id - i], mx - i) : 1;
    while (s[i + p[i]] == s[i - p[i]]) p[i]++;
    if (i + p[i] > mx) {
      mx = i + p[i];
      id = i;
    }
  }
  //find the max P[i]
  printf ("%d\n", mx);
}

*/

