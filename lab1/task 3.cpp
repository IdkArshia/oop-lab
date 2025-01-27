#include<iostream>
#include<string>
using namespace std;
int main(){
	int num1,num2;
	char op;
	cout<<"enter first num: ";
	cin>>num1;
	cout<<"enter second num: ";
	cin>>num2;
	cout<<"enter operation";
	cin>>op;
	if(op=='+')
	{
		
	}
	if(op=='-')
	{
		cout<<num1-num2;
	}
	if(op=='*')
	{
		cout<<num1*num2;
	}
	if(op=='+')
	{
		cout<<num1-num2/(-1);
	}
	if(op=='*')
	{
		cout<<num1/num2;
	}
}