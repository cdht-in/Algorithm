/*
	
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
	
*/
#include <vector>

using namespace std;

class Queue 
{
	vector<int> st1;
	vector<int> st2;
		
public:
    // Push element x to the back of queue.
    void push(int x) {
		
		while(st2.size())
		{
			st1.push_back(st2.back());
			st2.pop_back();
		}
		
        st1.push_back(x);
		
		while(st1.size())
		{
			st2.push_back(st1.back());
			st1.pop_back();
		}
		
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st2.pop_back();
    }

    // Get the front element.
    int peek(void) {
		return st2.back();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return st2.size() == 0;
    }
};

int main()
{
	
}