#include<iostream>
using namespace std;

class Account
{
	//private:
	int acno;
	double bal;		
	public:
	void open(int);
	void deposit(double);
	void withdraw(double);
	double balenq() { return bal; } //compiler may treat inline
	private:
	bool mincheck();
};

//inline prefix needed to treat these as inline
void Account::open(int x){
	acno=x;
	bal=0;
}
void Account::deposit(double tramt)
{
	bal+=tramt;
}
void Account::withdraw(double tramt)
{
	//if(mincheck())
	bal-=tramt;
}
bool Account::mincheck() //helper function
{
	return bal>500?true:false;
}

int main()
{
	Account a1;
	a1.open(1001); //a1.acno=1001,a1.bal=0
	a1.deposit(5000);//a1.bal+=5000
	a1.withdraw(1000);
	//a1.bal=10000; //--error
	//print a1.balenq()   //a1.bal
	return 0;
}
























