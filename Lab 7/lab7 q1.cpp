#include<iostream>
#include<string>
using namespace std;

class Account{
	protected:
	int accNum;
	int balance;
	string accHolderName;
	string AccountType;
	string transactions[10];
	int count=0;
	public:
		Account(int an,int bal,string name, string Acctype):accNum(an),balance(bal),accHolderName(name),AccountType(Acctype){
		};
		string deposit(int amt){
			balance+=amt;
			transactions[count]="Rs"+to_string(amt)+"deposited";
			count+=1;
			cout<<"successful deposit";	
		}
		virtual void withdraw(int amt){
			if(balance<amt){
				cout<<"insufficient funds";
			}
			else{
				balance-=amt;
				transactions[count]="Rs"+to_string(amt)+"withdrawn";
				count+=1;
				cout<<"money withdrawn successfully";
			}
			}
		virtual float calculateInterest(float timeinyears)=0;
		void getAccountinfo(){
			cout<<"Account Number:"<<accNum<<endl;
			cout<<"Account Holder Name:"<<accHolderName<<endl;
			cout<<"Account Type:"<<AccountType<<endl;
			}
		virtual void printStatement(){
			for(int i=0; i<count;i++){
				cout<<transactions[i]<<"\n";
			}
		}
		
};
class SavingsAccount: public Account{
	float interestRate;
	int minimumBalance;
	public:
		SavingsAccount(int an,int bal,string name, string Acctype,float ir, int mb):Account(an,bal,name, Acctype),interestRate(ir),minimumBalance(mb){};
		float calculateInterest(float TimeInYears) override {
			if(balance>=minimumBalance){
				float interest= balance*interestRate*TimeInYears;
				balance+=interest;
				transactions[count]="interest of "+to_string(interest)+"added";
			}
			else{
				cout<<"balance below minimum, no interest added";
			}
		}
		void printStatement() override {
			Account::printStatement();
			cout<<"Interest rate:"<<interestRate<<endl;
			cout<<"Minimum Balance Requirement:"<<minimumBalance<<endl;
		}
		void withdraw(int amt) override{
			if(balance-amt<minimumBalance){
				cout<<"can't withdraw. balance will drop minimum";
			}
			else{
				balance-=amt;
				cout<<"withdraw successful\n";
				transactions[count]="Rs"+to_string(amt)+"withdrawn";
				count+=1;
			}
		}	
};
class CheckingAccount : public Account{
	float overDraftLimit;
	float interestRate;
	public:
		CheckingAccount(int an,int bal,string name, string Acctype,float odl, float ir):Account(an,bal,name, Acctype),overDraftLimit(odl),interestRate(ir){
		};
		float calculateInterest(float TimeInYears) override{
			if(balance>0){
				double interest = balance * interestRate * TimeInYears;
				balance+=interest;
				transactions[count]="Interest of"+to_string(interest)+"added";
				count+=1;
			}
			else{
				cout<<"No interest added.Balance is 0 or negative";
				
			}
		}
		void printStatement() override{
			Account::printStatement();
			cout<<"Interest rate:"<<interestRate<<endl;
			cout<<"Over Draft Limit:"<<overDraftLimit<<endl;		
        }
        void withdraw(int amt) override{
        	if(amt<=0 || (balance-amt)< -overDraftLimit){
        		cout<<"overdraft limit exceeded. withdrawl denied";
			}
			else{
				balance-=amt;
				cout<<"withdawl successful\n";
				transactions[count]="Rs."+to_string(amt)+"withdrawn";
				count+=1;
			}
			}
};
 class FixedDepositAccount : public Account{
 	private:
 		string maturityDate;
 		float FixedInterestRate;
 		
 		bool isMatured(){
 			return true;
		 }
		 public:
		 	FixedDepositAccount(int an,int bal,string name, string Acctype,string md, float fir):Account(an,bal,name, Acctype),maturityDate(md),FixedInterestRate(fir){
			 };
			 
			 void withdraw(int amt) override{
			 	if(!isMatured()){
			 		cout<<"cannot withdraw before maturity date:"<<maturityDate<<endl;
				 }
				 else{
				 	if(amt>balance || amt<=0){
				 		cout<<"invalid withdrawal"<<endl;
					 }
					 else{
					 	balance-=amt;
					 	cout<<"successful withdrawal\n";
					 	transactions[count]="Rs"+to_string(amt)+"withdrawn";
					 	count+=1;
					 }
					 
				 }
			 }
	float calculateInterest(float timeInYears) {
    if (!isMatured()) {
        cout<<"Interest cannot be calculated before maturity date: "<<maturityDate<<endl;
    }
    else{
    float interest = balance * FixedInterestRate * timeInYears;
    balance += interest;
    transactions[count] = "Interest of"+to_string(interest)+"added to account";}
}
	void printStatement()override{
		Account::printStatement();
		cout<<"maturity date: "<<maturityDate<<endl;
		cout<<"Fixed Interest Rate: "<<FixedInterestRate<<endl;
	}

 };
 int main(){
 	SavingsAccount sa1(122345,20000,"Arshia","Savings Account",0.05,5000);
 	CheckingAccount ca1(233456,50000,"Sadaf","checking Account",60000,0.05);
 	FixedDepositAccount fad1(344567,1000000,"Azeem","Fixed deposit account","11-May-25",0.05);
 	
 	sa1.getAccountinfo();
 	sa1.calculateInterest(2);
 	sa1.withdraw(5000);
 	sa1.printStatement();
 	cout<<"\n";
 	ca1.getAccountinfo();
 	ca1.calculateInterest(2);
 	ca1.withdraw(5000);
 	ca1.printStatement();
 	cout<<"\n";
 	fad1.getAccountinfo();
 	fad1.calculateInterest(2);
 	fad1.withdraw(5000);
 	fad1.printStatement();
 }

	