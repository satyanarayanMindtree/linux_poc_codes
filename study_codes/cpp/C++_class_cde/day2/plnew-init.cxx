#include<iostream>
using namespace std;
char garr[40];
int main()
{
	char carr[40];
	int *parr;
	char *pc;
	pc=new char[40];
	//initialize 40 bytes of raw memory as per needs

	//parr=pc; -- compile time error
	parr=new (pc) int[10];
	//parr=new (carr) int[10];
	//parr=new (garr) int[10];
	for(int i=0;i<10;i++)
		parr[i]=15;
	cout << (unsigned int)pc << "," << 
		(unsigned int)parr << endl;
	delete[] pc;

	return 0;
}

