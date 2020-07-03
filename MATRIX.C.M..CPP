#include<iostream>
using namespace std;
int Matrix(int p[], int n) 
{ 
 
    int m[n][n]; 
  
    int i, j, k, L, q; 
  
   
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] =50242; 
            for (k = i; k <= j - 1; k++) 
            { 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 
int main() 
{ 
    int i,n;
	cout<<"Enter the no of matrices: ";
	cin>>n;
	n+=1;
	int arr[n];
	cout<<"ENTER Row 1: ";
	cin>>arr[0];
	for(i=1;i<n;++i)
	{
		cout<<"ENTER COLUMN "<<i<<": ";
		cin>>arr[i];
	}
    cout << "MINIMUM NO OF MULTIPLICATION REQUIRED:  "<< Matrix(arr,n); 
         
} 
  
