#include <iostream>
#include <string>
using namespace std;

class WeekDays {
private:
    string Days[7];
    int CurrentDay;

public:
    
    WeekDays() {
    	Days[0]="Sunday";
    	Days[1]="Monday";
    	Days[2]="Tuesday";
    	Days[3]="Wednesday";
    	Days[4]="Thursday";
    	Days[5]="Friday";
    	Days[6]="Saturday";  
    	CurrentDay=0;
    }

    
    WeekDays(int day) {
        
        CurrentDay = day % 7;
        Days[0]="Sunday";
    	Days[1]="Monday";
    	Days[2]="Tuesday";
    	Days[3]="Wednesday";
    	Days[4]="Thursday";
    	Days[5]="Friday";
    	Days[6]="Saturday";
    }

    string getCurrentDay() {
        return Days[CurrentDay];
    }

    
    string getNextDay() {
        return Days[(CurrentDay + 1) % 7];
    }

    
    string getPreviousDay() {
        return Days[(CurrentDay + 6) % 7];
    }

    
    string getNthDayFromToday(int N) {
        return Days[(CurrentDay + N) % 7];
    }
};

int main() {
    WeekDays today; 
    cout << "Current day: " << today.getCurrentDay() << endl;
    cout << "Next day: " << today.getNextDay() << endl;
    cout << "Previous day: " << today.getPreviousDay() << endl;
    cout << "Day 20 from today: " << today.getNthDayFromToday(20) << endl;

    WeekDays someDay(8);
    cout << "Some day: " << someDay.getCurrentDay() << endl;
    cout << "Next day: " << someDay.getNextDay() << endl;

    return 0;
}
