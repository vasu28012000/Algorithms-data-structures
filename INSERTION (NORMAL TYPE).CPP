#include <iostream>
using namespace std;
int main()
{
    int ar[20],i,j,tmp,n,c=0,ct=0;
    cout<<"ENTER NO OF ELEMENTS TO BE ENTERED: ";
    cin>>n;
    for(i=0;i<n;++i)
    {
        cout<<"ENTER ELEMENT "<<i+1<<": ";
        cin>>ar[i];
    }
    for(i=1;i<n;++i)
    {
        tmp=ar[i];
        j=i-1;
        while(j>=0&&ar[j]>tmp)
        {
            ar[j+1]=ar[j];
            j=j-1;
            c++;
            ct++;
        }
        ar[j+1]=tmp;
        
         for(int p=0;p<n;++p)
        {
        cout<<ar[p]<<", ";
      
        }
          cout<<"   COMPARISONS: "<<ct;
        ct=0;
        cout<<"\n";
    }
    for(i=0;i<n;++i)
    {
        cout<<ar[i]<<", ";
        
    }
    cout<<"\nNO OF COMPARISONS: "<<c;
    return 0;
}

