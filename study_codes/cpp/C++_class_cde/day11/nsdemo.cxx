#include<iostream>
using namespace std;

//int x=5;

namespace n1
{
	class sample {

	};
	static int x=10;
	int y=12;
	void f1() {   }
};

namespace n2
{
	class sample {

	};
	int x=20;
	int z=18;
	void f2() {  }
};

//using n1::f1;
//using n2::f2;

//using n1::x;
//using n2::x; --immediate error

using namespace n1;
using namespace n2;//no immediate error, error if access to common symb

int main()
{
	n1::sample s1;
	n2::sample s2;

	cout << "n1's x=" << n1::x << endl;
	n2::x++;
	x++; //error-ambiguous

	cout << "x=" << n1::x << endl;

	f1();
	f2();

	return 0;
}
