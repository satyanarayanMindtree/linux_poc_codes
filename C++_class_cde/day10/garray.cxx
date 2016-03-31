#include<iostream>
using namespace std;

template<typename T=int,int sz=5>
class Array
{
	//T parr[sz]; //ok
	T* parr;
	int len;
	public:
	Array(T val)
	{
		len=sz;
		parr=new T[len];
		for(int i=0;i<len;i++)
			parr[i]=val;
	}
	~Array() {
		delete[] parr;
	}
	void print() { 
	}
};
int main()
{
	Array<int,5> a1(8);
	Array<double,10> a2(2.3);
	Array<int,6> a3(12);
	Array<int,5> a4(15);

	Array<int> a5(18); //sz becomes 5,default
	Array<float> a6(5.3f); //T<-float,sz<-5
	Array<> a7(0); //T<-int , sz<-5


	a1.print();
	a2.print();
	a3.print();

	return 0;
}
