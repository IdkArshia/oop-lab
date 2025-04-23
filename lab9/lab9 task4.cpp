#include<iostream>
#include<string>
using namespace std;

class PaymentMethod{
	public:
	virtual void processPayment(double amt)=0;
};

class CreditCard: public PaymentMethod{
	string cardNumber;
	public:
		CreditCard(string c){
			cardNumber=c;
		}
		void processPayment(double amt){
			string c;
			cout<<"enter card number: ";
			cin>>c;
			if(c==cardNumber){
				cout<<"successful payment through card "<<endl;
				return;
			}
			cout<<"card number does not match";
		}
};

class DigitalWallet:public PaymentMethod{
	double balance;
	public:
		DigitalWallet(double b){
			balance=b;
		}
		void processPayment(double amt){
			if(amt<=balance){
				cout<<"successful payment through digital wallet"<<endl;
				cout<<"new balance: "<<balance-amt<<endl;
				return;
			}
			cout<<"insuffecient funds";
		}
};
int main(){
	
	CreditCard c1("123-abc");
	DigitalWallet d1(200000);
	PaymentMethod *p1=&c1;
	PaymentMethod *p2=&d1;
	p1->processPayment(10000);
	p2->processPayment(10000);
	
}