#include "Trie.h"
#include "Util.h"
#include <cstdio>

//maping back the character
const static char word[] = "abcdefghijklmnopqrstuvwxyz";

//create a node
Trie::Trie() : root (new TrieNode) {}

Trie::Trie (const char** a, int c) : root (new TrieNode)
{
  for (int i = 0; i < c; i++)
    InsertWord (a[i]);
}

//insert a word
TrieNode* Trie::InsertWordHelper (TrieNode* node, const char* str)
{
  //found the correct node,increment the count
  if (str[0] == '\0')
    node->count++;
  
  //the word resides in its children
  else 
  {
    node->prefixcount++;
    //found its child mapping
    int index = str[0] - 'a';
	
    //if this children doesn't exist, create
    if (node->edges[index] == NULL)
      node->edges[index] = new TrieNode;
	
    //else recursively go the child, and add it there
    node->edges[index] = InsertWordHelper (node->edges[index], ++str);
  }
  
  //return the node
  return node;
}

//insert a word
TrieNode* Trie::InsertWord (const char* str)
{
  return InsertWordHelper (root, str);
}

int Trie::countWordHelper (TrieNode* node, const char* str)
{
  if (str[0] == '\0')
    return node->count;
  else 
  {
    int index = str[0] - 'a';
    //the word doesn't exist
    if (node->edges[index] == NULL)
      return 0;
    //else recursively find it in the substree
    return countWordHelper (node->edges[index], ++str);
  }
}

//count how many occurrences of the str
int Trie::countWord (const char* str)
{
  return countWordHelper (root, str);
}

int Trie::countPrefixHelper (TrieNode* node, const char* str)
{
  //if found this word, return # of its children
  if (str[0] == '\0')
    return node->prefixcount;
  else
  {
    int index = str[0] - 'a';
    //it has no children
    if (node->edges[index] == NULL)
      return 0;
	
    return countPrefixHelper (node->edges[index], ++str);
  }
  
}

int Trie::countPrefix (const char* str)
{
  countPrefixHelper (root, str);
}

int main()
{
  //pre populate the trie with words
  int count = 5;
  int len = 3;
  char** str = new char*[count];
  for (int i = 0; i < count; i++)
    str[i] = new char[len + 1];
  
  for (int i = 0; i < count; i++)
    Util::RandomLowerAlphaString (str[i], len);
  
  Util::PrintStringArray ( (const char**) str, count);
  
  Trie trie ( (const char**) str, count);
}

