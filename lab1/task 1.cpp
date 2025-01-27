#include<iostream>
using namespace std;
int main(){
	int num,flag=0;
	cout<<"enter a number: ";
	cin>>num;
	if (num==2)
	{
		cout<<"prime number";
	}
	else{
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				cout<<"not a prime number";
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"prime number";
		}
	}
	
}
