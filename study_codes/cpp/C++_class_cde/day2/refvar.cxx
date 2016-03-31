#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	int& y = x;
	y++;
	cout << "x=" << x << endl;
	x=20;
	cout << "y=" << y << endl;
	cout << &x << "," << &y << endl;
	int& z = x;
	int& w = y;

	//int& r1; --error
	int *p=&x;
	int &r2 = *p;


	return 0;
}
