#include<iostream>
using namespace std;

class SFull{
};
class SEmpty{
};

template<typename T,int sz=5>
class stack
{
	T arr[sz];
	//T* arr;
	int top;
	public:
	stack()
	{
		//arr=new T[sz];
		top=-1;
	}
	~stack()
	{
		//delete[] arr
	}
	void push(T val)
	{
		if(top==sz-1)
			throw new SFull;
		arr[++top]=val;
	}
	T pop()
	{
		if(isEmpty())
			throw new SEmpty;
		return arr[top--];
	}
	void print() { }
	bool isEmpty() 
	{
		return top==-1;
	}
};
int main()
{
	stack<int,8> s1;
	try {
		s1.push(10);
		s1.push(20);
		s1.push(30);
		cout << s1.pop() << endl;
		s1.print();
	}catch(SFull* ps) {
		cout << "stack is full\n";
	}catch(SEmpty* ps) {
		cout << "stack is empty\n";
	}
	stack<double> s2; //sz will be 5,default
	return 0;
}
