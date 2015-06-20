#include <iostream>
#include <vector>

using namespace std;

#define nLetters 26

struct TrieNode
{
	int c;
	
	TrieNode* edges[nLetters];
	
	TrieNode():c()
	{
		for(int i = 0; i < nLetters; i++)
		{
			edges[i] = 0;
		}
	} 
};

struct Trie
{
	
private:
	
	int CountWordHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{
			return node->c;
		}
		
	    int index = s[start] - 'a';
		
	    //the word doesn't exist
	    if (node->edges[index] == 0)
	      return 0;
		
	    //else recursively find it in the substree
	    return CountWordHelper (node->edges[index], s, start + 1);
	}
	
	TrieNode* InsertWordHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{
			node->c++;
		}
		else
		{
			int index = s[start] - 'a';
			
			if(node->edges[index] == 0)
				node->edges[index] = new TrieNode;
			
			node->c++;
			
			node->edges[index] = InsertWordHelper(node->edges[index], s, start + 1);
		}
		
		return node;
	}
	
	bool FindWordHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{
			return true;
		}
		
		int index = s[start] - 'a';
		
		if(node->edges[index] == 0)
			return false;
		
		return FindWordHelper(node->edges[index], s, start + 1);
	}
	
public:
	
	TrieNode* root;
	
	Trie():root(new TrieNode)
	{
	}
	
    //insert a word
    TrieNode* InsertWord (const string& s)
	{
		return InsertWordHelper(root,s,0);
	}
		
	int CountWord(const string& s)
	{
		return CountWordHelper(root,s,0);
	}
	
	bool FindWord(const string& s)	
	{
		return FindWordHelper(root,s,0);
	}
	
	
    inline const TrieNode* getRoot() const 
    {
      return root;
    }
	
};

int main()
{
	Trie* tree = new Trie;
	
	string s = "abcd";
	
	for(int i = 0; i < s.size(); i++)
	{
		string substr = s.substr(i);
		tree->InsertWord(substr);
	}
	
	vector<string> vec;
	vec.push_back("bc");
	vec.push_back("b");
	
	for(int i = 0; i < vec.size(); i++)
	{
		cout << tree->FindWord(vec[i]) << endl;
	}
}


