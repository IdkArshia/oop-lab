#include<iostream>
#include<string>
using namespace std;

class SmartDevice{
	public:
		virtual void turnOn()=0;
		virtual void turnOff()=0;
		virtual bool getStatus()=0;
		
};
class LightBulb:public SmartDevice{
	public:
	bool isOn;
	int brightness;
	LightBulb(int b){
		isOn=false;
		brightness=b;
	}
	void turnOn(){
		isOn=true;
		cout<<"light has been turned on"<<endl;
	}
	void turnOff(){
		isOn=false;
		cout<<"light has been turned off"<<endl;
	}
	bool getStatus(){
		if(isOn){
			cout<<"light is on"<<endl;
		}
		else{
			cout<<"light is off"<<endl;
		}
		return isOn;
	}
};

class Thermostat:public SmartDevice{
	public:
	bool isOn;
	double temperature;
	Thermostat(double t){
		isOn=false;
		temperature=t;
	}
	void turnOn(){
		isOn=true;
		cout<<"thermostat has been turned on"<<endl;
	}
	void turnOff(){
		isOn=false;
		cout<<"thermostat has been turned off"<<endl;
	}
	bool getStatus(){
		if(isOn){
			cout<<"thermostat is on"<<endl;
		}
		else{
			cout<<"thermostat is off"<<endl;
		}
		return isOn;
	}
};

int main(){
	LightBulb l1(50);
	Thermostat t1(80);
	SmartDevice *d1=&l1;
	SmartDevice *d2=&t1;
	d1->turnOn();
	d1->getStatus();
	d2->turnOff();
	d2->getStatus();
}