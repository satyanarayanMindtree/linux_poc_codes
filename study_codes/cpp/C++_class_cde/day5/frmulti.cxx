#include<iostream>
using namespace std;

class B; //fwd declaration

class A
{
	int x;
	public:
	A(int p)
	{
		x=p;
	}
	friend void printxy(A&,B&);
};
class B
{
	int y;
	public:
	B(int q) { y=q; }
	friend void printxy(A&,B&);
};

void printxy(A& r1,B& r2)
{
	cout << "x=" << r1.x << endl;
	cout << "y=" << r2.y << endl;
}

int main()
{
	A a1(10);
	B b1(20);
	printxy(a1,b1);
	return 0;
}
