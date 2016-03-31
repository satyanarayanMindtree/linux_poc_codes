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
	{sample& r1)
		cout << x << "," << y << endl;
	}
	sample operator+(sample& r1)
	{
		int tx,ty;
		tx=x+r1.x;//tx=this->x+r1.x;
		ty=y+r1.y;//ty=this->y+r1.y;
		//sample temp(tx,ty);
		//return temp;
		return sample(tx,ty);
		/*sample tmp;
		tmp.x=x+r1.x;
		tmp.y=y+r1.y;
		return tmp;*/
	}
	sample operator+(int val)
	{
		int tx,ty;
		tx=x+val;
		ty=y+val;
		return sample(tx,ty);

		//return sample(x+val,y+val);

		/* sample tmp;
		 * tmp.x=x+val;tmp.y=y+val;
		 * return tmp; */
	}
	sample operator++(int) //post
	{
		sample old(*this);
		x++;
		y++;
		return old;6
	}
	sample& operator++() //pre
	{
		++x;
		++y;
		return *this;
	}
	sample& operator=(const sample& r1)
	{
		this->x=r1.x; //x=r1.x;
		this->y=r1.y; //y=r1.y;
		return *this;
	}
};
int main()
{
	sample s1(10,20), s2(1,2), s3;

	s3=s1+s2;  //s3=s1.operator+(s2)
	s3.print();

	sample s4(s1+s2);
	s4.print();

	s3=s1+5;   //s3=s1.operator+(5)

	sample s5(10,20);
	(++s5).print();	//s5.operator++();

	sample s6(12,18);
	(s6++).print(); //s6.operator++(dummy)
	s6.print();

	s3=s1;  //s3.operator=(s1)
	s3.print();

	return 0;
}







