#include<iostream>
using namespace std;

class A
{
	int x;
	public:
	A(int p)
	{
		x=p;
	}
	friend void printx(A&);
	friend void test();
	//friend int main();
};
void printx(A& ref)
{
	cout << "x=" << ref.x << endl;
}
void test()
{
	A at(20);
	cout << at.x << endl;
	at.x++;
}
int main()
{
	A a1(10);
	printx(a1);
	//a1.x++;
	//cout << a1.x << endl;
	return 0;
}
