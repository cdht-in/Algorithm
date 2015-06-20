/*
  Describe a stack data structure that supports "push", "pop", and "find minimum" operations.  "Find minimum" returns the smallest element in the stack.
  
*/

/*
  two stacks, one to store all elements, one to store all the minima
*/

#include <cstdio>
#include <cstring>
#include <stack>

class MinStack{
  std::stack<int> data;
  std::stack<int> minima;

public:
  MinStack(int* input, int size){
    for(int i=0;i<size;i++){
      push(input[i]);
    }
  }
  
  void push(int x){
    data.push(x);
    if(minima.size() > 0){
      if(x < minima.top())
	minima.push(x);
    }
    else
      minima.push(x);
  }

  //if the top being poped is the minimal, pop it off the minimal stack as well
  int pop(){
    if(data.size() > 0){
      int top = data.top();
      data.pop();
      if(top == minima.top())
	minima.pop();
      return top;
    }
    return -1;
  }

  int FindMin(){
    return (minima.size() > 0)? minima.top():999;
  }
	   
};

int main(){
  int foo[] = {3,2,1};
  MinStack bar(foo,3);
  bar.push(4);
  bar.pop();
  bar.push(5);
  bar.push(0);
  bar.pop();
  
  printf("min is %d\n",bar.FindMin());
  
}
