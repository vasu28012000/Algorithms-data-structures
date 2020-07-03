#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int p= partition(arr, low, high);

        quickSort(arr, low, p- 1);  
        quickSort(arr, p+1, high); 
    }
}

int main()
{
	srand(time(NULL));
	int ar[20],i,n;
	cout<<"Enter the no of elements: ";
	cin>>n;
	for(i=0;i<n;++i)
	{
		ar[i]=rand()%20+1;
	}
	quickSort(ar,0,n-1);
	cout<<"\n";
	for(i=0;i<n;++i)
	cout<<ar[i]<<", ";
}
