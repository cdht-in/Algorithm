/*

Suppose we are given S rectangles on 2 dimensional space:
1) each one is specified x1, y1, x2, y2  
2) calculate the area covered by these S rectangles.

*/

#include <vector>

using namespace std;

struct Rectangle
{
	int x1;
	int y1;
	int x2;
	int y2;

	Rectangle(int x1, int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){};
};


bool IsOverLapped(const Rectangle& a, const Rectangle& b)
{
	//assume a and b are sortted according to its top right corner;
	
}

int main()
{
	
	
}