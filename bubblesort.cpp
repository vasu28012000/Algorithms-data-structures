#include<iostream>
using namespace std;
	int bubbleSort(int a[],int n)
	{
			int pass=0,temp;
			for(int i = 0; i<n; i++) {
   			for(int j = i+1; j<n; j++)
   			{
      			if(a[j] < a[i]) {
         			temp = a[i];
         			a[i] = a[j];
         			a[j] = temp;
      		}
   			}
   			pass++;
		}
		return pass;
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
	int p=bubbleSort(ar,n);
	cout<<"\n";
	for(i=0;i<n;++i)
	cout<<ar[i]<<", ";
	cout<<"\nNo of passes: "<<p;
}
