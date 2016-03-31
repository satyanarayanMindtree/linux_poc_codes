#include<iostream>
using namespace std;
class A
{
	const int x;
	const static int y;
	const static int z=15; //direct init is allowed
	//static int p=5; --error
	public:
	A(int p):x(p)
	{
		//x=p; --error
	}
	void printx() { cout << x << endl; }
	static void printy() {
		cout << "y=" << y << endl;
	}
};
const int A::y=12;
int main()
{
	A a1(10);
	a1.printx();
	A::printy();
	return 0;
}
