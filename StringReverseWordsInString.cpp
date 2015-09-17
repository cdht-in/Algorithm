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

void Swap(string& s, int l, int r)
{
	for(int i = 0; i < (r - l) / 2; i++)
	{
		char tmp = s[l + i];
		s[l + i] = s[r - 1- i];
		s[r - 1 - i] = tmp;
	}
}

//assume no leading and trailing white space as mentioned in the description
void Reverse(string& s)
{
	
	int l = 0, r = 0;
	//reverse each word
	while(r < s.size())
	{
		while(r < s.size() && s[r] != ' ')
		{
			r++;
		}
		
		//one word between l and r
		Swap(s,l,r);
		
		l = r + 1;
		r++;
	}
	Swap(s,0,s.size());
}


int main(){
	string s = "the sky is blue";
	reverseWords(s);
	cout << s << endl;
}