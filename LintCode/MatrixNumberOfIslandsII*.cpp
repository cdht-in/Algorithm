/*
	
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.

Have you met this question in a real interview? Yes
Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].

Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
	
*/

#include "../commonHeader.h"

struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct DisjointSetNode
{
	int rank;
	int x;
	int y;
	DisjointSetNode* parent;
	DisjointSetNode(int x, int y, DisjointSetNode* parent,int rank):rank(rank),x(x),y(y),parent(parent){}
	DisjointSetNode():rank(),x(),y(),parent(){}
};

class DisjointForest
{
	vector<DisjointSetNode*> forest;
	
	DisjointSetNode* Find(DisjointSetNode* node)
	{
		if(node == 0)
			return node;
		
		while(node->parent != node)
		{
			node = node->parent;
		}
		return node;
	}
	
	DisjointSetNode* MakeSet(int x, int y)
	{
		 DisjointSetNode* node = new DisjointSetNode(x,y,0,0);
		 node->parent = node;
		 return node;
	}
	
	void Union(DisjointSetNode* node1,DisjointSetNode* node2)
	{
		
	}
	
public:
	
	DisjointForest()
	{		
	}
	
	void Add(int x, int y)
	{
		DisjointSetNode* node = MakeSet(x,y);
		
		if(forest.size() == 0)
		{
			forest.push_back(node);
			return;
		}
		
		vector<DisjointSetNode*> newForest;
		//merge the forest
		for(int i = 0; i < forest.size(); i++)
		{
			DisjointSetNode* parent1 = Find(forest[i]);
			DisjointSetNode* parent2 = Find(node);				
		}
	}
		
};

int find(int x, vector<int> &parent) 
{
           int r = x, y = x;
		   
		   //find the root
           while (r != parent[r]) 
		   {
                   r = parent[r];
           }
		   
		   //path compression
           while (y != r)
		   {
                   int temp = parent[y];
                   parent[y] = r;
                   y = temp;
           }
           return r;
}

void merge(int x, int y, vector<int> &bin) 
{
        int fx = find(x, bin), fy = find(y, bin);
		//could have done the rank optimization here as well
        if (fx != fy) 
			bin[fx] = fy;
}

vector<int> numIslands2(int n, int m, vector<Point>& operators) 
{
    vector<int> parent(m * n, -1);
    vector<int> res(operators.size());
    int cur = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
	
    for (int i = 0; i < operators.size(); i ++) 
	{
		int x = operators[i].x, y = operators[i].y, temp = x * m + y;
		if (parent[temp] != -1) 
			continue;
		
		//make its parent to be itself
		parent[temp] = temp;
		set<int> forest;
		
		for (int j = 0; j < 4; j++)
		{
		        int x1 = x + dx[j], y1 = y + dy[j], t = x1 * m + y1;
				
		        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && parent[t] != -1) 
				{
					//find the cluster
		                int cnt = find(t, parent);
						
		                if(forest.find(cnt) == forest.end()) 
							forest.insert(cnt);
		        }
		}
		
        for (int j = 0; j < 4; j ++) 
		{
            int x1 = x + dx[j], y1 = y + dy[j], t = x1 * m + y1;
			
			//merge with four neighbors
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && parent[t] != -1)
			{
                merge(t, temp, parent);
            }
        }
		
		//this line is beyond description, genius
        cur += 1 - forest.size();
		
		res[i] = cur;
    }
	
    return res;
}

int main()
{
	
}