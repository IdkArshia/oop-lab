#include <iostream>
using namespace std;

class TrafficSystem {
private:
    int cars;
    float delay;

public:
    TrafficSystem(int c=0,float d=0){
        cars=c;
        delay=d;
    }

    TrafficSystem operator+(int extraCars){
        return TrafficSystem(cars+extraCars, delay);
    }

    TrafficSystem operator-(int goneCars){
        int newCars = cars-goneCars;
        if (newCars < 0) newCars=0;
        return TrafficSystem(newCars,delay);
    }

    TrafficSystem operator*(int n){
        return TrafficSystem(cars, delay * n);
    }

    bool operator==(TrafficSystem other){
        return cars == other.cars;
    }

    void display() {
        cout << "Current Vehicle Count: " << cars << "\n";
        cout << "Estimated Delay Time: " << delay << " minutes\n\n";
    }
};

int main() {
    TrafficSystem roadA(50, 5);
    cout<<"Initial traffic status for Road A:\n";
    roadA.display();
    roadA=roadA+20;
    cout<<"Update: 20 additional vehicles have entered Road A.\n";
    roadA.display();
    roadA=roadA-15;
    cout<<"Update: 15 vehicles have exited Road A.\n";
    roadA.display();
    roadA=roadA*2;
    cout<<"Signal failure. Delay time has doubled.\n";
    roadA.display();
    TrafficSystem roadB(100, 10);
    TrafficSystem roadC(100, 7);
    if (roadB==roadC){
        cout<<"Both roads have same number of vehicles.\n";
    } else {
        cout << "Vehicle counts differ.\n";
    }
    return 0;
}
