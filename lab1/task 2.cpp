#include<iostream>
using namespace std;
int main(){
	int oop,pf,dld,ict,total,avg;
	cout<<"enter marks for oop: ";
	cin>>oop;
	cout<<"enter marks for pf: ";
	cin>>pf;
	cout<<"enter marks for dld: ";
	cin>>dld;
	cout<<"enter marks for ict: ";
	cin>>ict;
	total=oop+dld+pf+ict;
	avg=total/4;
	if(avg>=90)
	{
		cout<<"Grade: A";
	}
	else if(avg>=80)
	{
		cout<<"Grade: B";
	}
	else if(avg>=70)
	{
		cout<<"Grade: C";
	}
	else if(avg>=60)
	{
		cout<<"Grade: D";
	}
	else
	{
		cout<<"Grade: F";
	}
}
	