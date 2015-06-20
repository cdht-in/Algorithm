/*
  Merge k sorted arrays | Set 1
  July 29, 2013
  Given k sorted arrays of size n each, merge them and print the sorted output.

  Example:

  Input:
  k = 3, n =  4
  arr[][] = { {1, 3, 5, 7},
  {2, 4, 6, 8},
  {0, 9, 10, 11}} ;

  Output: 0 1 2 3 4 5 6 7 8 9 10 11
*/
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

struct HeapNode {
  //indicate where index of element in each array currently being compared at the heap
  vector<int>::iterator i;
  vector<int>::iterator end;
  HeapNode (vector<int>& vec) {
    i = vec.begin();
    end = vec.end();
  }
};

class Compare {
  bool reverse;
public:
  Compare (const bool& revparam = false) {
    reverse = revparam;
  }
  bool operator() (const HeapNode* lhs, const HeapNode* rhs) const {
    //ascending order
    if (reverse)
      return (* (lhs->i) > * (rhs->i) );
    //descending order
    else
      return (* (lhs->i) < * (rhs->i) );;
  }
};


//O(nklog(k)), where log(k) is for each heapify, and nk is for the size of all elements
vector<int>* MergeArray (priority_queue<HeapNode*, vector<HeapNode*>, Compare>* pq)
{
  vector<int>* vec = new vector<int>;
  while (!pq->empty() ) {
    HeapNode* node = pq->top();
    pq->pop();
    //push in the value
    vec->push_back (* (node->i) );
    (node->i) ++;
    //if there elements, push the vector back
    if (node->i != node->end)
      pq->push (node);
  }
  return vec;
}

int main()
{
  vector<int> a ( {1, 4, 7, 8, 9});
  vector<int> b ( {2, 3, 9, 10, 15});
  vector<int> c ( {4, 5, 7, 12, 13, 14});
  HeapNode anode (a);
  HeapNode bnode (b);
  HeapNode cnode (c);
  priority_queue<HeapNode*, vector<HeapNode*>, Compare> pq (Compare (true) );
  //init the pq with the head of each vector
  pq.push (&anode);
  pq.push (&bnode);
  pq.push (&cnode);
  vector<int>* array = MergeArray (&pq);
  for (int i = 0; i < array->size(); i++)
    printf ("%d ", array->at (i) );
  printf ("\n");
}

