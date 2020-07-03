#include<iostream>
using namespace std;
void sort(int ar[20],int end,int rad)
{
	for(int i=0;i<=end;++i)
	{
		int min=i;
		for(int j=i+1;j<=end;++j)
		{
			if(ar[j]%rad<=ar[min])
			min=j;
			
		}
		int tmp=ar[i];
		ar[i]=ar[min];
		ar[min]=tmp;
	}
}
void radixsort(int ar[20],int start,int end)
{
	int max=ar[start];
	for(int i=start+1;i<=end;++i)
	if(max<ar[i])
	{
		max=ar[i];
	}
	int rad=10;
	for(;max/rad!=0;rad*=10);
	sort(ar,end,rad);
}
int main()
{
	int ar[20],i,n;
	cout<<"Enter the no of elements: ";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cout<<"ENTER ELEMENT "<<i+1<<": ";
		cin>>ar[i];
	}
	radixsort(ar,0,n-1);
	cout<<"\n";
	for(i=0;i<n;++i)
	cout<<ar[i]<<", ";
}
