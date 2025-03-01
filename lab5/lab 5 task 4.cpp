#include<iostream>
#include<string>
using namespace std;

class Airport{
	private:
	string name;
	string location;
	public:
		Airport(const string& name,const string& location): name(name), location(location){};
		string getName()
		{
			return name;
		}
		string getLocation()
		{
			return location;
		}
		void display() const {
        cout << "Airport: " << name << " (" << location << ")" << endl;
    }
};

class Flight {
private:
    string flightNumber;
    string status;
    Airport* airports[3];
    int airportCount;

public:
    Flight(const string& flightNumber) : flightNumber(flightNumber), status("Scheduled"), airportCount(0) {}
    void addAirport(Airport* airport) {
        if (airportCount < 3) {
            airports[airportCount++] = airport;
        } else {
            cout << "Cannot add more airports." << endl;
        }
    }

    void setStatus(const string& newStatus) {
        status = newStatus;
    }

    void display() const {
        cout << "Flight: " << flightNumber << "  Status: " << status << endl;
        cout << "Route:" << endl;
        for (int i = 0; i < airportCount; ++i) {
            airports[i]->display();
        }
    }
};

int main() {
    Airport karachi("Jinnah International", "Karachi");
    Airport islamabad("Islamabad International", "Islamabad");
    Airport london("Heathrow", "London");
    Flight pk303("PK-303");
    pk303.addAirport(&karachi);
    pk303.addAirport(&islamabad);
    pk303.addAirport(&london);
    pk303.setStatus("Diverted to Islamabad");
    pk303.display();
    return 0;
}

		
