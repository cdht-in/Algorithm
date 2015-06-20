/*
  Write a function to remove a single occurrence of an integer from a doubly linked list if it is present.  You may use any language you like
*/

#include <cstdio>
#include <list>

//return 1 if presented and removed, return 0 if not presented
int RemoveInteger(std::list<int> list, int i){

for(std::list<int>::iterator itr = list.begin();itr!=list.end();itr++){
  if(*itr == i){
    list.remove(i);
    return 1;
  }
 }
return 0;
}

int main(){
  int foo[] = {1,2,3,4,5};
  //iterator constructor, indicating the end
  std::list<int> bar(foo,foo + sizeof(foo) / sizeof(int));
  printf("%d\n",RemoveInteger(bar,2));
  return 0;
}
