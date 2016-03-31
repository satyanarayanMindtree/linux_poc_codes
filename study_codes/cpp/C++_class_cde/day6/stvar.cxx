#include<iostream>
using namespace std;

class A
{
	int x;
	static int y; //declaration only
	public:
	A(int p)
	{
		x=p;
	}
	void print()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
	static void sety(int q) { y=q; }
	static int gety() { return y; }

	static void printy()
	{
		//print(); --error
		cout << "y=" << y << endl;
	}
};
int A::y=0;  //definition of static variable
A ag(8);
int main()
{
	//A::y=5;
	A::sety(5);
	cout << A::gety() << endl;
	A a1(11),a2(12),a3(13);
	//a1.y=10; 
	a1.sety(10);
	//a2.y=20;
	a2.sety(20);
	//cout << a1.y << "," << a2.y << "," << a3.y << endl;
	cout << a1.gety() << "," << a2.gety() << 
		"," << a3.gety() << endl;
	//cout << A::y << endl;
	a1.printy();
	A::printy();

	return 0;
}







