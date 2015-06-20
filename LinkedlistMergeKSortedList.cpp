/*
	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

#include <vector>
#include <queue>

using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (ListNode* l, ListNode* r) const
  {
    if (reverse) return (l->val > r->val);
    else return (l->val > r->val);
  }
};


//O(n space) and O(n * k log(k) time
ListNode *mergeKLists(vector<ListNode *> &lists) {
	
	priority_queue<int, vector<int>, greater<int> > q;
	
	for(int i = 0; i < lists.size(); i++)
	{
		ListNode* node = lists[i];
		while(node)
		{
			q.push(node->val);
			node = node->next;
		}
	}

	if(q.empty())
		return 0;
	
	ListNode* head = new ListNode(q.top());
	q.pop();
	ListNode* p = head;
	while(q.empty() == false)
	{
		p->next = new ListNode(q.top());
		q.pop();
		p = p->next;
	}
	return head;
}

//merge sort approach will be added later
//http://blog.csdn.net/linhuanmars/article/details/19899259

int main()
{
	
	
}