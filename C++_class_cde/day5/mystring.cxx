#include<iostream>
#include<cstring>
using namespace std;

class MyString
{
	//char buf[MAX];
	char* buf;
	int len;
	public:
	MyString(const char* str)
	{
		len=strlen(str);
		buf=new char[len+1];
		strcpy(buf,str);
	}
	MyString(const MyString& ref)
	{
		len=ref.len; //len=strlen(ref.buf);
		buf=new char[len+1];
		strcpy(buf,ref.buf);
	}
	void print()
	{
		cout << "str is " << buf << endl;
		cout << "Addr is " << (unsigned int)buf << endl;
	}
	~MyString()   //destructor
	{
		delete[] buf;
	}
	//same name as class name with prefix ~, no params,no retval
	//to release any external mem/resources
	//any cleanup/closing activities
	//
	//destructor & programmer providec copy ctor comes in 
	//combination
};
MyString s0("hello");
int main()
{
	MyString s1("abcd");
	s1.print();
	//MyString s2(s1);
	//s2.print();

	MyString *p1=new MyString("hellocpp");
	MyString *p2=new MyString(*p1);
	p1->print();
	delete p1;
	p2->print();
	return 0;
}
