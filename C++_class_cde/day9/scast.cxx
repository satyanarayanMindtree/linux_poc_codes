#include<iostream>
using namespace std;

class A
{
	int x;
	public:
	A(int p) { x=p; }
	virtual void test() {
		cout << "A--test,x=" << x << "\n";
	}
	int getx() { return x; }
	void f1() { cout << "A,x=" << x << endl; }
};
class B:public A
{
	int y;
	public:
	B(int p,int q):A(p) { y=q; }
	void test() {
		cout << "B--test,x=" << getx() << ",y=" << y << endl;
	}
	void f1() { cout << "B,x=" << getx() << ",y=" << y << endl; }
};
int main()
{
	A a1(10);
	B b1(11,21);

	A *p1,*p2;
	p1=&a1;
	p2=&b1;
	p1->test();
	p2->test();

	B* p3;
	p3=static_cast<B*>(p2);
	cout << &b1 << "," << p3 << endl;
	p3->test();

	p3=static_cast<B*>(p1);
	cout << &a1 << "," << p3 << endl;
	p3->test();
	p3->f1();

	
	enum day { sun=1,mon,tue,wed,thu,fri,sat};
	day d1;
	int x;

	d1=mon;
	x=d1;
	cout << "x=" << x << endl;

	x=5;
	//d1=x; -error
	d1=static_cast<day>(x);
	cout << "d1=" << d1 << endl;

	return 0;
}
