#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char ch;
	ifstream fin;
	fin.open("s1.dat",ios::in);
//	fin>>ch;fin>>ch;
	fin.seekg(5,ios::cur); //ios::beg,ios::end
	fin >> ch;
	cout << ch << endl;
	return 0;
}
