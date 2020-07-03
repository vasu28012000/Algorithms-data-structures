#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    int ar[20],i=0,j,tmp,n=0,c1=0,ct=0,t=0;
    char ch;
    ifstream f1;
    f1.open("123.txt");
    while(f1)
    {
        f1>>ch;
        switch(ch)
        {
            case ',':ar[n]=t/10;
                    t=0;
                    ++n;
                            break;
            default:t+=ch-48;
                    t*=10;
                            break;
        }
    n+=1;
    }
    for(i=1;i<n;++i)
    {
        tmp=ar[i];
        j=i-1;
        while(j>=0&&ar[j]>tmp)
        {
            ar[j+1]=ar[j];
            j=j-1;
            c1++;
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
    cout<<"\nNO OF COMPARISONS: "<<c1;
    return 0;
}

