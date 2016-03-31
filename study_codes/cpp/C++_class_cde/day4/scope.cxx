#include<iostream>
using namespace std;

int x=8,y=6;

class sample
{
	int x;
	int y;
	public:
	sample(int x=0,int y=0) //paramterized ctor
	{
		//sample::x=x; sample::y=y;
		this->x=x;
		this->y=y;
	}
	void f1() {}	
	void print()
	{
		this->f1();
		int x=18;
		cout << x << "," << y << endl; //18,20
		cout << "global x : " << ::x << endl; //8
		cout << "class var x : " << sample::x << endl; //10
		cout << "class var x : " << this->x << endl; //10
	}
	void test(int y) { 
		cout << x << "," << y << endl; 
		cout << "global y : " << ::y << endl; //6
		cout << "class var y : " << sample::y << endl; //20
	}
	int findsum() { return x + y; }
};
int main()
{
	sample s1(10,20);
	s1.print();
	s1.test(12);
//	cout << s1.findsum() << endl;


	return 0;
}
