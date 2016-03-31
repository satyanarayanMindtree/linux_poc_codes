#include<iostream>
using namespace std;

class sample
{
	int x;
	int y;
	public:
	sample(int p=0,int q=0) 
	{
		x=p; y=q;
	}
	sample(const sample& r1) //copy constructor
	{
		x=r1.x; //this->x=r1.x
		y=r1.y; //this->y=r1.y
	}
	//takes 1 param which is a ref of same type and const
	//in absence of our copy ctor compiler provides one
	//implicitly which does memwise copy
	void print()
	{
		cout << x << "," << y << endl;
	}
	int findsum() { return x + y; }
};
int main()
{
	sample s1(10,20);
	s1.print();
	cout << s1.findsum() << endl;

	sample s2(15);
	sample s3;

	sample s4(s1);  //direct
	//sample s4=s1;	  //copy -- try to avoid
	s4.print();

	return 0;
}
