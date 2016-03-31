#include<iostream>
#include<cstdio>
using namespace std;

class node
{
	int data;
	node* next;
	public:
	node(int x=0,node* p=NULL)
	{
		data=x;
		next=p;
	}
	friend class linkedlist;
};

class linkedlist
{
	node* start;
	public:
	linkedlist()
	{
		start=NULL;
	}
	void insbeg(int val)
	{
		node* tmp=new node(val,start);
		//node* tmp=new node;
		//tmp->data=val;
		//tmp->next=start;
		start=tmp;
	}
	void delbeg()
	{
		//check for empty
		node* p=start;
		start=p->next;
		cout << "deleted node is: " << p->data;
		delete p;
	}
	void print()
	{
		for(node* p=start;p!=NULL;p=p->next)
			cout << p->data << endl;
	}	
};


int main()
{
	return 0;
}
