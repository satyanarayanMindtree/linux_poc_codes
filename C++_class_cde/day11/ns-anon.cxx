#include<iostream>
using namespace std;

namespace {
	int x=10; //can't be linked externally
} //anonymous namespace
int y=10;

void test();

int main()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	::x++;
	::y++;
	test();
	return 0;
}
