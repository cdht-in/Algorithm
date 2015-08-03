#include <cassert>

struct Node
{
	int val;
	int row;
	int col;
	Node():val(),row(),col(){}
	Node(int val, int row, int col):val(val),row(row),col(col){}
};

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (const Node& lhs, const Node&rhs) const
  {
    if (reverse) return (lhs.val > rhs.val);
    else return (lhs.val < rhs.val);
  }
};

class Solution {
public:

    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        assert(matrix.size() > 0);
		
	priority_queue<Node,vector<Node>,mycomparison> q;
	for(int i = 0; i < matrix[0].size(); i++)
	{
		q.push(Node(matrix[0][i],0,i));
	}
	
	Node node;
	for(int i = 0; i < k; i++)
	{
		node = q.top();
		q.pop();
		
		if(node.row + 1 < matrix.size())
		{
			q.push(Node(matrix[node.row + 1][node.col],node.row + 1, node.col));
		}
		else
			q.push(Node(INT_MAX,0,0));
	}
	
	return node.val;
    }
};
