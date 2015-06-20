/*
	
	Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
	//slope to count map
	unordered_map<float,int> map;
	int max = 0;
	
	for(int i = 0; i < points.size(); i++)
	{
		map.clear();
		
		//in case if all points in points are the same
		map[INT_MIN] = 0;
		
		//indicate point[i];
		int dup = 1;
		
		for(int j = i + 1; j < points.size(); j++)
		{
			//same point as point[i]
			if(points[j].x == points[i].x && points[j].y == points[i].y)
			{
				dup++;
				continue;
			}
				
			//the key is that if A and B and A and C have the same slope, then it means that A,B and C are in the same line
			//NOTE that if points[j].x == points[i].x, that means the line is prependicular to the x axis and the slope is MAXIMUM
			float slope = (points[j].x == points[i].x)? INT_MAX : ((float)(points[j].y - points[i].y) / (points[j].x - points[i].x));
			
			//point[i] and point[j] are on the same line, this could be shortened to map[slope]++, but it was kept this way for clarity
			if(map.find(slope) == map.end())
				map[slope] = 1;
			else
				map[slope]++;
		}
		
		//now calculate how many points are in each line, adding the the number of times of the starting point A
		for(auto it = map.begin(); it != map.end(); it++)
		{
			if(it->second + dup > max)
				max = it->second + dup;
		}
	}
	
	return max;
}

int main()
{
	
}