#include<iostream>
using namespace std;
class addition
{
	public:
	int operator() (int x,int y)
	{
		return x+y;
	}
	int operator() (int x,int y,int z)
	{
		return x+y+z;
	}
	double operator() (double x,double y)
	{
		return x+y;
	}
};
/*int operator()(addition& r1,int x)
{
	return x;
}*/
int main()
{
	int a=10,b=20;
	double c=2.3,d=4.5;
	
	addition a1;

	//cout << a1.sum(a,b);
	cout << a1(a,b) << "\n";  //a1.operator() (a,b);
	cout << a1(c,d) << "\n";  //a1.operator() (c,d);
	cout << a1(a,b,5) << "\n";//a1.operator() (a,b,5);



	return 0;
}
