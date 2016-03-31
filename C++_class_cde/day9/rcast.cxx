#include<iostream>
using namespace std;

class A
{
	int x,y;
	public:
	A(int p,int q) { x=p;y=q;}
	void printxy() {
		cout << x << "," << y << endl;
	}
};
class B
{
	int a,b;
	public:
	B(int p,int q) { a=p;b=q;}
	void printab() {
		cout << a << "," << b << endl;
	}
};

int main()
{
	int x=-10,*p;
	float y=2.3,*q;
	//p=&y;
	//q=&x;
	p=reinterpret_cast<int*>(&y);
	cout << "*p=" << *p << endl;
	q=reinterpret_cast<float*>(&x);
	cout << "*q=" << *q << endl;

	A a1(10,20);
	B *pb;
	//pb=&a1;
	pb=reinterpret_cast<B*>(&a1);
	pb->printab();

	//pb=dynamic_cast<B*>(&a1);
	//pb=static_cast<B*>(&a1);

	return 0;
}
