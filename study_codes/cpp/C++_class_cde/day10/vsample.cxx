#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1(5,8);
	v1[2]=12;
	cout << "val is : " << v1[2] << endl;
	v1.push_back(10);
	cout << "size=" << v1.size() << endl;
	cout << "capacity=" << v1.capacity() << endl;

	v1.reserve(50); //v1.resize(50);
	cout << "capacity=" << v1.capacity() << endl;
	cout << "size=" << v1.size() << endl;
	for(int i=0;i<v1.size();i++)
		cout << v1.at(i) << endl;
	return 0;
}
