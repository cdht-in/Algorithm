/*

Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

FOLLOW UP

Write the test cases for this method.
	
*/

#include <string>
#include <iostream>

using namespace std;

//brute force
string RemoveDuplicate(string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		for(int j = i + 1; j < s.size(); j++)
		{
			if(s[i] == s[j])
				s.erase(j,1);
		}
	}
	return s;
}

//or open up a ASCII code hash

int main()
{	
	cout << RemoveDuplicate("abbc")	 << endl;
}