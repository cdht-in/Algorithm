/*
	
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

Have you met this question in a real interview? Yes
Example
Given graph:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E
for s = B and t = E, return true

for s = D and t = C, return false
	
*/

#include "../commonHeader.h"

struct DirectedGraphNode 
{
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) 
{
	queue<DirectedGraphNode*> q;
	q.push(s);
	unordered_set<DirectedGraphNode*> visited;
	while(q.empty() == false)
	{
		DirectedGraphNode* head = q.front();
		q.pop();
		
		if(head == t)
			return true;
		
		for(int i = 0; i < head->neighbors.size(); i++)
		{
			if(visited.find(head->neighbors[i]) == visited.end())
			{
				q.push(head->neighbors[i]);
				visited.insert(head->neighbors[i]);
			}
		}
		
		visited.insert(head);
	}
	
	return false;
}

int main()
{
	
}