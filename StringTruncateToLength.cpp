/*
	
	Truncate the string to maxLen without trailing white spaces
	
*/

/*
"one search all jobs"

10 -> "one search"
6 -> "one"
4 -> "one"

"one search all jobs"

"   one search all jobs"

9 -> "       one"

"one    "

"one   search     "
14 -> "one"

5 -> "one"

0 -> ""
1 -> ""
2 -> ""
3 -> "one"
4 -> "one"

*/

#include <string>
#include <iostream>

using namespace std;

string Truncate(string& s, int maxLen)
{
    if(maxLen == 0)
        return "";
        
    if(maxLen < 0 || s.size() <= maxLen)
        return s;
    
    //s.size() > maxLen 
    int i = maxLen - 1;   
    if(s[maxLen - 1] != ' ')
    {
        if(s[maxLen] != ' ')
        {
           while(i >= 0 && s[i] != ' ')
           {
                i--;
           }        
        }
        
    }
    
    while(i >= 0 && s[i] == ' ')
    {
        i--;
    }    
    
    return s.substr(0,i + 1);
}

int main()
{
	string s = "one search all jobs";
	int maxLen = 4;
	cout << Truncate(s,maxLen) << endl;
}