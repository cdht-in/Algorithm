/*
  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

  Note: You may not slant the container.

*/
#include <vector>

using namespace std;

//O(n^2)
int maxArea (vector<int>& height)
{
  if (height.size() < 2)
    return 0;
  int max = 0;
  int w = 0;
  int h = 0;
  for (int i = 0; i < height.size(); i++) {
    h = height[i];
    for (int j = i + 1; j < height.size(); j++) {
      if (height[j] < height[i]) {
        h = height[j];
      }
      w = j - i;
    }
    int area = w * h;
    if (area > max)
      max = area;
  }
  return max;
}

//O(n) in time
int min(int a, int b){
  return (a < b)? a : b;
}

int maxArea1 (vector<int>& height)
{
  if (height.size() < 1)
    return 0;
  int l = 0;
  int r = height.size() - 1;
  int max = 0;
  while(l < r)
    {
      int area = (r - l) * min(height[l],height[r]);
      if(area > max)
	max = area;
      if(height[l] < height[r])
	l++;
      else
	r--;
    }
  return max;
}


int main()
{
}
