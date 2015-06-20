/*

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

*/

#include <vector>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

//http://en.wikipedia.org/wiki/Topological_sorting
//O(|V| + |E|) in time
vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) 
{
	vector<int> sortedOrder;
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
		
	while(zeroInDegree.empty() == false)
	{
		int node = zeroInDegree.back();
		zeroInDegree.pop_back();
		
		sortedOrder.push_back(node);
		
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
	
	return (graph.size() == 0)? sortedOrder : vector<int>();
}


bool findOrderIHelper(int node,unordered_map<int,vector<int> >& graph, unordered_set<int>& visited,unordered_set<int>& tmpVisited,vector<int>& sortedOrder)
{	
	if(tmpVisited.find(node) != tmpVisited.end())
		return false;
	
	if(visited.find(node) == visited.end())
	{
		tmpVisited.insert(node);
	
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(findOrderIHelper(graph[node][i],graph,visited,tmpVisited,sortedOrder) == false)
			{
				return false;
			}
		}
	
		visited.insert(node);
		
		tmpVisited.erase(node);
	
		sortedOrder.push_back(node);
	
	}
	
	return true;
}

//DFS
vector<int> findOrderI(int numCourses, vector<pair<int, int> >& prerequisites) 
{
	
	vector<int> sortedOrder;
	unordered_map<int,vector<int> > graph;
	unordered_set<int> visited;
	
	unordered_set<int> tmpVisited;
	
	for(int i = 0; i < prerequisites.size(); i++)
	{
		if(graph.find(prerequisites[i].second) == graph.end())
		{
			graph[prerequisites[i].second] = vector<int>();
		}
		
		graph[prerequisites[i].second].push_back(prerequisites[i].first);
	}
	
	for(int i = 0; i < numCourses; i++)
	{
		if(graph.find(i) == graph.end())
		{
			graph[i] = vector<int>();
		}
	}
	
    for(auto it = graph.begin(); it != graph.end(); it++)
	{
		if(findOrderIHelper(it->first,graph,visited,tmpVisited,sortedOrder) == false)
		{
			return vector<int>();
		}
	}
	
	reverse(sortedOrder.begin(),sortedOrder.end());
	
	return sortedOrder;
			
}

int main()
{
	int n = 3;
	vector<pair<int,int> > pre;
	pre.push_back({1,0});
	pre.push_back({2,1});
	
	vector<int> ret = findOrder(n,pre);
	
	vector<int> ret1 = findOrderI(n,pre);
	
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	
	for(int i = 0; i < ret1.size(); i++)
	{
		cout << ret1[i] << " ";
	}
	cout << endl;

}