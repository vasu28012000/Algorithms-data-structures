#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void LCS(char x[30],char y[30])
{
	int m=strlen(x)+1,n=strlen(y)+1;
	int c[m][n];
	char ch[20];
	for(int i=0;i<m;++i)
	{
		c[i][0]=0;
	}
	for(int j=0;j<n;++j)
	{
		c[0][j]=0;
	}
	
	int p,q;
	for(p=1;p<m;++p)
	{
		for(q=1;q<n;++q)
		{
			if(x[p-1]==y[q-1])
			{
				c[p][q]=c[p-1][q-1]+1;	
			}
			else if(c[p-1][q]>=c[p][q-1])
			c[p][q]=c[p-1][q];
			else
			c[p][q]=c[p][q-1];
		}
	}
	for(int o=0;o<m;++o)
	{
		cout<<"\n";
		for(int k=0;k<n;++k)
		cout<<" "<<c[o][k];
	}

		cout<<"\nNO OF SIMILAR LETTERS: "<<c[m-1][n-1];
	
}

int main()
{
	char x[30],y[30];
	cout<<"ENTER STRING 1: ";
	gets(x);
	cout<<"ENTER STRING 2: ";
	gets(y);
	LCS(x,y);
	
}
