
// find all rotation symmetric numbers less than N digits,  16891 -> 16891, 

#include <vector>
#include <iostream>
#include <string>

using namespace std;

char minc = '0', maxc = '9';

void nextpalindrome(string &s)
{
  int len = s.length();
  for (int n = (len + 1) / 2; n > 0; n--) 
  {
    if (s[n - 1] < maxc) 
	{	
		s[n - 1]++; 
      	s[len - n] = s[n - 1];
      	return;
    }
	else 
	{
		s[len - n] = s[n - 1] = minc;
    }
  }
  // wrap around, so extend
  s[0]++;
  s.push_back(s[0]);
}

vector<int> FindDigits(int n)
{
	
}

int main()
{
	string s = "0";
	int n = 2;
	for (int i = 0; i < n - 1; i++) 
	{
		nextpalindrome(s);
	}
	
	std::cout << s << "\n";	
}