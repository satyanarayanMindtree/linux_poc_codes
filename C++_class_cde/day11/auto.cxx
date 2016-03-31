#include<iostream>
#include<memory>
using namespace std;

class A
{
	int *ptr;
	int len;
	//auto_ptr<int> ap;
	public:
	A(int p)
	{
		len=p;
		ptr=new int[len];
		//ap=ptr;
	}
	~A() {
		delete[] ptr;
	}

};

template<typename T>
class smart_ptr
{
	T* buf;
	public:
	smart_ptr(T* ptr)
	{
		buf=ptr;
	}
	~smart_ptr()
	{
		delete buf;
	}
};



int main()
{
	A *p1=new A(5);

	auto_ptr<A> ap1(p1);
	auto_ptr<A> ap2(p1);

	smart_ptr<A> sp(p1);


	auto_ptr<A> ap3(new A(8));

	//int *parr=new int[10];
	//auto_ptr<int> api(parr);
		

	return 0;
}






