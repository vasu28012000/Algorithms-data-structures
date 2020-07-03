#include<iostream>
using namespace std;
bool subsum(int ar[20],int size,int sum)
{
	bool b[size+1][sum+1];
	int i,j;
	for(i=0;i<size+1;++i)
	b[i][0]=true;
	for(i=1;i<sum+1;++i)
	b[0][i]=false;
	for(i=1;i<size+1;++i)
	{
		for(j=1;j<sum+1;++j)
		{
			if(ar[i-1]>j)
			b[i][j]=b[i-1][j];
			else 
			b[i][j]=b[i-1][j]||b[i-1][j-ar[i-1]];
		}
	}
	cout<<"\n"<<"  ";
	for(i=0;i<sum+1;++i)
	cout<<i<<"  ";
	cout<<"\n";
		for(i=0;i<size+1;++i)
	{
		cout<<"\n";
		if(i==0)
		cout<<0<<"  ";
		else
		cout<<ar[i-1]<<"  ";
		for(j=0;j<sum+1;++j)
		{
			cout<<b[i][j]<<"  ";
		}
	}
	cout<<"\n\n";
	return b[size][sum];	
}
int main()
{
	int ar[20],n,i,sum;
	cout<<"ENTER SUM: ";
	cin>>sum;
	cout<<"ENTER SIZE: ";
	cin>>n;
	cout<<"ENTER ELEMENTS OF THE SET: ";
	for(i=0;i<n;++i)
	{
		cin>>ar[i];
	}
	if(subsum(ar,n,sum))
	cout<<"SUCH SUBSET EXISTS!!";
	else
	cout<<"NO SUCH SUBSET EXISTS";
}
