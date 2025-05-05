#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file("article.txt");
    if(!file){
        cerr<<"Error opening file\n";
        return 1;
    }
    file.seekg(0, ios::end);
    streampos length = file.tellg();
    file.seekg(length / 2);
    string line;
    getline(file, line);
    int count = 0;
    while(getline(file, line) && count < 10){
        cout<<line<<endl;
        count++;
    }
    file.close();
    return 0;
}
