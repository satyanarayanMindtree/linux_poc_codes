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
	b=0;
	p=NULL;
	q=&y;
	try {
		try {
			c=div(a,b);
		}catch(int val) { //check without catch(int)
			cout << "inner catch block,int type\n";
			c=INT_MAX;
			throw val; // Re throw
		}
		try {
			if(p==NULL) throw p;
			d=*p;
		}catch(int* ptr) {
			cout << "inner catch block,int*\n";
			d=0;
		}
		if(q==NULL) throw q;
		y=*q;
		cout << "at end of try block\n";
	
	}catch(int val) {
		cout << "outer catch block,int type\n";
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




