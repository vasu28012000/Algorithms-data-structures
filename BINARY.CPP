#include<iostream> 
#include<stdlib.h>
#include<time.h>
using namespace std; 
int binarySearch(int arr[], int p, int r, int num) { 
   if (p <= r) { 
      int mid = (p + r)/2; 
      if (arr[mid] == num)   
         return mid ; 
      if (arr[mid] > num)  
         return binarySearch(arr, p, mid-1, num);            
      if (arr[mid] > num)
         return binarySearch(arr, mid+1, r, num); 
   } 
   return -1; 
} 
int main(void) { 
  srand(time(NULL));
	int arr[20],x;
	cout<<"ENTER ELEMENT TO BE SEARCHED: ";
	cin>>x;  
    int n =20;
	for(int i=0;i<n;++i)
	arr[i]=rand()%10; 
   int index = binarySearch (arr, 0,n-1,x); 
   if(index == -1)
      cout<<x<<" NOT PRESENT!";
   else
      cout<<x<<" PRESENT AT: "<< index <<" IN ARRAY"; 
   return 0; 
}
