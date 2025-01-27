#include<iostream>
#include<string>
using namespace std;
int main(){
	int start,i;
	int end;
	int a=0;
	cout<<"enter start range: ";
	cin>>start;
	cout<<"enter end range";
	cin>>end;
	for(i=start;i<=end;i++)
	{
		
		if(a==5)
		{
				cout<<i<<endl;
				a=0;
			
		}
		else
		{
				if(i%2==0)
			{
				cout<<i<<endl;
				a=a+1;
			}
		}
		
	
	}
}