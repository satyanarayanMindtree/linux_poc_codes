#include<iostream>
using namespace std;

class A
{
	public:
	virtual void test() {
		cout << "A--test\n";
	}
	int f1(int x)
	{
		return 5*x;
	}
	virtual void f2() { cout << "A--f2\n"; }
	void f3() {   }
};
class B:public A
{
	public:
	void test() {
		cout << "B--test\n";
	}
	int f1(int x)
	{
		return 10*x;
	}
};
int main()
{
	cout << "sizeof A : " << sizeof(A) << endl;
	A a1;
	B b1;
	/*a1.test();
	b1.test();
	cout << a1.f1(6) << endl;
	cout << b1.f1(6) << endl; */
	A *p1,*p2;
	B *p3,*p4;
	/*p1=&a1;
	p1->test();
	p3=&b1;
	p3->test();*/
	
	p2=&b1;
	//p2=p3; //ok
	//p4=&a1; --error
	p2->test();
	cout << p2->f1(6) << endl;

	A& r1=a1;  r1.test();
	B& r2=b1;  r2.test();

	A& r3=b1;  
	r3.test(); //B::test as virtual 
//	cout << r3.f1() << endl; //A::f1 only as not virtual

	return 0;
}
