#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int a,b,c;
	cout << "Hello Ex\n";
	a=10;
	b=0;
	try {
		if(b==0)
			throw b;
		c=a/b;
		cout << "at end of try block\n";
	}catch(int x) {
		cout << "ex occured, inside catch(int) block\n";
		c=INT_MAX;
	}
	cout << "c=" << c << endl;
	cout << "Thank You\n";

	return 0;
}
