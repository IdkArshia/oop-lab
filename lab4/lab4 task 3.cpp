#include <iostream>
#include <string>

using namespace std;

class SmartDevice {
private:
    string name;
    string type;
    bool status;  // if true then on, else off

public:
    
    SmartDevice(string name, string type, bool status = false) {
        this->name = name;
        this->type = type;
        this->status = status;

        cout << name << " power statu: OFF\n" << endl;
    }

    
    void powerOn() {
        status = true;
        cout << name << " power status: ON\n" << endl;
    }

    
    void powerOff() {
        status = false;
        cout << name << " power status: OFF\n" << endl;
    }

    
    ~SmartDevice() {
        cout << name << " is finally Powering down for the last time\n" << endl;
    }
};

int main() {
   
    SmartDevice Phone("Samsung Galaxy A32", "Smart Phone");
    SmartDevice Console("Xbox 360", "Gaming console");
    SmartDevice Laptop("macbook pro 2018", "laptop");

   
    Phone.powerOn();
    Phone.powerOff();
     
    Console.powerOn();
    Console.powerOff();
    
    Laptop.powerOn();
    Laptop.powerOff();
   
    

    return 0;
}