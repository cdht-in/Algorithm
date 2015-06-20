/*

  Question: Queue Using Stacks

  Describe a queue data structure that is implemented using one or more stacks.  

  Don't worry about running time.  Write the enqueue and dequeue operations for the 

  queue.  You may use any language you like.

*/

#include <stack>
#include <cstdio>

//using two stacks
class queue{

  std::stack<int> foo;
  std::stack<int> bar;
  
public:
  void enqueue(int x){
    foo.push(x);
  }

  int dequeue(){
    while(!foo.empty()){
      bar.push(foo.top());
      foo.pop();
    }
    int result = bar.top();
    bar.pop();
    return result;
  }
};

int main(){
  queue q;
  for(int i=0;i<5;i++){
    q.enqueue(i);
  }
  for(int i=0;i<5;i++){
    printf("%d ",q.dequeue());
  }
  printf("\n");
  
}
