#include<iostream>
#include<stdio.h>
using namespace std;

	class stack{
	int top;
	int *ar;
	public:stack(int n=20)
	{
		top=-1;
		ar=new int(n);
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
	int x;
	stack s;
	char c[50];
	gets(c);
	int u;
	for(int i=0;c[i]!='\0';++i)
	{
		switch(c[i])
		{
			case '+':s.push(s.pop()+s.pop());
										break;
			case '-':x=s.pop();
						s.push(s.pop()-x);
										break;
			case '*':s.push(s.pop()*s.pop());
										break;
			case '/':x=s.pop();
					s.push(s.pop()/x);
										break;
			case '%':x=s.pop();
						s.push(s.pop()%x);
										break;
			default: if(c[i]-47>0&&c[i]-49<9)
					{
						u=c[i]-48;
						++i;
						while(c[i]!=' ')
						{
							u*=10;
							u+=c[i]-48;
							++i;						
						}
						--i;
						s.push(u);
					}
										break;
		};
	}
	cout<<"RESULT: "<<s.pop();
}
