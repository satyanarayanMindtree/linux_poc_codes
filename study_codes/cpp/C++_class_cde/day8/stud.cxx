#include<iostream>
#include<cstring>
using namespace std;

class person
{
	char name[20];
	int age;
	public:
	void setperson(char* str,int x) {
		strcpy(name,str);
		age=x;
	}
	void printp()
	{
		cout << name << "," << age << endl;
	}
};
class student:public person
{
	int rollno;
	double marks;
	public:
	void setstudent(char* s1,int a,int r,double m)
	{
		setperson(s1,a);
		rollno=r;
		marks=m;
	}
	void prints()
	{
		printp();
		cout << rollno << "," << age << endl;
	}
};
class graduate:public student
{
	int credits;
	public:
};

int main()
{
	cout << "size of stud:" << sizeof(student) << endl;
	student s1;
	s1.setstudent("abc",20,1001,64.23);
	s1.prints();
	return 0;
}




