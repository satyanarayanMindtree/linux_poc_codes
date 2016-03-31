#include<iostream>
using namespace std;
int x=10;
void test();
int main()
{
	int x=20,y=18;
	//::y=24; --error
	cout << "1.x=" << x << endl;    //20
	cout << "2.x=" << ::x << endl;  //10
	{
		int x=30;
		cout << "3.x=" << x << endl; //30
		cout << "4.x=" << ::x << endl;  //10
	}
	cout << "5.x=" << x << endl; //20
	return 0;
}
void test()
{
	//print 6.x -- 10
}
