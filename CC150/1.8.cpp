/*
	
	Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”).

*/

#include <string>
#include <iostream>

using namespace std;

bool isSubstring(string s1, string s2){
    if(s1.find(s2) != string::npos) return true;
    else return false;
}

/*

s1 + s1 = waterbottlewaterbottle
很容易可以发现，s1+s1其实是把s1中每个字符都旋转了一遍，而同时保持原字符不动。 比如waterbottle向右旋转2个字条应该是：terbottlewa，但如果同时保持原字符不动， 我们得到的就是waterbottlewa，而terbottlewa一定是waterbottlewa的子串， 因为waterbottlewa只是在terbottlewa的基础上再加上一条原字符不动的限制。 因此s1+s1将包含s1的所有旋转字符串，如果s2是s1+s1的子串，自然也就是s1 的旋转字符串了。

*/

bool IsRotated(string s1, string s2)
{
	if(s1.length() != s2.length() || s1.length()<=0)
	        return false;
	return isSubstring(s1 + s1, s2);
}

int main()
{
	
	
}