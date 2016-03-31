#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("abcd");
	cout << "s1=" << s1 <<endl;
	cout << "len=" << s1.length() << endl;

	string s2,s3;
	s2=s1;
	s1.at(0)++;
	cout << "s1=" << s1 <<endl;
	cout << "s2=" << s2 << endl;

	cout << "char arr is " << s1.c_str() << endl;
	
	s2="xyz";
	s3=s1+s2;
	cout << "s3=" << s3 << endl;

	cout << "Enter a string";
	cin >> s2;
	if(s1==s2)
		cout << "equal\n";
	else
		cout << "not equal\n";
	return 0;
}
