#include<iostream>
#include<string>
using namespace std;

class Vehicle{
	public:
		double rate;
		string model;
		Vehicle(double r, string m):rate(r),model(m){};
		virtual  void getDailyRate()=0;
		virtual void displayDetails()=0;
};
class Car:public Vehicle{
	public:
		Car(double r, string m):Vehicle(r,m){
		};
		void getDailyRate(){
			cout<<"daily rate for this car is:"<<rate<<endl;
	}
		void displayDetails(){
			cout<<"car details\n";
			cout<<"Rate: "<<rate<<endl;
			cout<<"Model: "<<model<<endl;	
		}
	};
class Bike:public Vehicle{
	public:
		Bike(double r, string m):Vehicle(r,m){
		};
		void getDailyRate(){
			cout<<"daily rate for this bike is:"<<rate<<endl;
	}
		void displayDetails(){
			cout<<"bike details\n";
			cout<<"Rate:"<<rate<<endl;
			cout<<"Model: "<<model<<endl;	
		}
	};
	
	int main(){
		Car c1(20000,"abc");
		Bike b1(10000,"qrs");
		Vehicle *v1;
		Vehicle *v2;
		v1=&c1;
		v2=&b1;

		v1->displayDetails();
		v1->getDailyRate();
		v2->displayDetails();
		v2->getDailyRate();
	}
