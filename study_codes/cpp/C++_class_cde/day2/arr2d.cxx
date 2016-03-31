#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int (*p)[5];
	p=new int[4][5];
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			p[i][j]=i*10+j+1;

	delete[] p;

	int **q;
	q=new int*[3];
	q[0]=new int[4];
	q[1]=new int[5];
	q[2]=new int[6];
	//access elements
	delete[] q[0];
	delete[] q[1];
	delete[] q[2];
	delete[] q;

	return 0;
}
