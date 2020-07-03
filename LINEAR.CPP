#include <iostream> 
#include<stdlib.h>
#include<time.h>
using namespace std; 
  
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    srand(time(NULL));
	int arr[20],x;
	cout<<"ENTER ELEMENT TO BE SEARCHED: ";
	cin>>x;  
    int n =20;
	for(int i=0;i<n;++i)
	arr[i]=rand()%50; 
    int result = search(arr, n, x); 
   if(result == -1)
    cout<<"Element is not present in array" 
   else
   cout<<"Element is present at index " <<result; 
   return 0; 
} 
