#include<iostream>
using namespace std;
int main(){
	int size,even=0,odd=0;
	cout<<"enter size of array: ";
	cin>>size;
	int arr[size];
	cout<<"enter "<<size<<" numbers"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
		if(arr[i]%2==0)
		{
			even+=1;
		}
		else{
			odd+=1;
		}
	}
	cout<<even<<" even numbers"<<endl;
	cout<<odd<<" odd numbers";
	
}
	
	