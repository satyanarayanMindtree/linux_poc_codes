#include<iostream>
using namespace std;

class A
{
	int *p;
	public:
	A() { p=new int[5]; }
	virtual void test() {
		cout << "A--test\n";
	}
	virtual ~A() {  delete[] p;
		cout << "A destructor\n"; }
};
class B:public A
{
	int *q;
	public:
	B() { q=new int[10]; }
	void test() {
		cout << "B--test\n";
	}
	~B() { cout << "B destructor\n"; 
		delete[] q;
		}
};
int main()
{

	A* p1;	
	p1=new B();
	cout << "sizeof *p1 : " << sizeof(*p1) << endl;
	p1->test();

	delete p1;

	return 0;
}

