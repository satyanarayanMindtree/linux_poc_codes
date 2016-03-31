#include<iostream>
using namespace std;

class sample
{
	int x;
	int y;
	public:
	void init(int p,int q)
	{
		x=p; y=q;
	}
	void init(int p) { x=p; y=0; }
	void init() { x=0; y=0; }
	//void init(int p=0,int q=0) { x=p; y=q; }
	void print()
	{
		cout << x << "," << y << endl;
	}
	int findsum() { return x + y; }

	//partial violation of data hiding, provide only when necessary
	void setx(int p) { x=p; } //mutator method
	void sety(int q) { y=q; }
	int getx() { return x; } //accessor method
	int gety() { return y; }

	int& xval() { return x; }
};
int main()
{
	sample s1;
	s1.init(10,20);
	s1.print();
	cout << s1.findsum() << endl;

	s1.setx(12);
	cout << s1.getx(); 

	cout << s1.xval() << endl;
	s1.xval()=15; //as good as s1.x=15, violation of
		      //data hiding,try to avoid

	return 0;
}
