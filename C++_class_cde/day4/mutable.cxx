#include<iostream>
using namespace std;

class A
{
	int x;
	mutable int y;
	public:
	A(int p,int q)
	{
		x=p;y=q;
	}
	//A() { x=0; }
	void print() const  //void print(const A* this)
	{
		//x++; --error
		y++;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
	void test(int z) const //void test(const A* this,int z)
	{
		//x=15; //--error
		y=25;
	}
};

int main()
{
	return 0;
}
