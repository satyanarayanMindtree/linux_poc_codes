#include<iostream>
using namespace std;

void swap3(int&,int&);

int main()
{
	int a,b;
	a=10;b=20;
	//swap1(a,b);

	//swap2(&a,&b);
	//print a,b
	
	a=10;b=20;
	swap3(a,b);
	cout << "a=" << a << ",b=" << b << endl;
	print(a,b);
	return 0;
}
void print(const int& x,const int& y)
{
	//print x,y
}
void swap3(int& r1,int& r2)
{
	int t=r1;
	r1=r2;
	r2=t;
}
/*void swap1(int x,int y)
{
	int z=x;
	x=y;
	y=z;
}
void swap2(int *p,int *q)
{
	int t=*p; *p=*q; *q=t;
}*/




