#include <string>
#include <iostream>

using namespace std;

#define nLetters 26

class TrieNode 
{
	
public:
	
	int prefix;
	int c;
	TrieNode* edges[nLetters];
	
    // Initialize your data structure here.
    TrieNode():c(),prefix()
	{
		for(int i = 0; i < nLetters; i++)
		{
			edges[i] = 0;
		}
    }
};

class Trie 
{
public:
    Trie() 
	{
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        InsertHelper(root,s,0);
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return SearchHelper(root,key,0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
	{
        return (StartsWithHelper(root,prefix,0) > 0)? true : false;
    }
	
	void PrintStrings()
	{
		PrintStringsHelper(root,"");
	}

private:
    TrieNode* root;
	
	void PrintStringsHelper(TrieNode* node,string s)
	{
		bool f = false;
		for(int i = 0; i < nLetters; i++)
		{
			if(node->edges[i] != 0)
			{
				f = true;
				PrintStringsHelper(node->edges[i],s + string(1,'a' + i));
			}
		}
		
		//leaf
		if(f == false)
		{
			for(int i = 0; i < node->c; i++)
				cout << s << endl;
		}
		
	}
	
	int StartsWithHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{			
			return node->prefix;
		}
		
	    int index = s[start] - 'a';
		
	    //the word doesn't exist
	    if (node->edges[index] == 0)
	      return 0;
		
		//cout << "asd " << index << endl;
	    //else recursively find it in the substree
	    return StartsWithHelper (node->edges[index], s, start + 1);
	}
	
	
	TrieNode* InsertHelper(TrieNode* node, const string& s, int start)
	{
		node->prefix++;
		
		if(start >= s.size())
		{
			node->c++;
		}	
		else
		{
			int index = s[start] - 'a';
			
			if(node->edges[index] == 0)
				node->edges[index] = new TrieNode;
			
			node->edges[index] = InsertHelper(node->edges[index], s, start + 1);
			
		}
		
		return node;
	}
	
	bool SearchHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{
			return node->c;
		}
		
		int index = s[start] - 'a';
		
		if(node->edges[index] == 0)
			return false;
		
		return SearchHelper(node->edges[index], s, start + 1);
	}

};


int main()
{
	Trie trie;
	trie.insert("ac");
	trie.insert("ab");
	trie.insert("ab");
	trie.PrintStrings();
	//cout << trie.search("b") << " " << trie.startsWith("c")  << endl;
}



// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");