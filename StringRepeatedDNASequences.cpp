#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	int len = s.size();
	int n = 10;
	vector<string> vec;
	if(len < n)
		return vec;
	int map[26];
	map['A' - 'A'] = 0;
	map['C' - 'A'] = 1;
	map['G' - 'A'] = 2;
	map['T' - 'A'] = 3;
	set<int> existingSeq;
	set<int> duplicateSeq;
	int hashValue = 0;
	//hash the first substr
	for(int i = 0; i < n; i++)
	{
		//substract only the last 20 bits
		hashValue  = ((hashValue << 2) | map[s[i] - 'A']) & 0x000FFFFF;
	}
	existingSeq.insert(hashValue);
	
	for(int i = 1; i < len - n + 1; i++)
	{
		int j = i + n - 1;
		//moving hash
		int newHashValue = ((hashValue << 2) 
			| map[s[j] - 'A']) & 0x000FFFFF;;
		if(existingSeq.find(newHashValue) == existingSeq.end())
		{
			existingSeq.insert(newHashValue);
		}
		else
		{
			if(duplicateSeq.find(newHashValue) == duplicateSeq.end())
			{
				vec.push_back(s.substr(i,n));
				duplicateSeq.insert(newHashValue);
			}
			
		}
		//update hte previous hashValue
		hashValue = newHashValue;
	}	
    return vec;    
}



int main(){
	//["AAAAACCCCC", "CCCCCAAAAA"].
	string s = "AAAAAAAAAAAA";
	vector<string> vec = findRepeatedDnaSequences(s);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << "result : " << vec[i] << endl;
	}
}