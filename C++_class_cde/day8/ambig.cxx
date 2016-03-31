#include<iostream>
using namespace std;


class A
{
	int x;
	public:
	void setx(int p)
	{
		x=p;
	}
	void print() {
		cout << "x=" << x << endl;
	}
	void f1() { 
		cout << "A--f1\n";
	}
	void f2() {
		cout << "A--f2\n";
	}
};
class B:public A
{
	int y;
	public:
	void setxy(int p,int q)
	{
		setx(p);
		y=q;
	}
	void print()
	{
		//print() - calls from B, infinite recursion
		A::print();
		cout << "y=" << y << endl;
	}
	void f1() {
		cout << "B--f1\n";
	}
};
int main()
{
	A a1;
	a1.f1();

	B b1;
	b1.f1();	//B
	b1.f2();	//A
	b1.A::f1();	//A

	return 0;
}







