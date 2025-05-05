#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream file("backup_log.txt",ios::app);
    if (!file) {
        cout<<"can't open file\n";
        return 1;
    }
    string log;
    while(1){
        cout << "Enter log message or type exit: ";
        getline(cin, log);
        if (log=="exit") break;
        file<<log<<'\n';
        cout<<"File size: "<<file.tellp()<<" bytes\n";
    }
    file.close();
    return 0;
}
