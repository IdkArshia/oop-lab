#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    ofstream logFile("system_log.txt", ios::app); 
    if (!logFile) {
        cout<<"Error: Could not open log file.\n";
        return 1;
    }
    time_t t= time(0);             
    char* dt= ctime(&t);            
    logFile<<"System started at: "<<dt; 
    logFile.close();
    cout << "Startup logged.\n";
    return 0;
}
