#include<iostream>
using namespace std;

class B;

class A
{
	int x;
	public:
	A(int p)
	{
		x=p;
	}
	void printy(B&);
	friend class B;
};
class B
{
	int y;
	public:
	B(int q) { y=q; }
	void printx(A& r1)
	{
		cout << "x=" << r1.x << endl;
	}
	friend class A;
};
void A::printy(B& r2)
{
	cout << "y=" << r2.y << endl;
}
int main()
{
	A a1(10);
	B b1(20);
	b1.printx(a1);
	a1.printy(b1);
	return 0;
}
