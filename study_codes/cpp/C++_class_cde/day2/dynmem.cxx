#include<iostream>
using namespace std;

int main()
{
	int *p,*parr;
	p=new int;
	*p=20;
	cout << *p << "\n";
	delete p;

	p=new int(10);
	cout << *p << "\n";
	delete p;

	parr=new int[10];
	for(int i=0;i<10;i++)
		parr[i]=i*10+1;
	//do some access
	delete[] parr;

	return 0;
}






