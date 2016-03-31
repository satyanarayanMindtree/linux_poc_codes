#include<iostream>
using namespace std;
class sample
{
	int x;
	int y;
	public:
	sample(int p=0,int q=0)
	{
		x=p;
		y=q;
	}
	sample(const sample& r1)
	{
		cout << "copy ctor" << endl;
		x=r1.x;
		y=r1.y;
	}
	void print()
	{
		cout << x << "," << y << endl;
	}
	//sample& operator++() { } --ambiguous error
	
	friend sample operator+(sample&,sample&);
	friend sample operator+(sample&,int);
	friend sample operator++(sample&,int);
	friend sample& operator++(sample&);

	friend ostream& operator<<(ostream&,sample&);
	friend istream& operator>>(istream&,sample&);
};
//ostream& operator<<(ostream& rout,int val) {} --error
sample operator+(sample& r1,sample& r2)
{
	int tx,ty;
	tx=r1.x+r2.x;
	ty=r1.y+r2.y;
	return sample(tx,ty);
}
sample operator+(sample& r1,int val)
{
	return sample(r1.x+val,r1.y+val);
}
sample& operator++(sample& r1)
{
	r1.x++;r1.y++;
	return r1;
}
sample operator++(sample& r1,int)
{
	sample old(r1);
	r1.x++;
	r1.y++;
	return old;
}
ostream& operator<<(ostream& rout,sample& r1)
{
	rout << "x=" << r1.x << endl;
	rout << "y=" << r1.y << endl;
	return rout;
}
istream& operator>>(istream& rin,sample& r1)
{
	rin >> r1.x >> r1.y;
	return rin;
}
int main()
{
	//cout << test() << endl;
	sample s1(10,20), s2(1,2), s3;
	cout << s1 << endl; //operator<<(cout,s1)
	s3=s1+s2; //s3=operator+(s1,s2)

	s3=s1+8;  //s3=operator+(s1,8);

	++s1;	  //operator++(s1);

	s1++; 	  //operator++(s1,int)


	return 0;
}







