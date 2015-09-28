/*
	
Longest Common Prefix

27% Accepted
Given k strings, find the longest common prefix (LCP).

Have you met this question in a real interview? Yes
Example
For strings "ABCD", "ABEF" and "ACEF", the LCP is "A"

For strings "ABCDEFG", "ABCEFG" and "ABCEFA", the LCP is "ABC"
	
*/

#include "../commonHeader.h"

struct PrefixTreeNode
{
	const static int n = 26;
	int c;
	int nPrefix;
	int prefixLen;
	PrefixTreeNode* edges[n];
	
	PrefixTreeNode(): c(),nPrefix(),prefixLen()
	{
		for(int i = 0; i < n; i++)
		{
			edges[i] = 0;
		}
	}
};

struct PrefixTree
{
private:
	
	PrefixTreeNode* root;
	int numberOfNodes;
	
	void AddHelper(PrefixTreeNode* node,const string& s, int index)
	{
		if(node == 0)
			return;
		
		node->nPrefix++;
		node->prefixLen = index;
				
		if(index >= s.size())
		{
			node->c++;
			numberOfNodes++;
			return;
		}
		
		char edge = tolower(s[index]) - 'a';
		if(node->edges[edge] == 0)
		{
			node->edges[edge] = new PrefixTreeNode();
		}
		
		AddHelper(node->edges[edge],s,index + 1);
	}
	
	int GetLongestPrefix(PrefixTreeNode* node)
	{
		if(node == 0)
		{
			return 0;
		}
		
		int longestCommonPrefix = 0;
		if(node->nPrefix == numberOfNodes)
		{
			longestCommonPrefix = node->prefixLen;	
		}
		
		
		for(int i = 0; i < PrefixTreeNode::n; i++)
		{
			longestCommonPrefix = std::max(longestCommonPrefix,GetLongestPrefix(node->edges[i]));
		}
		
		return longestCommonPrefix;
	}
	
public:	
	
	PrefixTree():root(new PrefixTreeNode()),numberOfNodes()
	{
	}
	
	void Add(const string& s)
	{
		AddHelper(root,s,0);
	}
	
	int GetLongestPrefix()
	{
		return GetLongestPrefix(root);
	}
	
};

string longestCommonPrefix(vector<string> &strs) 
{
	if(strs.size() == 0)
	{
		return "";
	}
	
	//build the prefix tree
	PrefixTree tree;
	for(auto& s : strs)
	{
		tree.Add(s);
	}
	int n = tree.GetLongestPrefix();
	return strs[0].substr(0,n);
}

int main()
{
	vector<string> strs = {"ABC"};
	cout << longestCommonPrefix(strs) << endl;
}