#include<iostream>
#include<string>
using namespace std;

class Currency{
protected:
float amount;
string currencyCode;
float exchangeRateToUSD;
public:
Currency(float amt,string code,float rate):amount(amt),currencyCode(code),exchangeRateToUSD(rate){}
virtual float convertToBase(){
return amount*exchangeRateToUSD;
}
virtual float convertTo(float targetRate){
return (convertToBase()/targetRate);
}
virtual void displayCurrency(){
cout<<amount<<" currencyCode\n";
}
};

class Dollar:public Currency{
public:
Dollar(float amt):Currency(amt,"USD",1.0){}
float convertToBase(){
return amount;
}
void displayCurrency(){
cout<<"USD: $"<<amount<<"\n";
}
};

class Euro:public Currency{
public:
Euro(float amt):Currency(amt,"EUR",1.1){}
float convertToBase(){
return amount*exchangeRateToUSD;
}
void displayCurrency(){
cout<<"EUR: "<<amount<<"\n";
}
};

class Rupee:public Currency{
public:
Rupee(float amt):Currency(amt,"PKR",0.0035){}
float convertToBase(){
return amount*exchangeRateToUSD;
}
void displayCurrency(){
cout<<"PKR: Rs"<<amount<<"\n";
}
};

int main(){
Dollar d(100);
Euro e(100);
Rupee r(1000);

d.displayCurrency();
cout<<"USD to base:"<<d.convertToBase()<<"\n";
cout<<"USD to EUR:"<<d.convertTo(1.1)<<"\n";
e.displayCurrency();
cout<<"EUR to base:"<<e.convertToBase()<<"\n";
cout<<"EUR to PKR:"<<e.convertTo(0.0035)<<"\n";
r.displayCurrency();
cout<<"PKR to base:"<<r.convertToBase()<<"\n";
cout<<"PKR to USD:"<<r.convertTo(1.0)<<"\n";
return 0;
}
