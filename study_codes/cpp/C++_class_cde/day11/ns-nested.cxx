#include<iostream>
using namespace std;

namespace n1
{
	int a=10,b=20;
	namespace na
	{
		int x=10;
		int y=12;
	}
	namespace nb
	{
		int x=20;
		int z=18;
	}

}

using namespace n1;    //only direct members of n1(a,b) are added
using namespace n1::na;//now x,y are added from sub namespace

int main()
{
	cout << "y=" << n1::na::y << endl;
	cout << "z=" << n1::nb::z << endl;
	cout << "na's x=" << n1::na::x << endl;
	cout << "a=" << n1::a << endl;
	cout << "b=" << n1::b << endl;

	y++;
	//z++; --error
	a++; b=15;


	return 0;
}
