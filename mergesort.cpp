#include<iostream>
using namespace std;
 void merge(int A[ ] , int start, int mid, int end) {
 
int p = start ,q = mid+1;

int Arr[end-start+1] , k=0;

for(int i = start ;i <= end ;i++) {
    if(p > mid)     
       Arr[ k++ ] = A[ q++] ;

   else if ( q > end)   
       Arr[ k++ ] = A[ p++ ];

   else if( A[ p ] < A[ q ])     
      Arr[ k++ ] = A[ p++ ];

   else
      Arr[ k++ ] = A[ q++];
 }
  for (int p=0 ; p< k ;p ++) {
   
     A[ start++ ] = Arr[ p ] ;                          
  }
}
  void merge_sort (int A[ ] , int start , int end )
   {
           if( start < end ) {
           int mid = (start + end ) / 2 ;           
           merge_sort (A, start , mid ) ;                 
           merge_sort (A,mid+1 , end ) ;              
	         merge(A,start , mid , end );   
   }                    
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
	merge_sort(ar,0,n-1);
	cout<<"\n";
	for(i=0;i<n;++i)
	cout<<ar[i]<<", ";
}
