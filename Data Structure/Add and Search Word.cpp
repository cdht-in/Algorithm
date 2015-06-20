#include <string>
#include <iostream>


/*
	
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
	
*/

using namespace std;

#define nLetters 26

class TrieNode 
{
	
public:
	
	int c;
	TrieNode* edges[nLetters];
	
    // Initialize your data structure here.
    TrieNode():c()
	{
		for(int i = 0; i < nLetters; i++)
		{
			edges[i] = 0;
		}
    }
};

class WordDictionary 
{
	
public:

	WordDictionary()
	{
        root = new TrieNode();
	}
	
    // Adds a word into the data structure.
    void addWord(string word) 
	{
        InsertHelper(root,word,0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
	{
        return SearchHelper(root,word,0);
    }
	
private:
	
    TrieNode* root;
		
	TrieNode* InsertHelper(TrieNode* node, const string& s, int start)
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
			
			node->edges[index] = InsertHelper(node->edges[index], s, start + 1);
			
		}
		
		return node;
	}
	
	bool SearchHelper(TrieNode* node, const string& s, int start)
	{
		if(start >= s.size())
		{
			return node->c > 0;
		}
		
		if(s[start] != '.')
		{
			int index = s[start] - 'a';
		
			if(node->edges[index] == 0)
				return false;
		
			return SearchHelper(node->edges[index], s, start + 1);
		}
		
		for(int i = 0; i < nLetters; i++)
		{
			if(node->edges[i] != 0)
			{
				if(SearchHelper(node->edges[i], s, start + 1))
					return true;
				
			}
		}
		
		return false;
	}
	
};

int main()
{
	//cout << trie.search("b") << " " << trie.startsWith("c")  << endl;
}



// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");