#include<iostream>
using namespace std;
class A
{
	int x;
	public:
	A(int m=5)
	{
		cout << "A ctor\n";
		x=m;
	}
	~A() { cout << "A dtor\n"; }
	void printx()
	{
		cout << "x=" << x << endl;
	}
	void f1() {}
};
class B
{
	int y;
	public:
	B(int n)
	{
		cout << "B ctor\n";
		y=n;
	}
	~B() { cout << "B dtor\n"; }
	void printy()
	{
		cout << "y=" << y << endl;
	}
	void f1() { }
};
class C:public B,public A
{
	int z;
	public:
	C(int p,int q,int r):A(p),B(q)
	{
		cout << "C ctor\n";
		z=r;
	}
	~C() { cout << "C dtor\n"; }
	void printxyz()
	{
		printx();
		printy();
		cout << "z=" << z << endl;
	}
};
int main()
{
	C c1(11,12,13);
	c1.printxyz();

	//c1.f1(); --ambiguous
	c1.A::f1();
	c1.B::f1();

	return 0;
}






