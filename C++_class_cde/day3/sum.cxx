#include<iostream>
using namespace std;



int sum(int,int);
int sum(int,int,int);
double sum(double,double);
//float sum(float,float);

int main()
{
	int a=10,b=20,c=5;
	long int l=10l,m=20l;
	double x=2.3,y=4.5;
	float f=2.3f,g=4.5f;

	cout << sum(a,b,c) << endl;
	cout << sum(x,y) << endl;
	cout << sum(10,20) << endl;
	sum(10.0,20.0);
	cout << sum(f,g);
	//sum('A',2.3); --ambiguous
	
	//sum(a,x);     --ambiguous
	cout << "sum char is " << sum(' ','A') << endl;
	//sum(l,m);
	sum(&a,&b);
	sum(a,b,c,5);
	return 0;
}
/*int sum(int x,int y)
{
	cout << "sum(i,i)\n";
	return x + y;
}
int sum(int x,int y,int z)
{
	cout << "sum(i,i,i)\n";
	return x + y + z;
}
double sum(double p,double q)
{
	cout << "sum(d,d)\n";
	return p + q;
}*/
