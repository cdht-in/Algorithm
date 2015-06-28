#include <string>
#include <vector>
#include <iostream>

using namespace std;

int StringToInt(const string& s) {
  string::size_type sz;
  if (s.size() == 0) return 0;
  return stoi(s, &sz);
}


// generate palindromic number less than n, this is not working!
vector<string> Generate(int n) {
  vector<string> ret;
  ret.push_back("0");

  string s = "";
  while (1) {
    s = ret.back();
    string newString = "";
    int mid = s.size() / 2;

    if ((s.size() % 2) == 0) {
      if (s[mid] < '9') {
        newString = string(s);
        newString[mid - 1] = (char)(s[mid - 1] + 1);
        newString[mid] = (char)(s[mid] + 1);
      } else {
        string firstHalf = s.substr(0, mid - 1);
        int tmp = StringToInt(firstHalf) + 1;
        string secondHalf = to_string(tmp);
        reverse(secondHalf.begin(), secondHalf.end());

        // carry on
        if (secondHalf.size() > firstHalf.size()) {
          firstHalf = string(secondHalf);
          reverse(firstHalf.begin(), firstHalf.end());
          newString = firstHalf + string(1, '0') + secondHalf;
        } else {
          firstHalf = string(secondHalf);
          reverse(firstHalf.begin(), firstHalf.end());
          newString = firstHalf + secondHalf;
        }
      }
    } else {
      if (s[mid] < '9') {
        newString = string(s);
        newString[mid] = (char)(s[mid] + 1);
      } else {
        string firstHalf = s.substr(0, mid);
        int tmp = StringToInt(firstHalf) + 1;
        string secondHalf = to_string(tmp);

        reverse(secondHalf.begin(), secondHalf.end());

        // carry on, only happens when the number is 1 digit
        if (secondHalf.size() > firstHalf.size()) {
          firstHalf = string(secondHalf);
          reverse(firstHalf.begin(), firstHalf.end());
          newString = firstHalf + secondHalf;
        } else {
          firstHalf = string(secondHalf);
          reverse(firstHalf.begin(), firstHalf.end());
          newString = firstHalf + string(1, '0') + secondHalf;
        }
      }
    }

    cout << newString << endl;
    if (StringToInt(newString) <= n)
      ret.push_back(newString);
    else
      break;
  }

  return ret;
}

char minc = '0', maxc = '9';
void nextpalindrome(std::string& s) 
{
  int len = s.size();
  //n always lands on the imaginary center of the 2*n + 1 palindrome
  for (int n = (len + 1) / 2; n > 0; n--) 
  {
	  //n - 1 is the at the center
    if (s[n - 1] < maxc)
	{
      s[len - n] = s[n - 1] = s[n - 1] + 1;
      return;
    }
	else
	{
      s[len - n] = s[n - 1] = minc;
    }
  }
  
  //wrap around, so extend
  s[0]++;
  s.push_back(s[0]);
}

string NthPalindrome(int n)
{
    std::string s = "0";
    for (int i = 0; i < n - 1; i++) 
    {
		nextpalindrome(s);
    }
	return s;
}

int main() 
{
	string s = NthPalindrome(10);
  	cout << s << endl;
  // vector<string> ret = Generate(n);
}