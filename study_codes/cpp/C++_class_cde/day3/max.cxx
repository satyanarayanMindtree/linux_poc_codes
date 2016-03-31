#include<iostream>
using namespace std;
int& max(int&,int&);
int main()
{
	int a,b,c;
	a=30;
	b=20;
	c=max(a,b);
	cout << "c=" << c << endl;

	max(a,b)=25; //acts as lvalue also,as returning
		     //valid reference
	cout << "a= " << a << ",b=" << b << endl;
	max(a,b)++;
	cout << "a= " << a << ",b=" << b << endl;

	int& d=max(a,b);

	return 0;
}
int& max(int& x,int& y)
{
	if(x>y)
		return x;
	else
		return y;
}
