/*
	You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
	
*/

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;



//moving window
vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> vec;
	if(S.size() == 0 || L.size() == 0)
		return vec;
	
	int n = L[0].size();
	
	int window = n * L.size();
	
	if(S.size() < window)
		return vec;
	
	map<string, int> m;
	
	for(int i = 0; i < L.size(); i++)
	{
		if(m.find(L[i]) == m.end())
		{
			m[L[i]] = 1;
		}
		else
			m[L[i]]++;
	}
	
    int i = 0;
	//remaining substr is greater than the window
	//O(S * L) => O(n ^ 2)
    while(S.size() - i >= window){
		map<string, int> tmpM(m);
		for(int j = 0;j < L.size();j++)
		{
            string str = S.substr(i + j * n, n);
            if(tmpM.find(str) != tmpM.end())
			{
                tmpM[str]--;
				if(tmpM[str] == 0)
                    tmpM.erase(str);
            }
			else
                break;
        }
        if(tmpM.size() == 0) 
			vec.push_back(i);
        i++;
    }
	return vec;	  
}

int main(){
	string S = "barfoothefoobarman";
	
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");	
	
	vector<int> vec = findSubstring(S,L);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	
	
}