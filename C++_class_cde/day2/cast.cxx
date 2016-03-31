#include<iostream>
using namespace std;

int main()
{
	//const int x=10;
	const volatile int x=10;
	int* p;
	//p=(int*)&x; //c style casting
	p=const_cast<int*>(&x); //c++ style
	(*p)++;
	cout << "x=" << x << ",*p=" << *p << endl;	

	//const int y=20;
	const volatile int y=20;
	//int& r1=(int&)y; //old style
	int& r1=const_cast<int&>(y);
	r1=25;
	cout << "y=" << y << ",r1=" << r1 << endl;

	return 0;
}
