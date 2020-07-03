#include<iostream>
using namespace std;
int power(int num,int p)
{
	if(p==0)
	return 1;
	else
	return num*power(num,p-1);
}
int main()
{
	int n,p;
	cout<<"ENTER BASE: ";
	cin>>n;
	cout<<"ENTER POWER: ";
	cin>>p;
	cout<<"RESULT: "<<power(n,p);
}
