#include<iostream>
using namespace std;

	class stack{
	int top;
	int ar[20];
	public:stack()
	{
		top=-1;
		
	}
	void push(int n)
	{
		ar[++top]=n;
	}
	int pop()
	{
		
		return ar[top--];
		
	}
	bool isempty()
	{
		if(top==-1)
		return true;
		return false;
	}
};	
int main()
{
	stack s1,s2,s3;
	int n1,n2,check;
	cout<<"ENTER FIRST NUMBER: ";
	cin>>n1;
	cout<<"ENTER SECOND NUMBER: ";
	cin>>n2;
	if(n2>n1)
	{
		check=2;
		s2.push(0);
	}
	else
	{
		s1.push(0);
		check=1;
	}
	for(;n1!=0;)
	{
		s3.push(n1%10);
		n1/=10;
	}
	for(;s3.isempty()==false;)
	{
		s1.push(s3.pop());
	}
	for(;n2!=0;)
	{
		s3.push(n2%10);
		n2/=10;
	}
	
	for(;s3.isempty()==false;)
	{
		s2.push(s3.pop());
	}
	int rem=0,temp,x;
	if(check==1)
	{	
		for(;s1.isempty()==false;)
		{
			if(s2.isempty()==true)
			x=0;
			else
			x=s2.pop();
			temp=s1.pop()+x+rem;
			s3.push(temp%10);
			rem=temp/10;
		}
	}
		if(check==2)
	{	
		for(;s2.isempty()==false;)
		{
			if(s1.isempty()==true)
			x=0;
			else
			x=s1.pop();
			temp=s2.pop()+x+rem;
			s3.push(temp%10);
			rem=temp/10;
		}
	}
	cout<<'\n'<<"RESULT: ";
	for(;s3.isempty()==false;)
	cout<<s3.pop();
}
