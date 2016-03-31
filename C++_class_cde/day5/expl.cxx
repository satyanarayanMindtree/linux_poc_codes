#include<iostream>
using namespace std;

class sample
{
	int x;
	public:
	explicit sample(int p) 
	{
		x=p; 
	}
	explicit sample(const sample& r1) //copy constructor
	{
		x=r1.x; //this->x=r1.x
	}
	void print()
	{
		cout << x <<  endl;
	}
};
int main()
{
	sample s1(10);     //direct
	//sample s1=10;    //copy, wont work if ctor is explicit
	// sample s1(sample(10))
	//2 phase construction , sample(10)==>temp object and then used        //to create s1

	s1.print();

	sample s2(s1);
	//sample s2=s1;   //wont work if copy ctor is explicit
	s2.print();

	return 0;
}


