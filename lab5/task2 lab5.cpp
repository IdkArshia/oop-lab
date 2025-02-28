#include <iostream>
#include <string>
using namespace std;

class Battery {
private:
    int capacity;  

public:
    Battery(int cap) : capacity(cap) {}
    
    int getCapacity() const {
        return capacity;
    }
    
	void getDetails() const {
		cout<<"Battery: "<<capacity<<"mAh";
        
    }
};

class Smartphone {
private:
    string name;
    const Battery& battery;

public:
   
    Smartphone(string phoneName, const Battery& phoneBattery)
        : name(phoneName), battery(phoneBattery) {}

    void showDetails() const {
    cout << "Smartphone: " << name <<endl;
    battery.getDetails();
    }
};

int main() {
    Battery battery(5000);
    Smartphone phone("Galaxy X", battery);

    phone.showDetails();

    return 0;
}

