#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;

int div(int x,int y)
{
	if(y==0)
		throw y;
	return x/y;
}

int main()
{
	int a,b,c,d;
	int *p;
	double *q,y;
	cout << "Hello Ex\n";
	a=10;
	b=1;
	p=&a;
	q=NULL;
	try {
		c=div(a,b);
		if(p==NULL) throw p;
		d=*p;
		if(q==NULL) throw q;
		y=*q;
		cout << "at end of try block\n";
	
	}catch(int val) {
		cout << "ex occured, inside catch(int) block\n";
		cout << "denom is : " << val << endl;
		c=INT_MAX;
	}catch(int* ptr) {
		cout << "ex occured, in catch(int*)\n";
		d=0;
	}catch(...) {
		cout << "generic catch block\n";
	}
	cout << "c=" << c << ",d=" << d << endl;
	cout << "Thank You\n";

	return 0;
}




