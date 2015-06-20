/*
	Implement a MyQueue class which implements a queue using two stacks.	
*/
#include <stack>
#include <iostream>

using namespace std;

struct MyQueue
{
	stack<int> st1;
	stack<int> st2;
	
	void Push(int v)
	{
		st1.push(v);	
	}
	
	int PopFront()
	{
		while(st1.empty() == false)
		{
			st2.push(st1.top());
			st1.pop();
		}
		
		if(st2.empty() == false)
		{
			int v = st2.top();
			st2.pop();
			return v;
		}
		return -1;
	}
	
	bool Empty()
	{
		if(st1.empty() && st2.empty())
			return true;
		return false;
	}
	
};

int main()
{
	MyQueue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(3);
	
	while(q.Empty() == false)
	{
		int v = q.PopFront();
		cout << v << " ";
	}
	cout << endl;
}