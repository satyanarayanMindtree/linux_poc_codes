#include<iostream>
using namespace std;
class array
{
	int *arr,*cur;
	int len;
	public:
	array(int n,int val)
	{
		len=n;
		cur=arr=new int[len];
		for(int i=0;i<len;i++)
			arr[i]=val;
	}
	~array()
	{
		delete[] arr;
	}
	//add copy ctor
	void print()
	{
		for(int i=0;i<len;i++)
			cout << arr[i] << "\t";
		cout << "\n";
	}
	/*int getval(int index)
	{
		return arr[index];
	}
	void setval(int index,int val)
	{
		arr[index]=val;
	}*/
	int& valueat(int index)
	{
		return arr[index];
	}
	int& operator[](int index)
	{
		return arr[index];
	}
	int& operator*()
	{
		return *cur;
	}
	array& operator++()
	{
		//check limits
		cur++;
		return *this;
	}
	array& operator--()
	{
		//check limits
		cur--;
		return *this;
	}
};
int main()
{
	array a1(5,8);
	//a1.print();

	//a1.setval(2,12);
	//cout << a1.getval() << endl;
	
	a1.valueat(2)=12;
	cout << a1.valueat(2) << endl;

	a1[3]=15;
	cout << a1[3] << endl;

	a1.print();

	++a1;
	++a1;
	*a1=13;
	cout << *a1;   //x=a1.operator*();

	--a1;

	return 0;
}


