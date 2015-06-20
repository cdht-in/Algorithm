/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

*/
#include <vector>
#include <iostream>

using namespace std;

class StackOfPlates
{
	int p;
	int c;
	vector<vector<int> > sts;
	
public:
	
	StackOfPlates(int capacity): c(capacity),p(-1){}
	
	void Push(int v)
	{
		if(sts.size() == 0 || sts[p].size() == c)
		{
			sts.push_back(vector<int>());
			p++;
		}
		sts[p].push_back(v);
	}
	
	int Pop()
	{
		if(p == -1)
		{
			return -1;
		}
		
		int v = sts[p].back();
		sts[p].pop_back();
		
		if(sts[p].size() == 0)
		{
			sts.pop_back();
			p--;
		}
		
		return v;
	}
	
	int PopAt(int index)
	{
		if(index < 0 || index > p)
			return -1;
		
		int v = sts[index].back();
		sts[index].pop_back();
		
		if(sts[index].size() == 0)
		{
			sts.erase(sts.begin() + index);
			if(index == p)
				p--;
		}
			
		return v;
	}
	
};


int main()
{
	StackOfPlates st(2);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	
	cout << st.PopAt(0) << endl;
	cout << st.Pop() << endl;
	cout << st.Pop() << endl;
	
	st.Push(3);
	cout << st.Pop() << endl;
}