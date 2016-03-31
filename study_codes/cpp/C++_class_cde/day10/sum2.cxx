#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T1,typename T2>
void test(T1 x,T2 y)
{
	cout << typeid(x).name() << "," << typeid(y).name()
		<< endl;
	cout << "x=" << x << ",y=" << y << endl;
}

template<typename T1,typename T2>
void test(T1* x,T2* y)
{
	cout << "T1*,T2*" << endl;
}

int main()
{
	int a=10,b=20;
	double x=2.3,y=4.5;

	test(a,b);
	test(a,x);
	test(y,b);
	test(a,'+');
	test(&a,&b);
	test(&a,a);

	test<int,int>(a,x);
	test<int>(x,y); //T1<-int,explicit 
			//T2<-double,implicit


	return 0;
}
