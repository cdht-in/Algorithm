/*
	
Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)

Have you met this question in a real interview? Yes
Example
Given graph:

A----->B  C
 \     |  | 
  \    |  |
   \   |  |
    \  v  v
     ->D  E <- F
Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}

Note
Sort the element in the set in increasing order
	
*/
#include "../commonHeader.h"

struct DirectedGraphNode 
{
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};


/*

//doesn't work
vector<vector<int> > connectedSet2(vector<DirectedGraphNode*>& nodes) 
{
	//first build the graph of incoming edges
	unordered_map<DirectedGraphNode*,vector<DirectedGraphNode*> > inComingEdges;
	
	for(auto node : nodes)
	{
		for(auto neighbor : node->neighbors)
		{
			if(inComingEdges.find(neighbor) == inComingEdges.end())
			{
				inComingEdges[neighbor] = vector<DirectedGraphNode*>();
			}
			inComingEdges[neighbor].push_back(node);
		}
	}
	
	//start with the nodes has only incoming edges
	vector<DirectedGraphNode*> inComingNodes;
	for(auto node : nodes)
	{
		if(node->neighbors.size() == 0)
		{
			inComingNodes.push_back(node);
		}
	}
	
	vector<vector<int> > sets;
	unordered_set<DirectedGraphNode*> visited;
	
	for(auto node : inComingNodes)
	{
		queue<DirectedGraphNode*> q;
		q.push(node);
		sets.push_back(vector<int>());
		
		while(q.empty() == false)
		{
			DirectedGraphNode* head = q.front();
			q.pop();
			visited.insert(head);
			
			sets.back().push_back(head->label);
			for(auto incomingNode : inComingEdges[head])
			{
				if(visited.find(incomingNode) == visited.end())
				{
					q.push(incomingNode);
					visited.insert(incomingNode);
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
*/


int find(unordered_map<int, int> &father, int x) {
    if (father.find(x) == father.end()) 
	{
        father[x] = x;
        return x;
    }
	
    while (x != father[x]) 
		x = father[x];
	
    return x;
}

vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) 
{	
    unordered_map<int, int> father;
    int fa, fb, fn;
    for (auto &n : nodes) 
	{
        for (auto &nn : n->neighbors) 
		{
            fa = find(father, n->label);
            fb = find(father, nn->label);
			//if fa and fb are not in the same union
            if (fa != fb) 
			{
				//union
                if (fa > fb)
					father[fa] = fb;
                else
					father[fb] = fa;
            }
        }
    }
	
    unordered_map<int, vector<int>> comp;
    for (auto &n : nodes) 
	{
        fn = find(father, n->label);
        comp[fn].push_back(n->label);
    }
	
    vector<vector<int>> res;
    for (auto &c : comp) 
	{
        sort(c.second.begin(), c.second.end());
        res.push_back(c.second);
    }
    return res;
}


int main()
{	
	vector<DirectedGraphNode*> nodes;
	DirectedGraphNode A(1);
	DirectedGraphNode B(2);
	DirectedGraphNode C(3);
	DirectedGraphNode D(4);
	DirectedGraphNode E(5);
	DirectedGraphNode F(6);
	
	A.neighbors.push_back(&B);
	A.neighbors.push_back(&D);
	B.neighbors.push_back(&D);
	
	C.neighbors.push_back(&E);
	F.neighbors.push_back(&E);
	
	nodes.push_back(&A);
	nodes.push_back(&B);
	nodes.push_back(&C);
	nodes.push_back(&D);
	nodes.push_back(&E);
	nodes.push_back(&F);
	
	vector<vector<int> > sets = connectedSet2(nodes);
	for(auto set : sets)
	{
		for(auto label : set)
		{
			cout << label << " ";
		}
		cout << endl;
	}
}