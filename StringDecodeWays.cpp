/*
  A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Given an encoded message containing digits, determine the total number of ways to decode it.

  For example,
  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

  The number of ways decoding "12" is 2.
*/

#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

/*

first implementation

int check (char a)
{
  return (a == '0') ? 0 : 1;
}

int check (char a, char b)
{
  return (a == '1' || (a == '2' && b <= '6') ) ? 1 : 0;
}

int numDecodings (string s)
{
  if (s.empty() || s[0] == '0')
    return 0;
  if (s.size() == 1)
    return check (s[0]);
  int fn = 0, fn_1 = 0, fn_2 = 1;
  fn_1 = (check (s[0])  *  check (s[1]) ) + check (s[0], s[1]);
  for (int i = 2; i < s.size(); i++) {
    if (check (s[i]) ) fn += fn_1;
    if (check (s[i - 1], s[i]) ) fn += fn_2;
    if (fn == 0)
      return 0;
    fn_2 = fn_1;
    fn_1 = fn;
    fn = 0;
  }
  return fn_1;
}

int decode (char* message, size_t len)
{
  //# of ways to decode length n
  int ways[] = {1, 0};
  int i, w;
  for (i = 0; i < len; ++i) {
    w = 0;
    //if the second last digit is 1 or the it is 2 and the last one is less than 7, it is a valid decoding
    if ( (i > 0) && ( (message[i - 1] == '1') || (message[i - 1] == '2' && message[i] < '7') ) ) {
      w += ways[1];
    }
    if (message[i] > '0') {
      w += ways[0];
    }
    ways[1] = ways[0];
    ways[0] = w;
    //printf ("%d ways[0]:%d ways[1]:%d\n", i, ways[0], ways[1]);
  }
  return ways[0];
}
*/

//second implementation

bool CanDecode(string& s)
{
	string::size_type sz;   // alias of size_t
	int dec = std::stoi (s,&sz);
	if(10 <= dec && dec <= 26)
		return true;
	return false;
}

int numDecodings(string s) {
	if(s.size() == 0)
		return 0;
	
	//if there are leading zeros, can't decode
	if(s[0] == '0')
		return false;
	
	int n = s.size();
	int ways[n + 1];
	ways[0] = 1;
	ways[1] = 1;
	
	for(int i = 2; i <= n; i++){
		string substr = s.substr(i - 2,2);
		
		//minus 1 to get the index
		if(s[i - 1] != '0')
		{		
			if(CanDecode(substr) == false)
			{
				ways[i] = ways[i - 1];
			}
			else
			{
				ways[i] = ways[i - 1] + ways[i - 2];
			}
		}
		else
		{
			if(CanDecode(substr) == false)
			{
				return 0;
			}
			ways[i] = ways[i - 2];
		}
	}	
	return ways[n];
}

int main()
{
  char message[] = "10";
}
