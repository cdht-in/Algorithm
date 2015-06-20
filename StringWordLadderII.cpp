/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
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
#include <unordered_map>
#include <algorithm>

using namespace std;

inline bool oneCharDiff(const string& str1, const string& str2)
{
    int diff = 0;
    for (int i = 0; i < str1.size(); ++i) 
    {
        if (str1[i] != str2[i]) ++diff;
        if (diff > 1) 
			return false;  // perhaps quicker
    }
	
    return diff == 1;
}


/*

//DFS to enumerate all paths, doesn't work for now, and didn't find the reason yet
void findLaddersHelper(vector<string>& path, vector<vector<string> >& paths,string start,string& end,unordered_set<string>& visited,unordered_set<string> &dict){
	
	cout << start << endl;
	
	if(start == end)
	{
		path.push_back(start);
		paths.push_back(path);
		return;
	}
	
	if(visited.find(start) == visited.end())
	{
		visited.insert(start);
		path.push_back(start);
		
		//mutate the word
		for(int i = 0; i < start.size(); i++)
		{
			char tmp = start[i];
			for(int j = 0; j < 26; j++)
			{
				if(tmp !=  (char)('a' + j))
				{				
					start[i] = (char)('a' + j);
					
					if(dict.find(start) == dict.end())
						continue;
					
					findLaddersHelper(path,paths,start,end,visited,dict);
				}
			}
			start[i] = tmp;
		}
		
		path.push_back(start);
		visited.erase(start);
	}
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
{
	vector<vector<string> > allPaths;
	vector<string> path;
	unordered_set<string> visited;
	findLaddersHelper(path,allPaths,start,end,visited,dict);
	
	//now find trim off to find the shortest path
	int min = INT_MAX;
	vector<vector<string> > trimmedPaths;
	for(int i = 0; i < allPaths.size(); i++)
	{
		if(allPaths[i].size() < min)
		{
			min = allPaths[i].size();
			
			trimmedPaths.clear();
			trimmedPaths.push_back(allPaths[i]);
		}
		else if(allPaths[i].size() == min)
		{
			trimmedPaths.push_back(allPaths[i]);
		}
			
	}

	return allPaths;
}

*/

//BFS gaurantee the shortest distant, find the distant from the start to each dictionary word
void bfs(unordered_map<string, vector<string> >& adjacencyList, unordered_map<string, int>& distance, string start, string end, unordered_set<string>& dict)
{
	queue<string> q;
	q.push(start);
	
	distance[start] = 0;
	
	for (auto i = dict.begin(); i != dict.end(); i++) 
	{
		adjacencyList[*i] = vector<string>();
	}
	
    //build the adjacency list for each word in the dict
	while (q.empty() == false) 
	{
	    string word = q.front();
		q.pop();
		//mutate the word
		for(int i = 0; i < word.size(); i++)
		{
			for(int j = 0; j < 26; j++)
			{
				if(word[i] !=  (char)('a' + j))
				{				
					string newWord = word;
					newWord[i] = (char)('a' + j);;
					
					if(dict.find(newWord) != dict.end())
					{
						
						adjacencyList[newWord].push_back(word);
						
						//this build the distance between all dictionary words and the starting word
						if(distance.find(newWord) == distance.end())
						{
							distance[newWord] = distance[word] + 1;	
							
							q.push(newWord);		
						}
					}
				}
			}
		}			
	}
}

void dfs(vector<vector<string> >& ladders, vector<string>& path, string& crt, string& start, unordered_map<string, int>& distance, unordered_map<string, vector<string> >& adjacencyList) 
{
       path.push_back(crt);
	   
       if (crt == start) 
	   {
           reverse(path.begin(),path.end());
           ladders.push_back(path);
           reverse(path.begin(),path.end());
       } 
	   else 
	   {
		   vector<string> neightbors = adjacencyList[crt];
		   for(int i = 0; i < neightbors.size(); i++)
		   {
			   string neightbor = neightbors[i];
			   //cout << crt << " 's " << distance[crt] << neightbor << " 's " << distance[neightbor] << endl;
			   //distance[crt] == distance[neightbor] + 1 this would act like a visited graph to make sure each node is traverse once
               if ((distance.find(neightbor) != distance.end()) && distance[crt] == distance[neightbor] + 1) 
			   { 
                   dfs(ladders, path, neightbor, start, distance, adjacencyList);
               }			
		   }
       }
	   
       path.pop_back();
}


vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
{
	vector<vector<string> > ladders;
	
    unordered_map<string, vector<string> > adjacencyList;
	
    unordered_map<string, int> distance;
   
    dict.insert(end);
   
    bfs(adjacencyList, distance, start, end, dict);
	
	vector<string> path;
	
	//note how the dfs start at the end
   	dfs(ladders, path, end, start, distance, adjacencyList);
   
    return ladders;
}



int main()
{
  string start = "hit";
  string end = "cog";
  unordered_set<string> dict ({"hot","dot","dog","lot","log"});
  vector<vector<string> > paths = findLadders(start, end, dict);
  for(int i = 0; i < paths.size(); i++)
  {
	  for(int j = 0; j < paths[i].size(); j++)
	  {
		  cout << paths[i][j] << " ";
	  }
	  cout << endl;
  }
	  
}

	

