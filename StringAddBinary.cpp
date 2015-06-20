#include <string>
#include <iostream>
#include <algorithm>
/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

using namespace std;

/*

first implementation

string addBinary(string a, string b) {
  int i = a.size() - 1;
  int j = b.size() - 1;
  int k = max (a.size(), b.size() );
  //the sum has at most a.size + b.size + 1 bits
  string ret = string (k + 1, '0');
  string carry = "0";
  string tmpa = "";
  string tmpb = "";
  while (i >= 0 && j >= 0) {
    tmpa = a[i];
    tmpb = b[j];
    //if one number is smaller, keep adding 0s
    if (tmpa + tmpb == "11" && carry == "0" ) {
      ret[k] = '0';
      carry = "1";
    }
    else if (tmpa + tmpb == "11" && carry == "1" ) {
      ret[k] =  '1';
      carry = "1";
    }
    else if (tmpa + tmpb == "00" && carry == "0") {
      ret[k] = '0';
      carry = "0";
    }
    else if (tmpa + tmpb == "00" && carry == "1") {
      ret[k] = '1';
      carry = "0";
    }
    else if ( (tmpa + tmpb == "01" || tmpa + tmpb == "10") && carry == "0" ) {
      ret[k] = '1';
      carry = "0";
    }
    else {
      ret[k] = '0';
      carry = "1";
    }
    i--;
    j--;
    k--;
  }
  if (i == -1) {
    while (j >= 0) {
      if (b[j] + carry == "11") {
	ret[k--] = '0';
	carry = "1";
      }
      else if (b[j] + carry == "01" || b[j] + carry == "10") {
	ret[k--] = '1';
	carry = "0";
      }
      else {
	ret[k--] = '0';
	carry = "0";
      }
      j--;
    }
  }
  else{
    while (i >= 0) {
      if (a[i] + carry == "11") {
	ret[k--] = '0';
	carry = "1";
      }
      else if (a[i] + carry == "01" || a[i] + carry == "10") {
	ret[k--] = '1';
	carry = "0";
      }
      else {
	ret[k--] = '0';
	carry = "0";
      }
      i--;
    }
  }
  if(carry == "1"){
    ret[k] = '1';
    return ret;
  }
  return ret.substr (k + 1);
}

*/

//second implementaion

string addBinary(string a, string b) {
	int m = a.size();
	int n = b.size();
	
	if(m > n)
	{
		int diff = m - n;
		string newB = "";
		for(int i = 0; i < diff; i++)
			newB += "0";
		newB += b;
		b = newB;
		n = m;
	}
	else if(m < n)
	{
		int diff = n - m;
		string newA = "";
		for(int i = 0; i < diff; i++)
			newA += "0";
		newA += a;
		a = newA;
		m = n;
	}
	
	//now m == n
	bool carry = false;
	string c = string(m + 1,'0');
	for(int i = m - 1; i >= 0; i--)
	{
		if(a[i] == '1' && b[i] == '1')
		{
			if(carry)
				c[i + 1] = '1';
			else
				c[i + 1] = '0';
			carry = true;
		}
		else if(a[i] == '0' && b[i] == '0')
		{
			if(carry)
				c[i + 1] = '1';
			else
				c[i + 1] = '0';
			carry = false;
		}
		else
		{
			if(carry)
			{
				c[i + 1] = '0';
				carry = true;
			}
			else
			{
				c[i + 1] = '1';
				carry = false;
			}
		}
	}
	if(carry)
	{
		c[0] = '1';
		return c;
	}
	return c.substr(1);
}

int main()
{
  string a = "1";
  string b = "0";
  // string a = "10110011111100000010101011111110101000100010100101";
  //string b = "10101010101101001011001111101100110011000110010111101010101011000101001010011010000101010111010";
  cout << addBinary (a, b) << endl;
}
