/*
	Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

#include <iostream>
#include <cstring>
using namespace std;

//if string is only between A-Z
bool isUnique3(string s)
{
    int check = 0;
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int v = (int)(s[i]-'a');
        if(check & (1 << v)) 
			return false;
        check |= (1 << v);
    }
    return true;
}

//else use 256 bit hash

bool isUnique1(string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i < len; ++i)
    {
        int v = (int)s[i];
        if(a[v]) return false;
        a[v] = true;
    }
    return true;
}

bool isUnique2(string s)
{
    int a[8];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i < len; ++i)
    {
        int v = (int)s[i];
        int idx = v/32, shift=v%32;
        if(a[idx] & (1 << shift)) return false;
        a[idx] |= (1 << shift);
    }
    return true;
}

int main()
{
	
	
}