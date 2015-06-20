/*
	
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one rod onto the next rod.
A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//with recursion
void Hanoi(int n, char src, char intermediate, char dst)
{
	if(n == 1)
	{
	    cout << "Move disk " << n << " from " << src << " to " << dst << endl;
	}
	else
	{
	    Hanoi(n - 1, src, dst, intermediate);
	    cout << "Move disk "<< n <<" from "<< src <<" to "<< dst << endl;
	    Hanoi(n - 1, intermediate, src, dst);
	}
}

//with stack
struct op
{	
    int begin, end;
    char src, intermediate, dst;
	
    op()
	{

    }
	
    op(int pbegin, int pend, int psrc, int pintermediate, int pdst):begin(pbegin), end(pend), src(psrc), 	intermediate(pintermediate), dst(pdst){}
};

void HanoiWithStack(int n, char src, char intermediate, char dst){
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, intermediate, dst));
	
    while(st.empty() == false)
	{
        tmp = st.top();
        st.pop();
		
        if(tmp.begin != tmp.end)
		{
            st.push(op(tmp.begin, tmp.end - 1, tmp.intermediate, tmp.src, tmp.dst));
			
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.intermediate, tmp.dst));
			
            st.push(op(tmp.begin, tmp.end - 1, tmp.src, tmp.dst, tmp.intermediate));
        }
        else
		{
            cout << "Move disk " << tmp.begin << " from " << tmp.src << " to " << tmp.dst << endl;
        }

    }
}

int main()
{
	HanoiWithStack(2,'A','B','C');
}