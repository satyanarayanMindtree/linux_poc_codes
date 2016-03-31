#include<iostream>
using namespace std;

class sample
{
	public:
	int x;
	int y;

	int sum(int x,int y) { 
		cout << "sum is " << x+y << endl;
		return x+y; }
	int pro(int x,int y) { return x*y; }

};

int main()
{
	sample s1;
	sample *ps=&s1;

	int sample::*p=&sample::x;
	
	s1.*p=20;
	cout << s1.*p << endl;

	p=&sample::y;
	ps->*p=25;
	cout << ps->*p << endl;

	int (sample::*fp)(int,int);
	fp=&sample::sum;
	cout << (s1.*fp)(10,20) << endl;
	fp=&sample::pro;
	cout << (ps->*fp)(10,20) << endl;



	return 0;
}





