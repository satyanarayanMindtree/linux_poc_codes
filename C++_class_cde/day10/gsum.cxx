#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T>
T sum(T n1,T n2)
{
	T n3;
	cout << "type is " << typeid(n1).name() << "\n";
	n3=n1+n2;
	return n3;
}
template<typename T>
void gswap(T& r1,T& r2)
{
	cout << "gswap T&,T&\n";
	cout << "1.type is " << typeid(T).name() << "\n";
	T temp=r1;
	r1=r2;
	r2=temp;
}
template<typename T>
void gswap(T* p1,T* p2) //partially specialized over prev
{
	cout << "gswap T*, T*\n";
	cout << "2.type is " << typeid(T).name() << "\n";
	int tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}

void gswap(char* ps1,char* ps2)//completely specialized
{
	cout << "gswap(char*,char*)" << "\n";
	//some code
}
int main()
{
	int a=10,b=20,c;
	float x=2.3f,y=4.5f,z;

	c=sum(a,b); //implicit resolution,based on args
	z=sum(x,y);

	cout << "c=" << c << endl;
	cout << "z=" << z << endl;
	cout << sum(1,2) << endl;
	cout << sum<int>(a,x) << endl;

	z=sum<int>(x,y);//explicit resolution
	cout << "z=" << z << endl;
	cout << sum(2.3,4.5) << endl;

	gswap(a,b);
	cout << a << "," << b << endl;

	a=10;b=20;
	int *p=&a,*q=&b;
	cout << p << "," << q << endl;
	gswap(p,q);
	cout << p << "," << q << endl;
	cout << a << "," << b << endl;

	char s1[20]="abcd",s2[20]="xyz";
	gswap(s1,s2);

	gswap(&a,&b); //error in absence of gswap(T*,T*)

	return 0;
}
