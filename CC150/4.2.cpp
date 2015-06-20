/*
	
	Given a directed graph, design an algorithm to find out whether there is a route between two nodes.	
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;


struct Node
{
	int v;
	bool visited;
	vector<Node*> neightbors;
};

//BFS from node1 to see if it can reach node2
bool IsRoute(Node* node1, Node* node2)
{
	queue<Node*> q;
	q.push(node1);
	
	while(q.empty() == false)
	{
		Node* node = q.front();
		q.pop();
		node->visited = true;
		
		if(node == node2)
			return true;
		
		for(int i = 0; i < node->neightbors.size(); i++)
		{
			if(node->neightbors[i]->visited == false)
				q.push(node->neightbors[i]);
		}
	}
	
	return false;
}

int main()
{
	Node node1;
	Node node2;
	Node node3;
	node1.neightbors.push_back(&node2);
	node3.neightbors.push_back(&node2);
	
	cout << IsRoute(&node1,&node3) << endl;
}