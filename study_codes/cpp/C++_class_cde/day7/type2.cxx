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
	void printx()
	{
		cout << "x=" << x << endl;
	}
	//A& operator=(B&);
};
class B
{
	int y;
	public:
	B(int q) { y=q; }
	void printy() {
		cout << "y=" << y << endl;
	}
	operator A() {
		return A(y);
	}
	//friend class A;
};
/*A& A::operator=(B& rb)
{
	x=rb.y;
	return *this;
}*/
int main()
{
	A a1(10); //A a1=10;
	B b1(20);

	a1=b1; //a1.operator=(b1);
	a1.printx();

	return 0;
}
