/*
  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

  Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


  The largest rectangle is shown in the shaded area, which has area = 10 unit.

  For example,
  Given height = [2,1,5,6,2,3],
  return 10.
*/

#include <cmath>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

/*
first implementation

// The main function to find the maximum rectangular area under given
// histogram with n bars
int getMaxArea (int hist[], int n)
{
  // Create an empty stack. The stack holds indexes of hist[] array
  // The bars stored in stack are always in increasing order of their
  // heights.
  stack<int> s;
  int max_area = 0; // Initalize max area
  int tp;  // To store top of stack
  int area_with_top; // To store area with top bar as the smallest bar
  // Run through all bars of given histogram
  int i = 0;
  while (i < n) {
    // If this bar is higher than the bar on top stack, push it to stack
    if (s.empty() || hist[s.top()] <= hist[i])
      s.push (i++);
    // If this bar is lower than top of stack, then calculate area of rectangle
    // with stack top as the smallest (or minimum height) bar. 'i' is
    // 'right index' for the top and element before top in stack is 'left index'
    else {
      tp = s.top();  // store the top index
      s.pop();  // pop the top
      // Calculate the area with hist[tp] stack as smallest bar
      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
      printf ("area %d with height %d\n", area_with_top, hist[tp]);
      // update max area, if needed
      if (max_area < area_with_top)
        max_area = area_with_top;
    }
  }
  printf ("==========\n");
  // Now pop the remaining bars from stack and calculate area with every
  // popped bar as the smallest bar
  while (s.empty() == false) {
    tp = s.top();
    s.pop();
    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
    printf ("area %d with height %d\n", area_with_top, hist[tp]);
    if (max_area < area_with_top)
      max_area = area_with_top;
  }
  return max_area;
}

int LargestRectangle1 (int* data, int size)
{
  stack<int> largest;
  int area = 0;
  int i = 0;
  for (i = 0; i < size;) {
    //keep track of when the histogram decrease
    if (largest.empty() || data[i] >= data[largest.top()]) {
      //add those bars to the stack
      largest.push (i);
      i++;
    }
    else {
      int tp = largest.top();
      largest.pop();
      //calculate the rectangle's width
      int width = (largest.empty() ) ? i : i - largest.top() - 1;
      area = max (area, data[tp] * width);
    }
  }
  while (!largest.empty() ) {
    int tp = largest.top();
    largest.pop();
    int width = (largest.empty() ) ? i : i - largest.top() - 1;
    area = max (area, data[tp] * width);
  }
  return area;
}


//this one is not correct
int LargestRectangle (int* data, int size)
{
  //scan once the find the peak in the histograms
  int peak = 0;
  for (int i = 0; i < size; i++) {
    if (data[i] >= data[peak])
      peak = i;
  }
  //start from the peak index, scan to left and right to find the ibiggest rectangles
  int i = peak - 1;
  int j = i + 1;
  int hl = data[peak];
  int hr = data[peak];
  int max = data[peak] * 1;
  while (i >= 0 || j < size) {
    if (i >= 0) {
      hl = std::min (data[i], hl);
      max = std::max (max, hl * (peak - i + 1) );
    }
    if (j < size) {
      hr = std::min (data[j], hr);
      max = std::max (max, hr * (j - peak + 1) );
    }
    max = std::max (max, std::min (hl, hr) * (j - i + 1) );
    i--;
    j++;
  }
  return max;
}


int largestRectangleArea (vector<int>& h)
{
  stack<int> S;
  h.push_back (0);
  int sum = 0;
  for (int i = 0; i < h.size(); i++) {
    if (S.empty() || h[i] > h[S.top()])
      S.push (i);
    else {
      int tmp = S.top();
      S.pop();
      sum = max (sum, h[tmp] * (S.empty() ? i : i - S.top() - 1));
      i--;
    }
  }
  return sum;
}

*/

//second implementation

int largestRectangleArea(vector<int> &height) {
    if(height.size() == 0)
		return 0;
    if(height.size() == 1)
		return height[0];
	
	stack<int> peakIndex;
	int max = 0;
	for(int i = 0; i <= height.size();)
	{
		//this would trigger the last computation when the heights are increasing only, very smart!
		int newHeight = (i == height.size())?  -1 : height[i];
			
		if(peakIndex.empty() || newHeight >= height[peakIndex.top()])
		{
			peakIndex.push(i);
			i++;
		}
		else
		{
			int h = height[peakIndex.top()];
			peakIndex.pop();	
			//NOTE the peakIndex.top
			int w = (peakIndex.empty())? i : i - peakIndex.top() - 1;
			int area = w * h;
			max = (max > area)? max : area;
		}
	}
	
	return max;
}


	
	
int main()
{
  int foo[] = {2,1,2};
  vector<int> height(foo,foo + sizeof(foo ) / sizeof(int));
  cout << largestRectangleArea (height) << endl;
}
