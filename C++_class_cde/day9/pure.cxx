#include<iostream>
using namespace std;

class A
{
	public:
	virtual void test()=0;
	virtual int f1(int x)
	{
		return 5*x;
	}
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
	
	B b1;
	A *p1;
	p1=&b1;
	p1->test();
	cout << p1->f1(6) << endl;

	A a1; //, A cant create objects as it is abstract class
	//p1=&a1;
	p1->test();

	return 0;
}






