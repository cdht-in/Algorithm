/*

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
	
*/
#include <string>

using namespace std;


/*
Analysis:
The idea is simple, compare the current char in the string with the previous one, if they are the same, count +1, if not, print the previous char (count + char), set the new char and count, until the string ends.
Note that the the ascii code of '0' is 48, to convert the int to char we can use "char chr = i + '0';"
	
*/
string cas(string str){
        string str1;
        char ch=str[0];
        int chn=1;
        for(int i = 1; i<=str.size();i++){
            if (str[i]==ch){chn++;}
            else {
                char chr = chn+'0';
                str1 = str1+ chr;
                str1 = str1+ch;
                ch = str[i];
                chn=1;
            }
        }
        return str1;
}

string countAndSay(int n) {
// Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==1) {return "1";}
        string str1 = "1";
        string strn;
        for (int i=1; i<n;i++){
            strn = cas(str1);
            str1 = strn;
        }
        return strn;
}

int main()
{
	
	
}