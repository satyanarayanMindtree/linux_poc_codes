#include<iostream>
using namespace std;
class A
{
	int x;
	protected:
	int y;
	void f2() {
		cout << "A--f2--protected\n";
	}
	public:
	void f1() {
		cout << "A--f1--public\n";
	}
};
class B:protected A
{
	public:
	void test() {
		y++;
		f2();
	}
};
class C:public B
{
	public:
	void test() {
		y--;
		f1();
		f2();
	}
};
void fun()
{
	A a1;
	//a1.f2();
}
int main()
{
/*	//fun();

	A a1;
	a1.f1();

	B b1;
	//b1.test();
	b1.f1();
	b1.f2();

	//C c1;
	//c1.test();*/
	return 0;
}
