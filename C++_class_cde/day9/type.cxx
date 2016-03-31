#include<iostream>
#include<typeinfo>
#include<cstdio>
using namespace std;

class A
{
	public:
	virtual void test() {
		cout << "A--test\n";
	}
	void f3() {   }
};
class B:public A
{
	public:
	void test() {
		cout << "B--test\n";
	}
};
int main()
{
	cout << "sizeof A : " << sizeof(A) << endl;
	A a1;
	B b1;
	A* ptr;
	
	ptr=&b1;
	int x;
	cout << "type of x:" << typeid(x).name() << endl;	
	cout << "type of a1:" << typeid(a1).name() << endl;
	cout << "type of b1:" << typeid(b1).name() << endl;
	cout << "type of ptr:" << typeid(ptr).name() << endl;
	cout << "type of *ptr:" << typeid(*ptr).name() << endl;

	A *p1,*p2;
	B *p3,*p4;

	p1=&a1;
	p3=&b1;

	//p1=p3;
	//p1=dynamic_cast<A*>(&b1); 
	p1=dynamic_cast<A*>(p3);
	cout << "p1=" << p1 << endl;


	//p2=&a1; 
	p2=&b1;
	//p4=p2; --error
	p4=dynamic_cast<B*>(p2); //null if p2=&a1, 
				 //else(p2=&b1) actual addr
	cout << "p4=" << p4 << endl;
	if(p4!=NULL)
		p4->test();

	p4=dynamic_cast<B*>(&a1); //p4 is always null

//	A& r1=b1;
	A& r1=a1;
//	B& r2=r1; --error
	B& r2=dynamic_cast<B&>(r1);
	//raise exception if r1 points to a1, else ok
	r2.test();




	return 0;
}
