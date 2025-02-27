#include <iostream>
#include <string>

using namespace std;

class FootballPlayer {
private:
    string name;
    string position;
    int goals;

public:
    
    FootballPlayer() {
        name = "Unknown Player";
        position = "Bench Warmer";
        goals = 0;
        
        cout<<"Default Player: "<< endl;
        cout << "\nname: " << name << endl;
        cout << "\nposition: " << position << endl;
        cout << "\ngoals: " << goals << endl;
    }

   
    FootballPlayer(string name, string position, int goals) {
        this->name = name;
    	this->position = position;
    	this->goals = goals;
        
        cout<<"Parameterized Player: "<<endl;
        cout << "\nname: " << name << endl;
        cout << "\nposition: " << position << endl;
        cout << "\ngoals: " << goals << endl;
    }
    
     FootballPlayer(string name){
        this->name = name;
    	this->position = "Mid Fielder";
    	this->goals = 10;
    	
    	cout<<"Default Argument Player: "<<endl;
    	cout << "\nname: " << name << endl;
        cout << "\nposition: " << position << endl;
        cout << "\ngoals: " << goals << endl;
     }

    
     FootballPlayer(FootballPlayer& p) {
         this->name = p.name;
         this->position = p.position;
         this->goals = p.goals;
        
        cout<<"Cloned Player: "<<endl;
        cout << "\nname " << name << endl;
        cout << "\nposition: " << position << endl;
        cout << "\ngoals: " << goals  << endl;
    }
    
    void boostGoals(int goals) {
        this->goals += goals;
        cout <<"\n"<< name << " has scored " << goals << " more goals! Total goals are now increased to: " << this->goals <<"\nHe must win a Treble this Season!!" <<endl;
    }
};

int main() {
    
    FootballPlayer p1; 
    FootballPlayer p2("Virgil Van Dijk", "Centre Back",35 );
    
    p2.boostGoals(30);
    
    
    FootballPlayer p3("Joshua Kimmich");
    
    
    FootballPlayer p4(p2);  
   
    
    return 0;
}