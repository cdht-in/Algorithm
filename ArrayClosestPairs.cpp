#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

#define x first
#define y second

typedef pair<int,int> Point;

void PrintPoints(const vector<Point>& points)
{
	for(int i = 0; i < points.size(); i++)
	{
		cout << "("<<points[i].x << "," << points[i].y << ")"<< endl;
	}	
}

inline double dist(Point p1, Point p2)
{
    return sqrt((double) (p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x));
}

ostream& operator<<(ostream& out, Point point)
{
	cout << "(" << point.x << "," << point.y << ")" << endl;
	return cout;
}

bool operator==(Point a,Point b)
{
	return (a.x == b.x) && (a.y == b.y);
}

//O(n^2)
void NaiveClosePair(vector<Point > points)
{
	double min = INT_MAX;
	Point a;
	Point b;
	for(int i = 0; i < points.size(); i++)
	{
		for(int j = i + 1; j < points.size(); j++)
		{
			if(points[i] == points[j])
				continue;
			
			double distance = dist(points[i],points[j]);
			if(distance < min)
			{
				a = points[i];
				b = points[j];
				min = distance;
			}
		}
	}
	cout << "min is at " << min << " from NaiveClosePair" << endl;
	cout << a;
	cout << b;
}

//O(nlogn)
void ClosePair(vector<Point > points)
{
	sort(points.begin(),points.end());
	//PrintPoints(points);
	
    double min = INT_MAX;
	
	//Bounding box maintained by y-coordinate
    set <Point > boundingBox;
	
    boundingBox.insert(points[0]);
    int left = 0;
    Point best1, best2;

    for (int i = 1; i < points.size(); i++)
    {
        //Maintain only points to the left of the current point whose distance is less than bestDist
        while ((left < i) && (points[i].x - points[left].x > min))
        {
            boundingBox.erase(points[left]);
            left++;
        }
		
		//skip the duplicates
		if(boundingBox.find(points[i]) != boundingBox.end())
			continue;

        //Consider only points within bestDist of the current point
		//at most 6 points at this loop O(1) time
        for (auto it = boundingBox.lower_bound(make_pair(points[i].x - min, points[i].y - min));
             it != boundingBox.end() && it->y <= points[i].y + min; it++)
        {
            if (dist(*it, points[i]) < min)
            {
                min = dist(*it, points[i]);
                best1 = *it;
                best2 = points[i];
            }
        }

        boundingBox.insert(points[i]);
    }
	
	cout << "closest pairs are:" << endl;
	cout << best1 << best2 << min << endl;
	
}

int main()
{
	int n = 100000;
	vector<Point > points;
	
	for(int i = 0; i < n; i++)
	{
		points.push_back(make_pair<int,int>(rand() % n, rand() % n));
	}
	
	int t0 = time(0);
	ClosePair(points);
	int t1 = time(0);
	cout << "line sweep took " << t1 - t0 << " seconds" << endl;
	
	t0 = time(0);
	NaiveClosePair(points);	
	t1 = time(0);
	cout << "navie took " << t1 - t0 << " seconds" << endl;
	
}