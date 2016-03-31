#include<iostream>
#include<cmath>
#include<cstdio> //strict typechecking
using namespace std;

double x=12.25;
double y=sqrt(x);//dynamic init of global vars
int n=printf("Hello x=%d\n",656);

int main()
{
	int n;
	cout << "sizeof char : " << sizeof('A') << "\n";
	cout << "enter a no.\n";
	cin >> n;
	bool flag=true;
	for(int i=2;i<n;i++)
	{
		if(n%i==0){
			flag=false;
			break;
		}
	}	
	if(flag)
		cout << n << " is a prime no.\n";
	else
		cout << "not a prime no.\n";
	cout << "addr of n : " << &n << endl;	

	return 0;
}















