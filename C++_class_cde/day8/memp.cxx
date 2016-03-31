#include<iostream>
using namespace std;

class sample
{
	int x;
	int y;
	public:
	int z;
	sample(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	void print(int dummy)
	{
		cout << x << "," << y << endl;
	}
	int sum(int a,int b)
	{
		return a + b;
	}
};

int main()
{
	sample s1(10,20);
	sample* ps=new sample(11,12);

	int sample::*pz=&sample::z;
	
	s1.*pz=15;
	cout << "z=" << s1.*pz << endl;

	ps->*pz=18;
	cout << "z=" << ps->*pz << endl;

	int *p=&s1.z;
	*p=12; cout << *p << endl;

	void (sample::*pfun)(int)=&sample::print;
	(s1.*pfun)(0);
	(ps->*pfun)(0);

	int (sample::*fp)(int,int);
	fp=&sample::sum;
	cout << (s1.*fp)(10,20) << endl;
	cout << (ps->*fp)(11,12) << endl;


	return 0;
}
