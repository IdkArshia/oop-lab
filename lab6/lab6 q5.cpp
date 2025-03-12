#include<iostream>
#include<string>
using namespace std;

class Vehicle{
	public:
	string make;
	string model;
	int year;
	Vehicle(string m, string mo, int y): make(m), model(mo), year(y){
	};
	
};
class Car: public Vehicle{
	public:
	int No_ofDoors;
	string FuelEfficiency;
	Car(string m, string mo, int y, int d, string fe): Vehicle(m,mo,y), No_ofDoors(d), FuelEfficiency(fe){
	};
};

class ElectricCar:public Car{
	public:
	string batteryLife;
	ElectricCar(string m, string mo, int y, int d, string fe, string bl): Car(m,mo,y,d,fe), batteryLife(bl){
	};
	void display(){
		cout<<"Make:"<<make<<"\nModel: "<<model<<"\nYear: "<<year<<"\nNo.of Doors: "<<No_ofDoors<<"\nFuel Efficiency: "<<FuelEfficiency<<"\nBattery Life: "<<batteryLife;
	}
};
int main()
{
	ElectricCar c1("Volkswagen","ID.3",2025,5,"32 MPG","10-15 years");
	c1.display();
}
