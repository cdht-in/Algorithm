#include <iostream>
#include <string>

using namespace std;


string Trim(string const& str)
{
	if(str.empty())
		return str;
    size_t first = str.find_first_not_of('0');
	//size_t last  = str.find_last_not_of('0');
	return str.substr(first, str.size()-first+1);
}

int compareVersion(string version1, string version2) {
    
	//find the dots
	int dot1 = version1.find_first_of('.',0);
	string version1s1;
	string version1s2;
	if(dot1 == string::npos)
	{
		version1s1 = Trim(version1);
		version1s2 = "";
	}
	else{
   		version1s1 = version1.substr(0,dot1);
   	 	version1s2 = version1.substr(dot1);
	}
	
	int dot2 = version2.find_first_of('.',0);
	string version2s1;
	string version2s2;
	if(dot2 == string::npos)
	{
		version2s1 = Trim(version2);
		version2s2 = "";
	}
	else{
   		version2s1 = version1.substr(0,dot2);
   	 	version2s2 = version1.substr(dot2);
	}
		
	if(version1s1 < version2s1)
		return -1;
	if(version1s1 > version2s1)
		return 1;
	
	if(version1s2 < version2s2)
		return -1;
	if(version1s2 > version2s2)
		return 1;
	return 0;
}

int main(){
	
	string s1 = "10";
	string s2 = "1";
	cout << compareVersion(s1,s2) << endl;
		
}