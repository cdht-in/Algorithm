#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


//http://stackoverflow.com/questions/742013/how-to-code-a-url-shortener
class Host
{
	string hostName;
	
	int n;
	
	unordered_map<int,string> database;
	
	const int n64;
	
	char hashTable64bit[64];
	unordered_map<char,int> hashTable64bitReverse;
	
	vector<char> Hash64bit(int n)
	{
		vector<char> hash;
		while(n > 0)
		{
			int remainder = n % n64;
			hash.push_back(hashTable64bit[remainder]);
			n = n / 64;
		}
		
		reverse(hash.begin(),hash.end());
		return hash;
	}
	
public:
	
	Host():n64(64),n(1),hostName("www.xxx.com")
	{
		int p = 0;
		//init 64 bit hash table
		for(int i = 0; i <= 9; i++)
		{
			hashTable64bitReverse['0' + i] = p;
			hashTable64bit[p++] = '0' + i;
		}
		
		for(int i = 0; i < 26; i++)
		{
			hashTable64bitReverse['a' + i] = p;
			hashTable64bit[p++] = 'a' + i;
		}
		
		for(int i = 0; i < 26; i++)
		{
			hashTable64bitReverse['A' + i] = p;
			hashTable64bit[p++] = 'A' + i;
		}
	}
	
	string Shorten(const string& s)
	{
		database[n++] = s;
		
		vector<char> hash = Hash64bit(n - 1);
		
		string hashString = "";
		for(int i = 0; i < hash.size(); i++)
			hashString += hash[i];
		
		return hostName + "/" + hashString;
	}
	
	string Restore(const string& s)
	{
		string substr = s.substr(s.find('/') + 1);
		
		int n = 0;
		//the rest is the hashed id
		for(int i = 0; i < substr.size(); i++)
		{
			n += (hashTable64bitReverse[substr[i]] * pow(62,substr.size() - 1 - i));
		}
		return database[n];
	}
};

int main()
{
	Host host;
	
	string url1 = "https://www.youtube.com/watch?v=so6ExplQlaY";
	
	string url2 = "https://www.youtube.com/watch?v=k0d4wj4Cqvw";
	string shorted1 = host.Shorten(url1);
	string shorted2 = host.Shorten(url2);
		
	cout << host.Restore(shorted1) << endl;
	cout << host.Restore(shorted2) << endl;		
}