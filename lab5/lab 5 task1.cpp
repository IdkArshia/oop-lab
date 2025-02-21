#include <iostream>
using namespace std;


class DayOfYear {
private:
    int day;
    static const int daysPerMonth[12];
    static const string monthNames[12];

public:
    DayOfYear(int d) {
        if (d < 1 || d > 365) {
            cout<<"invalid day";
            return 0;
        } else {
            day = d;
        }
    }

    void print() const {
        int remaining = day;
        int month = 0;

        while (remaining > daysPerMonth[month]) {
            remaining =remaining -  daysPerMonth[month];
            month++;
        }

        cout << monthNames[month] << " " << remaining << endl;
    }
};

const int DayOfYear::daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string DayOfYear::monthNames[12] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};

int main() {
	cout << "Enter day\n";
	int day;
	cin>>day;
    DayOfYear d1(day);
    
    cout << "Dates:"<<endl;
    d1.print();
    

    return 0;
}
