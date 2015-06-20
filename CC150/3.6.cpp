/*
	Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.

*/

#include <stack>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

//O(n) in best time when the s is already sorted, and O(n^2) when
stack<int> SortStack(stack<int>& s)
{
    stack<int> t;
    while(s.empty() == false)
	{
        int data = s.top();
        s.pop();
		
		cout << data << endl;
		
        while(t.empty() == false && t.top() < data)
		{
            s.push(t.top());
            t.pop();
        }
		
        t.push(data);
    }
	
    return t;
}

void Qsort(stack<int> &s){
    priority_queue< int,vector<int>,greater<int> > q;
    while(!s.empty())
	{
        q.push(s.top());
        s.pop();
    }
	
    while(!q.empty())
	{
        s.push(q.top());
        q.pop();
    }
}

int main()
{
	srand((unsigned)time(0));
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	/*
	for(int i = 0; i < 5; ++i)
	    s.push((rand() % 100));
	*/
	s = SortStack(s);
	
	while(s.empty() == false)
	{
	    cout<< s.top() << " ";
	    s.pop();
	}
	
	cout << endl;
	
}