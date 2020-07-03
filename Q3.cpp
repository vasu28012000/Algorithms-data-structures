#include<iostream>
#include<stdio.h>
using namespace std;
char ch[20],c;
void rev(int j,int i=0)
{
	if(i<=j/2)
	{
		c=ch[i];
		ch[i]=ch[j-i];
		ch[j-i]=c;
		rev(j,i+1);
	}
}

int size(int i=0)
{
	if(ch[i]=='\0')
	return 0;
	return 1+size(i+1);
}
int main()
{
	cout<<"ENTER STRING: ";
	gets(ch);
	int s=size()-1;
	cout<<s;
	rev(s);
	cout<<"REVERSED STRING: ";
	puts(ch);
	return 0;
}

