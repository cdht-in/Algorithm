/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
#include <unordered_set>
#include <vector>
#include <cstdint>
#include <queue>
#include <map>

using namespace std;

struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* cloneGraphHelper(UndirectedGraphNode* node,map<int64_t,UndirectedGraphNode*>& visited)
{
	if(node->neighbors.size() == 0)
	{
		UndirectedGraphNode* leafNode = new UndirectedGraphNode(node->label);
		//map it to its clone
		visited[(int64_t)node] = leafNode;
		return leafNode;
	}
	
	UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
	visited[(int64_t)node] = newNode;
	
	for(int i = 0; i < node->neighbors.size(); i++)
	{
		UndirectedGraphNode* neighborNode = 0;
		if(visited.find((int64_t)node->neighbors[i]) != visited.end())
		{
			neighborNode = visited[(int64_t)node->neighbors[i]];
		}
		else
		{
			neighborNode = cloneGraphHelper(node->neighbors[i],visited);
		}
		
		newNode->neighbors.push_back(neighborNode);
	}
	
	return newNode;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(node == 0)
		return node;
	
	map<int64_t,UndirectedGraphNode* > visited;
		
	return cloneGraphHelper(node,visited);
}

int main(){
	
	
}