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
};
class B:public A
{
	int y;
	public:
	//in absence of A(p) in initializer list, default ctor
	//of class A will be invoked
	B(int p,int q):A(p)
	{
		cout << "B ctor\n";
		//x=p; -error
		y=q;
	}
	~B() { cout << "B dtor\n"; }
	void printxy()
	{
		printx();
		cout << "y=" << y << endl;
	}
};
class C:public B
{
	int z;
	public:
	C(int p,int q,int r):B(p,q)
	{
		cout << "C ctor\n";
		z=r;
	}
	~C() { cout << "C dtor\n"; }
	void printxyz()
	{
		//can call printx() also
		printxy();
		cout << "z=" << z << endl;
	}
};
int main()
{
	//B b1(10,20);
	//b1.printxy();

	C c1(11,12,13);
	c1.printxyz();
	return 0;
}






