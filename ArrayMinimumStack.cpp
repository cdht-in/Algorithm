/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/
#include <vector>
#include <climits>

using namespace std;

class MinStack {
	vector<int> minStack;
	vector<int> stack;
	
public:
    void push(int x) {
    	stack.push_back(x);
		if(minStack.size() < 1 || minStack.back() >= x)
			minStack.push_back(x);
    }

    void pop() {
		if(stack.size() < 1)
			return;
		if(stack[stack.size() - 1] == minStack.back())
			minStack.erase(minStack.begin() + minStack.size() - 1);
        stack.erase(stack.begin() + stack.size() - 1);
    }

    int top() {
		if(stack.size() < 1)
			return 0;
        return stack.back();
    }

    int getMin() {
 		return minStack.back();
    }
};

int main(){
	
	
	
}