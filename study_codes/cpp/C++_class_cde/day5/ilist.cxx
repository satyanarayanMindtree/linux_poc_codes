#include<iostream>
using namespace std;
class sample
{
	int x;
	int y;
	const int a;
	int& r1;
	public:
	sample(int p,int q,int r):x(p),y(q),a(r),r1(x)
	{
		cout << "x=" << x << ",y=" << y << endl;
		cout << "r1=" << r1 << endl;
		//x=p;y=q;
		//a=r;
	}
	sample():x(0),y(0),a(10),r1(x)
	{
			//nothing to do
	}
	void print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	sample s1(10,20,30);
	s1.print();
	return 0;
}
