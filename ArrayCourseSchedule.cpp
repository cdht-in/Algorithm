/*
	
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
There are several ways to represent a graph. For example, the input prerequisites is a graph represented by a list of edges. Is this graph representation appropriate?
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
	
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//first attempt
bool canFinishHelper(vector<unordered_set<int> >& graph, int start,vector<bool>& visited,unordered_set<int>& isCycle)
{
	visited[start] = true;
	isCycle.insert(start);
	
	//search it's neightbors
	for(auto it = graph[start].begin(); it != graph[start].end(); it++)
	{
		//outgoing edges
		if(isCycle.find(*it) != isCycle.end() || canFinishHelper(graph,*it,visited,isCycle) == false)
		{	
			return false;
		}
	}
	
	isCycle.erase(start);
	return true;
}

//find a cyle in the graph
bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
{
	//build the adjacency matrix
	vector<unordered_set<int> > adjMatrix(numCourses);
	
	for(int i = 0; i < prerequisites.size(); i++)
	{
		int start = prerequisites[i][1];
		int end = prerequisites[i][0];	
		adjMatrix[start].insert(end);
	}
	
	//find cycle in the graph
	vector<bool> visited(numCourses, false);
	
	unordered_set<int> isCycle;
	
	for(int i = 0; i < numCourses; i++)
	{
		if(visited[i] == false && canFinishHelper(adjMatrix,i,visited,isCycle) == false)
			return false;
	}
	
	return true;
}


//BFS topological sort
bool canFinishI(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    vector<int> d(numCourses, 0); // in-degree
    for(int i = 0; i < numCourses; ++ i)
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            ++d[*it];

    for(int j = 0, i; j < numCourses; ++ j)
    {
        for(i = 0; i < numCourses && d[i] != 0; ++i); // find a node whose in-degree is 0

		//there is a dependency cycle
        if(i == numCourses)
            return false;

        d[i] = -1;
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            --d[*it];
    }

    return true;
}

bool canFinishII(int numCourses, vector<pair<int,int> >& prerequisites)
{
	if(prerequisites.size() == 0)
		return true;
	
	unordered_map<int,vector<int> > inDegree;
	unordered_map<int,vector<int> > graph;
	
	for(int i = 0; i < prerequisites.size(); i++)
	{
		if(inDegree.find(prerequisites[i].first) == inDegree.end())
		{
			inDegree[prerequisites[i].first] = vector<int>();
		}
		
		inDegree[prerequisites[i].first].push_back(prerequisites[i].second);
		
		
		if(graph.find(prerequisites[i].second) == graph.end())
		{
			graph[prerequisites[i].second] = vector<int>();
		}
		
		graph[prerequisites[i].second].push_back(prerequisites[i].first);
		
	}
	
	//find the zero indegree nodes;	
	vector<int> zeroInDegree;
	
	for(int i = 0; i < numCourses; i++)
	{
		if(inDegree.find(i) == inDegree.end())
			zeroInDegree.push_back(i);
	}
		
	while(zeroInDegree.size() > 0)
	{
		int node = zeroInDegree.back();
		zeroInDegree.pop_back();
		
		vector<int> edges = graph[node];
		
		graph.erase(node);
		
		for(int i = 0; i < edges.size(); i++)
		{
			//this node only has the edge
			for(int j = 0; j < inDegree[edges[i]].size(); j++)
			{
				if(inDegree[edges[i]][j] == node)
				{
					inDegree[edges[i]].erase(inDegree[edges[i]].begin() + j);
				}
				
				if(inDegree[edges[i]].size() == 0)
					zeroInDegree.push_back(edges[i]);
			}
		}
	}
	
	return (graph.size() == 0);
}

bool canFinishIII(int numCourses, vector<pair<int,int> >& prerequisites)
{
	if(prerequisites.size() == 0)
		return true;
	
	vector<vector<bool> > graph(numCourses,vector<bool>(numCourses,false));
	
	//adjacency matrix
	for(int i = 0; i < prerequisites.size(); i++)
	{
		int start = prerequisites[i].second;
		int end = prerequisites[i].first;
		
		graph[start][end] = true;		
	}
	
	vector<bool> removed(numCourses,false);
	while(1)
	{
		bool noZeroInDegree = true;
		
		for(int node = 0; node < numCourses && removed[node] == false; node++)
		{
			//find the zero indegree nodes;	
			int inDegree = 0;
			while(inDegree < numCourses && graph[inDegree][node] == false)
			{
				inDegree++;
			}
				
			//found a zero indegree node
			if(inDegree == numCourses)
			{	
				noZeroInDegree = false;
				
				for(int k = 0; k < numCourses; k++)
				{
					//remove the edge
					graph[node][k] = false;
				}
				
				removed[node] = true;
			}
		}
		
		if(noZeroInDegree)
		{
			for(int i = 0; i < removed.size(); i++)
			{
				if(removed[i] == false)
					return false;
			}
			return true;
		}			
	}
	
	return true;
}


int main()
{
	int n = 2;
	vector<pair<int,int> > pre;
	pre.push_back({0,1});
	//pre.push_back({1,0});
	
	//cout << canFinishII(n,pre)  << endl;
	cout << canFinishIII(n,pre) << endl;
}