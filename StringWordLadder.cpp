/*
  Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

  Only one letter can be changed at a time
  Each intermediate word must exist in the dictionary
  For example,

  Given:
  start = "hit"
  end = "cog"
  dict = ["hot","dot","dog","lot","log"]

  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
  return its length 5.

  Note:

  Return 0 if there is no such transformation sequence.
  All words have the same length.
  All words contain only lowercase alphabetic characters.
*/

#include <cstdio>
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <climits>


using namespace std;

//O(n^2) transform it into shortest path problem in graph search, since we are only changing one character at a time, assume distant bewteen each node is 1
//first implementation
int ShortestTransformation (string start, string end, unordered_set<string> dict)
{
  int trans = 0;
  if (start == end)
    return trans;
  queue<string> q;
  unordered_set<string> visited;
  //record the path
  vector<string> seq;
  q.push (start);
  while (!q.empty() ) {
    string s = q.front();
    seq.push_back (s);
    q.pop();
    for (int i = 0; i < s.size(); i++) {
      //change one character at a time
      for (int j = 0; j < 26; j++) {
        string tmp = s;
        tmp[i] = 'a' + j;
        //found the transformation
        if (tmp == end) {
          for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << " ";
          }
          cout << tmp << endl;
          //trans in bewteen + start and end
          return trans;
        }
        //if haven't seen this permutation and it is in the given dict
        if (visited.find (tmp) == visited.end() && dict.find (tmp) != dict.end() ) {
          //push the neighbor into the q
          q.push (tmp);
          //mark it visisted
          visited.insert (tmp);
          trans++;
        }
      }
    }
  }
  return 0;
}





bool CanTransform(string s1,string s2){
	//if the current word could be transformed into any dictionary word
	int nDiff = 0;
	for(int i = 0; i < s1.size(); i++)
	{
		if(s1[i] != s2[i])
			nDiff++;
	}
	return nDiff == 1;
}

//second implementation, this would fail at LeetCode's Time Limit Exceed for some reason
int ladderLength(string start, string end, unordered_set<string> &dict) {

	queue<string> q;
	q.push(start);
	int nSteps = 1;
	unordered_set<string> unvisited = dict;
	unvisited.erase(start);
		
	while(q.empty() == false)
	{
		string s = q.front();
		q.pop();
				
		//if can transfrom to any word in the dict
		for (auto it = unvisited.begin(); it != unvisited.end();)
		{
			string word = *it;
			
			if(CanTransform(s,word))
			{
				nSteps++;
				
				if(word == end)
				{
					return nSteps;
				}
				
				q.push(word);	
				//mark this as visited
				it = unvisited.erase(it);
			}
			else{
				it++;
			}	
		}
	}
	return 0;
}


//this would pass the Leetcode's test, but it is essentially the same thing as what I had above
/*
int ladderLength(string start, string end, unordered_set<string> &dict) 
{
    if (dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end()) return 0;

    queue<string> q;
    q.push(start);
    unordered_map<string, int> visited;  // visited track the distance
    visited[start] = 1;
    unordered_set<string> unvisited = dict;  // unvisited prevent searching through the whole dict
    unvisited.erase(start);

    while (!q.empty())
    {
        string word = q.front(); q.pop();
        auto itr = unvisited.begin();
        while (itr != unvisited.end())
        {
            string adjWord = *itr;
            if (oneCharDiff(word, adjWord))
            {
                visited[adjWord] = visited[word] + 1;
                if (adjWord == end) return visited[adjWord];
                itr = unvisited.erase(itr);  // tricky here
                q.push(adjWord);
            }
            else
            {
                ++itr;
            }
        }
    }
    return 0;
}

inline bool oneCharDiff(const string& str1, const string& str2)
{
    int diff = 0;
    for (int i = 0; i < str1.size(); ++i) 
    {
        if (str1[i] != str2[i]) ++diff;
        if (diff > 1) return false;  // perhaps quicker
    }
    return diff == 1;
}
	
*/



int main()
{
  string start = "hot";
  string end = "dog";
  unordered_set<string> dict ( {"hot", "dog", "dot"});
  cout <<  ladderLength(start, end, dict) << endl;
}

