#include <iostream>
#include <string>

using namespace std;

class CricketPlayer {
private:
    string name;
    int JerseyNumber;
    float BattingAverage;
    int matches;
    int runs;

public: 
void displayStats() {
        cout << "\nPlayer Name: " << name << endl;
        cout << "Jersey Number: " << JerseyNumber << endl;
        cout << "Batting Average: " << BattingAverage << endl;
        cout << "Total Matches Played: " << matches << endl;
        cout << "Total Runs: " << runs << endl;
        
    }
    void improveAverage(int runs) {
        this->BattingAverage += runs;
    }
    
    void playMatch(int runsScored) {
    runs += runsScored; 
    matches++;         
    BattingAverage = runs / float(matches); 
}
 CricketPlayer(string name, int JerseyNumber, float BattingAverage) {
        this->name = name;
    	this->JerseyNumber = JerseyNumber;
    	this->BattingAverage = BattingAverage;
    	this->matches = 50;
    	this->runs = 2800;
        
    }


};

int main() {
    CricketPlayer p1("Babar Azam", 56, 76.5);
    CricketPlayer p2("Muhammad Rizwan", 16, 69.4);
    CricketPlayer p3("Saim Ayub", 98, 46.67);
    
    p1.improveAverage(120);
    p2.improveAverage(50);
    p3.improveAverage(80);
    
    p1.playMatch(113);
    p2.playMatch(45);
    p3.playMatch(77);
    
    cout<<"The Updated Player Stats are: "<<endl;
    p1.displayStats();
    p2.displayStats();
    p3.displayStats();
    
    return 0;
}