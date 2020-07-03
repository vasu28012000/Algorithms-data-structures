#include<iostream>
#include<stdio.h>
using namespace std;
	class stack1{
	int top;
	char ar[20];
	public:stack()
	{
		top=-1;
		
	}
	void push(char n)
	{
		ar[++top]=n;
	}
	char pop()
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
	char ch[20],c;
	stack1 s1;
	gets(ch);
	for(int i=0;ch[i]!='\0';++i)
	{
		switch(ch[i])
		{
			case '*':
			case '/':s1.push(ch[i]);
						break;
			case '(':s1.push(ch[i]);
						break;
			case ')':c=s1.pop();
						while(c!='(')
						{
							cout<<c;
							c=s1.pop();
						}
							break;
			case '+':
			case '-':if(!s1.isempty())
						{
							char r=s1.pop();
							switch(r)
							{
								case '*':
								case '/':cout<<r;
											s1.push(ch[i]);
										break;
								default:s1.push(r);
										s1.push(ch[i]);
											break;
							}
						}
						else
						s1.push(ch[i]);
								break;
			default: cout<<ch[i];
								break;								
		}
	

	}
	for(;s1.isempty()==false;)
	cout<<s1.pop();

return 0;
}
