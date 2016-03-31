#include<iostream>
using namespace std;

class A
{
	int x;
	public:
	A(int p)
	{
		x=p;
	}
	friend class B;
};
class B
{
	public:
	void printx(A& ref)
	{
		cout << "x=" << ref.x << endl;
	}
	void test()
	{
		A at(20);
		cout << at.x << endl;
		at.x++;
	}
};
int main()
{
	A a1(10);
	B b1;
	b1.printx(a1);
	b1.test();
	return 0;
}
