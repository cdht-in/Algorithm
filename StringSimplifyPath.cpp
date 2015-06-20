/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
	
*/

#include <vector>
#include <string>
#include <iostream>


using namespace std;


string simplifyPath(string path) {
	if(path.size() < 1 || path[0] != '/')
		return "";
	
	vector<string> st;
	int l = 1;
	for(int r = 1; r < path.size(); r++)
	{
		while(path[r] != '/' && r < path.size())
			r++;
		
		string token = path.substr(l, r - l);
		if(token == "..")
		{
			if(st.size() > 0)
				st.pop_back();
		}
		else if(token != "." && token != "")
		{
			st.push_back(token);
		}
		l = r + 1;
	}
	
	string newPath = "/";
	for(int i = 0; i < st.size(); i++)
	{
		string subPath = "";
		if(i != st.size() - 1)
			subPath = st[i] + "/";
		else
			subPath = st[i];
		
		newPath += subPath;
	}
	
	return newPath;
}

int main(){
	cout << simplifyPath("/..") << endl;
	
}