#ifndef TRIE_H
#define TRIE_H

/*
  A Trie data structure，note that the word is stored as the mapping from one level to another, current it only supports loweralpha string
*/

//26 different letters
#define nLetters 26
#define NULL 0

struct TrieNode
 {
  //# of this current word
  int count;
  //# of words that have this current prefix
  int prefixcount;
  //pointer to its children that share this prefix
  TrieNode* edges[nLetters];
  
  TrieNode() : count(), prefixcount() 
  {
    for (int i = 0; i < nLetters; i++)
      edges[i] = NULL;
  }
  
};

class Trie 
{

  TrieNode* root;
  int countWordHelper (TrieNode* node, const char* str);
  TrieNode* InsertWordHelper (TrieNode* node, const char* str);
  int countPrefixHelper (TrieNode* node, const char* str);

public:
  //default constructor
  Trie();
  
  //init a Trie with a array of strings
  Trie (const char** a, int c);
  //insert a word
  TrieNode* InsertWord (const char* str);

  //count how many occurrences of the str
  int countWord (const char* str);

  //count number of words that have this prefix
  int countPrefix (const char* str);

  inline const TrieNode* getRoot() const 
  {
    return root;
  }

};

#endif
