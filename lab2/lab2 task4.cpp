#include<iostream>
using namespace std;
void add(int *n1, int *n2)
{
	int result;
	result=*n1+*n2;
	cout<<result;

}
void subtract(int *n1, int *n2)
{
	int result;
	result=*n1-*n2;
	cout<<result;

}
void multiply(int *n1, int *n2)
{
	int result;
	result=*n1*(*n2);
	cout<<result;

}
void divide(int *n1, int *n2)
{
	int result;
	result=*n1/(*n2);
	cout<<result;

}
int main()
{
	int num1,num2;
	char op;
	cout<<"enter first number: ";
	cin>>num1;
	cout<<"enter second number: ";
	cin>>num2;
	int *n1=&num1;
	int *n2=&num2;
	cout<<"enter operation";
	cin>>op;
	switch (op)
	{
		case '+':
			add(n1,n2);
			break;
		case '-':
			subtract(n1,n2);
			break;
		case '*':
			multiply(n1,n2);
			break;
		case '/':
			divide(n1,n2);
			break;
		
			
	}
	
}