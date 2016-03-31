#include<iostream>
using namespace std;

int main()
{
	int *q;
	char *pc;
	int x=15;
	pc=new char[4];
	pc[0]='A';pc[1]='B';pc[2]='C';pc[3]='D';

	q=new (pc) int;
	//no need to deallocate
	cout << *q << endl;
	cout << *pc << endl;

	q=new (&x) int;
	cout << *q << endl;

	delete p;
	return 0;
}
