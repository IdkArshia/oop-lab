#include<iostream>
using namespace std;

int main(){
	int n, d;
	cout<<"enter numerator: ";
	cin>>n;
	try{
		cout<<"enter denominator: ";
		cin>>d;
		if(d==0){
			throw runtime_error("Division by zero");
		}
				cout<<"result:"<<n/d;
	}
		catch(runtime_error &e){
			cout<<"error: "<<e.what()<<endl;
			return 0;
		}
		
	}
	
	