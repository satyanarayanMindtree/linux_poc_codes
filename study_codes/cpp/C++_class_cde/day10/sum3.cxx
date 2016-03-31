#include<iostream>
#include<typeinfo>
using namespace std;

template<typename RT,typename T1,typename T2>
RT test(T1 x,T2 y)
{
	RT z;
	cout << typeid(x).name() << "," << typeid(y).name()
		<< endl;
	cout << "x=" << x << ",y=" << y << endl;
	return z;
}
//RT cant be resolved implicitly,as not part of param list

int main()
{
	int a=10,b=20;
	double x=2.3,y=4.5;

	//test<int,int,int>(a,b);
	//test<float,int,double>(a,x);
	//
	test<int>(a,b);
	test<float>(a,x);
	
	return 0;
}
