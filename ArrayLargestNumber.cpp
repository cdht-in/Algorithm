/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool myfunction (string i,string j) 
{
	//"12 " + "3 " > "3" + "12"
	return (i + j > j + i);
}

string largestNumber(vector<int> &num) {
	if(num.size() < 1)
		return "";
	int n = num.size();
	string* s = new string[n];
	for(int i = 0; i < n; i++)
	{  
		ostringstream ostr;
		ostr << num[i];
		s[i] = ostr.str();
	}
	sort(s, s + n, myfunction);
	string result = "";
	for(int i = 0; i < n; i++)
	{
		result += s[i];
	}
	if(result[0] == '0')
		return "0";
	delete[] s;
	return result;
}

   
int main(){
	int num[] = {3, 30, 34, 5, 9};
	vector<int> vec(num, num + sizeof(num) / sizeof(int));
	string s = largestNumber(vec);
	cout << s << endl;
	
}