#include<iostream>
using namespace std;

class A
{
	int x;
	public:
	A(int p)
	{
		x=p*10;
	}
	void printx()
	{
		cout << "x=" << x << endl;
	}
	A& operator=(int val)//more pref than A(int) during
			     //conversions
	{
		x=val+5;
		return *this;
	}
	operator int()
	{
		return x;
	}
};
//constructor with 1 param can also be used for conversion
//from param type to class type
int main()
{
	A a1(10); //A a1=10;
	a1.printx();
	a1=12; //A(int) or a1.operator=(12);
	a1.printx();

	int y;
	y=a1; //y=int(a1)
	cout << "y=" << y << endl;

	return 0;
}
