#include<iostream>
#include<stdio.h>
using namespace std;

	class stack{
	int top;
	int *ar;
	int size;
	public:stack(int n=20)
	{
		top=-1;
		size=n-1;
		ar=new int(n);
	}
	void push(int n)
	{
		if(!isfull())
		ar[++top]=n;
	}
	int pop()
	{
		if(!isempty())
		return ar[top--];
		else
		{
			cout<<"UNDERFLOW!!!";
			return -1;
		}
		
	}
	void clear()
	{
		while(!isempty())
		pop();
	}
	bool isempty()
	{
		if(top==-1)
		return true;
		return false;
	}
	bool isfull()
	{
		if(top==size)
		{	
			cout<<"OVERFLOW!!!";
			return true;
		}
		else
		{
			return false;
		}
	}
	void display()
	{
		for(int i=top;i!=-1;--i)
		{
			cout<<ar[i]<<", ";
		}
	}
};	
int main()
{
	cout<<"ENTER SIZE OF STACK: ";
	int n;
	cin>>n;
	stack s(n);
	int choice=0;
	while(choice<5)
	{
		cout<<"\nMENU\n1.PUSH\n2.POP\n3.CLEAR\n4.DISPLAY\nENTER CHOICE: ";
		cin>>choice;
		switch(choice)
		{
			case 1:int u;
					cout<<"ENTER ELEMENT: ";
					cin>>u;
					s.push(u);
										break;
			case 2:choice=s.pop();
					if(choice!=-1)
					cout<<choice<<" has been poped out!!";
										break;
			case 3:s.clear();
										break;
			case 4:s.display();
										break;				
		};
					
	}
}
