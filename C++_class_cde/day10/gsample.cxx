#include<iostream>
using namespace std;

template<typename T>
class sample
{
	T x;
	T y;
	public:
	sample(T p,T q)
	{
		x=p; y=q;
	}
	sample() {   }
	void print();
	T getsum() { return x+y; }

	void setx(T p);
	T getx() { return x; }
	//sety,gety
};

template<typename T>
void sample<T>::setx(T p)
{
	x=p;
}

template<typename T>
void sample<T>::print()
{
	cout << x << "," << y << endl;
}
int main()
{
	sample<int> s1(10,20);
	sample<double> s2;
	sample<int> s3;
	//implicit resolution not applicable for classes
	//sample s1(10,20) -- error
	return 0;
}
