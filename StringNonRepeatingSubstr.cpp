/*
  Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring (string s)
{
  int map[26];
  for (int i = 0; i < 26; i++) {
    map[i] = -1;
  }
  int max = 0;
  int i,j = 0;
  int e = 0;
  int b = 0;
  for (i = 0; i < s.size(); i++) {
    //seen before
    if (map[s[i] - 'a'] != -1) {
      //NOTE: the skipping has to skip them all
      if(map[s[i] - 'a'] >= j)
	j = map[s[i] - 'a'] + 1;
      map[s[i] - 'a'] = i;
    }
    else {
      map[s[i] - 'a'] = i;
    }
    if (i - j + 1 > max) {
      /*
	//record the beginning and end of the substr
	e = i;
        b = j;
      */
      max = i - j + 1;
    }
  }
  /*
  cout << "b at " << b << " " << e << endl;
  for (int i = b; i <= e; i++) {
    cout << s[i];
  }
  cout << endl;
  */
  return max;
}

int main()
{
  string s1 = "abcabcbb";
  string s2 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
  string s3 = "msboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuu";
  string s4 = "ctclemwwlexnkvwizzoyctqlnzxoetyioavsorrbvoqflpqlqgluzdgoefckaatpdohtgaxdqnlceb";
  cout << lengthOfLongestSubstring (s3) << endl;
}
