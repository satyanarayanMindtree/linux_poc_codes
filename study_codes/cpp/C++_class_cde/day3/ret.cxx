#include<iostream>
using namespace std;

int& test(int);

int main()
{
	int a,*p;
	int b=test(a);
	int& c=test(a);
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	p=testp(a);
	cout << *p << endl;
	return 0;
}
int& test(int& y)
{
	int z;
	z=30;
	return y;
}
int* testp(int& y)
{
	int z;
	z=30;
	return &y;
}
