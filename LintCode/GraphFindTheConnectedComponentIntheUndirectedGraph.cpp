/*
	
Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

Have you met this question in a real interview? Yes
Example
Given graph:

A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
	
*/

#include "../commonHeader.h"

struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

vector<vector<int> > connectedSet(vector<UndirectedGraphNode*>& nodes) 
{
	//first build the graph of incoming edges
	vector<vector<int> > sets;
	unordered_set<UndirectedGraphNode*> visited;
	for(auto& node : nodes)
	{
		if(visited.find(node) != visited.end())
			continue;
		
		queue<UndirectedGraphNode*> q;
		q.push(node);
		sets.push_back(vector<int>());
		
		while(q.empty() == false)
		{
			UndirectedGraphNode* head = q.front();
			q.pop();
			visited.insert(head);
			
			sets.back().push_back(head->label);
			
			for(auto neighbor : head->neighbors)
			{
				if(visited.find(neighbor) == visited.end())
				{
					q.push(neighbor);
					visited.insert(neighbor);
				}
			}
		}
	}
	
	for(int i = 0; i < sets.size(); i++)
	{
		sort(sets[i].begin(),sets[i].end());
	}
	
	return sets;
}

int main()
{
	
}