#include<iostream>
#include<climits>
using namespace std;

int f1(int,int);
int f2(int,int);
int div(int,int) throw(); //throw(int,double*);

int main()
{
	int a,b,c;
	a=10;
	b=0;
	c=f1(a,b);
	cout << "c=" << c << endl;
	cout << "thank you\n";
	return 0;
}
int f1(int x,int y)
{
	int z;
	try {
	z=f2(x,y);
	}catch(int d) { z=INT_MAX; }
	cout << "end of f1\n";
	return z;
}
int f2(int x,int y)
{
	int z;
	try {
	z=div(x,y);
	}catch(int* d) { 
		z=INT_MAX; 
		cout << "catch--int block\n";
	}catch(double* q) {cout << "catch-double*\n"; }


	cout << "end of f2\n";
	return z;
}
int div(int x,int y) throw() //throw(int,double*) //throw(...)
{
	int z;
	double* q;
	//throw q;
	//try {
	if(y==0)
		throw y;
	z=x/y;
	//}catch(int d) {z=INT_MAX;}
	cout << "end of div\n";
	return z;
}
