#include<iostream>
using namespace std;

int main()
{
	int x=10;
	const int& y=20;
	const int& z=(x+5);
	cout << y << "," << z << endl;

	int& r1=(int&)y;
	r1++;
	cout << r1 << endl;
	int& r2=(int&)z;
	r2=18;
	cout << r2 << endl;

	return 0;
}
