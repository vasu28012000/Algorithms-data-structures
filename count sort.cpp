  #include<iostream>
  using namespace std;
  	int k=0;
void countSort(int A[],int B[],int n)    
{
	int count[k+1],t;
	for(int i=0;i<=k;i++)
	{
		count[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
	   	t = A[i];
		count[t]++;			
	}
	for(int i=1;i<=k;i++)
	{
	    count[i] = count[i]+count[i-1];            
	}
	for(int i=0;i<n;i++)
	{
		t = A[i];
		B[count[t]] = t;          
	    count[t]=count[t]-1;		
	}
}

			int main()
{
	int ar[20],i,n,b[20];
	cout<<"Enter the no of elements: ";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cout<<"ENTER ELEMENT "<<i+1<<": ";
		cin>>ar[i];
		if(ar[i]>k)
		k=ar[i];
	}
	countSort(ar,b,n);
	cout<<"\n";
	for(i=0;i<n;++i)
	cout<<b[i]<<", ";

}
