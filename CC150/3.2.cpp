/*

	How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.
	
*/
#include <vector>
#include <iostream>

using namespace std;

struct MinStack{
	vector<int> st;
	vector<int> minSt;
	
	void Push(int v)
	{
		st.push_back(v);
		if(minSt.size() == 0 || minSt.back() >= v)
			minSt.push_back(v);
	}
	
	int Pop()
	{
		if(st.size() > 0)
		{
			int v = st.back();
			st.pop_back();
			if(v == minSt.back())
				minSt.pop_back();
			return v;
		}
		return -1;
	}
	
	int Min()
	{
		if(minSt.size() > 0)
			return minSt.back();
		return -1;
	}

};

int main()
{
	MinStack st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Pop();
	st.Pop();
	st.Push(0);
	
	cout << st.Min() << endl;
}