#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream fout("sample.dat");
	fout << "Hello File\n";
	//fout << s1; //s1 is an object of student class
	fout.close();

	char ch;
	ifstream fin(__FILE__); 
	fin.unsetf(ios::skipws);
	while(1)
	{
		fin >> ch;
		if(fin.eof())
		{
		//	cout << (int)ch << endl;
			break;
		}
		cout << ch;
	}
	fin.close();
	return 0;
}
