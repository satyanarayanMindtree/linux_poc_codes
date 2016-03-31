#include<iostream>
using namespace std;

int main()
{
	const int y=20;
	int *p;
	//p=&y; --error
	const int* q=&y;
	//(*q)++; --error
	cout << *q << endl;

	int x=10;
	const int& r1=x;
	//r1++; --error

	//int& r2=y; --error
	const int& r3=y;
	//r3++ --error
	cout << r3 << endl;
	return 0;
}






