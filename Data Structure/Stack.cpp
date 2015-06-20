#include <queue>

using namespace std;

//naive implementation
class Stack 
{
	queue<int> q1;
	queue<int> q2;
	int size;
	
public:
	
	Stack()
	{
		size = 0;
	}
	
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
		size++;
    }

    // Removes the element on top of the stack.
    void pop() {
		if(empty())
			return;
			
		for(int i = 0; i < size - 1; i++)
		{
			int v = q1.front();
			q1.pop();
			q1.push(v);
		}
		
		q1.pop();
		size--;
    }

    // Get the top element.
    int top() {
		
		if(empty())
			throw "empty";
		
		for(int i = 0; i < size - 1; i++)
		{
			int v = q1.front();
			q1.pop();
			q1.push(v);
		}
		
		int v = q1.front();
		q1.pop();
		q1.push(v);
		return v;
    }

    // Return whether the stack is empty.
    bool empty() {
        return size <= 0;
    }
};

int main()
{
	
}