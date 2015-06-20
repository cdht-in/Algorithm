/*

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
	
*/
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

void findWordsHelper(vector<vector<char> >& board, vector<vector<bool> >& visited,int i, int j, int m, int n,int start, int end, const string& word,unordered_set<string>& set)
{
	
	if(start > end)
	{
		set.insert(word);
		return;
	}
	
	if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j] || word[start] != board[i][j])
		return;
		
	visited[i][j] = true;
	
	findWordsHelper(board,visited,i + 1, j, m, n, start + 1, end, word,set);
	findWordsHelper(board,visited,i, j + 1, m, n, start + 1, end, word,set);
	findWordsHelper(board,visited,i - 1, j, m, n, start + 1, end, word,set);
	findWordsHelper(board,visited,i, j - 1, m, n, start + 1, end, word,set);
	
	visited[i][j] = false;
	
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) 
{
	int m = board.size();
	if(m == 0)
		return vector<string>();
			
	int n = board[0].size();
	
	vector<vector<bool> > visited(m, vector<bool>(n,false));
	unordered_set<string> set;
		
	for(int k = 0; k < words.size(); k++)
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				findWordsHelper(board,visited,i,j,m,n,0,words[k].size() - 1,words[k],set);
			}
		}
	}
	
	vector<string> result;
	for(auto i = set.begin(); i != set.end(); i++)
	{
		result.push_back(*i);
	}
	
	return result;
}

int main()
{
	vector<vector<char> > board;
	board.push_back(vector<char>(1,'a'));
	vector<string> words;
	words.push_back("a");
	
	vector<string> ret = findWords(board,words);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	
}