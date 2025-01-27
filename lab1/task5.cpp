#include<iostream>
using namespace std;
int main(){
	int num,fac=1;
	cout<<"enter a number: ";
	cin>>num;
	for(int i=2;i<=num;i++)
	{
		fac=fac*i;
	}
	cout<<"factorial: "<<fac;
}