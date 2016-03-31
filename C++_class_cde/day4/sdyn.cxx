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
	
	sample(int p) { x=p; y=0; } //param ctor
	sample() { x=0; y=0; } //deafult ctor
	
	void print()
	{
		cout << x << "," << y << endl;
	}
	int findsum() { return x + y; }
};
int main()
{
	sample s1(10,20);
	sample* ps;
	ps=&s1;
	ps->print();
	cout << ps->findsum() << endl;

	sample& rs=s1;
	rs.print();

	sample *p1;
	p1=new sample; //p1=new sample();
	p1->print();

	sample *p2=new sample(12,18);
	p2->print();

	delete p1;
	delete p2;

	sample s0(); //s0 is a function
	//s0.print(); --error
	
	sample* parr=new sample[10];//depends on def ctor
	//parr[i].print();
	delete[] parr;







	return 0;
}
