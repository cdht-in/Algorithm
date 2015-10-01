/*
	
Medium Word Ladder

22% Accepted
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
Have you met this question in a real interview? Yes
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
	
*/

#include "../commonHeader.h"

/*
void ladderLengthHelper(string& start, string& end, int index,int changeCount,int min,unordered_set<string> &dict)
{
	if(index >= start.size())
	{		
		return;
	}
	
	if(start == end)
	{
		min = std::min(min,changeCount);
		return;
	}
	
	for(int i = 0; i < start.size(); i++)
	{
		for(int j = 0; j < 26; j++)
		{
			char tmp = start[i];
			start[i] = (char)('a' + j);
			
			if(dict.find(start) != dict.end())
			{
				dict.erase(start);
				
				ladderLengthHelper(start,end,index + 1,changeCount + 1,min,dict);
				
				dict.insert(start);
			}
			
			start[i] = tmp;
		}
		
	}
}
*/

int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	queue<string> q;
	q.push(start);
	int cur = 1;
	int next = 0;
	int distance = 0;
	dict.insert(end);
	unordered_set<string> visited;
	
	while(q.empty() == false)
	{
		string head = q.front();
		q.pop();
		cur--;
		
		if(head == end)
		{
			return distance + 1;
		}
		
		for(int i = 0; i < head.size(); i++)
		{
			char tmp = head[i];
			for(int j = 0; j < 26; j++)
			{
				if(head[i] != (char)('a' + j))
				{
					head[i] = (char)('a' + j);
					
					if(dict.find(head) != dict.end() && visited.find(head) == visited.end())
					{
						q.push(head);
						visited.insert(head);
						next++;
					}
				}
			}
			head[i] = tmp;
		}
		
		visited.insert(head);
		
		if(cur == 0)
		{
			distance++;
			cur = next;
			next = 0;
		}
	}
	
	return 0;
}

int main()
{
	string start = "hit";
	string end = "hot";
	unordered_set<string> dict = {"hot","dot","dog","lot","log"};
	cout << ladderLength(start,end,dict) << endl;
}