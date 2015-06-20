/*
	Write a method to decide if two strings are anagrams or not.
*/

#include <string>
#include <algorithm>


using namespace std;


//nlog(n)
bool IsAnagram(string a, string b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	return a == b;
}

//O(n)
bool IsAnagramI(string a, string b){
	int n = 256;
	int map[n];
	memset(map,0,n * sizeof(int));
	
	for(int i = 0; i < a.size(); i++)
		map[a[i]]++;
	
	for(int i = 0; i < b.size(); i++)
	{
		map[b[i]]--;
	}

	for(int i = 0; i < n; i++)
	{
		if(map[i] > 0)
			return false;
	}
	return true;
}

int main()
{
	
	
}