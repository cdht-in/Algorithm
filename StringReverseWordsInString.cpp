#include <string>
#include <iostream>

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
	
*/


using namespace std;

string trim(string const& str)
{
    if(str.empty())
        return str;

    size_t first = str.find_first_not_of(' ');
    size_t last  = str.find_last_not_of(' ');
    return str.substr(first, last-first+1);
}

void reverseWords(string &s) {
	string rs;  
	    for (int i = s.length()-1; i >= 0; )  
	    {  
	        while (i >= 0 && s[i] == ' ') i--;  
	        if (i < 0) break;  
	        if (!rs.empty()) rs.push_back(' ');  
	        string t;  
	        while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);  
	        reverse(t.begin(), t.end());  
	        rs.append(t);  
	    }  
	    s = rs;  
}

int main(){
	string s = "the sky is blue";
	reverseWords(s);
	cout << s << endl;
}