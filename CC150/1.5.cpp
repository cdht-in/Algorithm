/*
	Write a method to replace all spaces in a string with ‘%20’.
*/

#include <string>
#include <iostream>

using namespace std;

string ReplaceSpace(string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			s[i] = '%';
			s.insert(i + 1, "20");
		}
	}
	return s;
}

int main()
{
	string s = "a b cd ";
	cout << ReplaceSpace(s) << endl;
}