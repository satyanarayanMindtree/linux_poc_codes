#include<iostream>
using namespace std;

class sample
{
	int x;
	int y;
	public:
	sample(int p,int q) //paramterized ctor
	{
		x=p; y=q;
	}
	//same name as class name,no ret type
	//they are invoked just after the object creation and before
	//first use, used to initialize/give initial values for data 
	//can't be invoked explicitly
	
	sample(int p) { x=p; y=0; } //param ctor
	sample() { x=0; y=0; } //deafult ctor

	//sample(int p=0,int q=0) { x=p; y=q; }
	
	void print()
	{
		cout << x << "," << y << endl;
	}
	int findsum() { return x + y; }
};
int main()
{
	sample s1(10,20);
//	s1.init(10,20);
	s1.print();
	cout << s1.findsum() << endl;

	sample s2(15);
	sample s3;




	return 0;
}
