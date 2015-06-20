/*
  Write an algorithm that take a list of n words, and an integer m, and retrieves the mth most frequent word in that list.
*/

#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <vector>

/*
  idea is that first get the count of each words, each quick select on that count O(n), currently using char instead of a whole word, but it wouldn't be different in principle for a whole word
*/

struct CompareObject {
private:
  bool reverse;
public:
  CompareObject (const bool& f = false) : reverse (f) {}
  bool operator() (const std::pair<char, int>& l, const std::pair<char, int>& r) {
    if (reverse)
      return l.second > r.second;
    return l.second < r.second;
  }
};

int Compare (const void* a, const void* b)
{
  return * ( (char*) a) > * ( (char*) b);
}

void nthFrequent (char* data, int size, int k)
{
  //hashmap to get the frequency of each word
  std::unordered_map<char, int> map;
  //heap to extract the top k frequencies
  std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int> >, CompareObject> pq (CompareObject (false) );
  //get the count O(n)
  for (int i = 0; i < size; i++) {
    if (map.find (data[i]) == map.end() )
      map[data[i]] = 0;
    else
      map[data[i]]++;
  }
  typedef std::unordered_map<char, int>::const_iterator seti;
  //now pump those frequency into a heap O(n) to construct the heap
  for (seti i = map.begin(); i != map.end(); i++)
    pq.push (std::pair<char, int> (i->first, i->second) );
  //now extract the the top k with the highest frequency
  for (int i = 0; i < k; i++) {
    std::cout << pq.top().first << " : " << pq.top().second << std::endl;
    pq.pop();
  }
  //so the overall is O(n + klogn)
}


int main()
{
  char foo[] = {'a', 'b', 'c', 'b', 'e', 'z'};
  int size = sizeof (foo) / sizeof (char);
  nthFrequent (foo, size, 2);
}
