#include<iostream>
using namespace std;

class A;

class B
{
	public:
	void f1() { }
	void printx(A&);
	void test();
};
class A
{
	int x;
	public:
	A(int p)
	{
		x=p;
	}
	friend void B::printx(A&);
	friend void B::test();
};
void B::printx(A& ref)
{
	cout << "x=" << ref.x << endl;
}
void B::test()
{
	A at(20);
	cout << at.x << endl;
	at.x++;
}
int main()
{
	A a1(10);
	B b1;
	b1.printx(a1);
	b1.test();
	return 0;
}
