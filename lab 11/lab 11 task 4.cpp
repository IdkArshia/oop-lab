#include<iostream>
using namespace std;

class BankAccount{
	double balance;
	public:
		BankAccount( double b){
			balance=b;
		}
		void withdrawal(double amt){
			try{
				cout<<"current funds: "<<balance<<endl;
			if(amt>balance){
				throw runtime_error("insufficient funds to complete withdrawal");
			}
			balance-=amt;
			cout<<"withdrawal successful! New Balance: "<<balance<<endl;	
			}
			catch(runtime_error &e){
				cout<<"Error: "<<e.what()<<endl;
			}
			
			
		}
};
int main(){
	BankAccount b1(500);
	b1.withdrawal(6000);
	BankAccount b2(6000);
	b2.withdrawal(500);
}