#include<iostream>
#include<fstream>
using namespace std;

int main() {
    fstream file("draft.txt", ios::in | ios::out);
    if (!file) {
        cout << "couldn't open file\n";
        return 1;
    }

    string word;
    streampos pos = file.tellg();

    while (file >> word) {
        if (word == "teh") {
            file.seekp(pos);
            file << "the";
            cout<<"replacement successful";
            break;
        }
        pos = file.tellg();
    }

    file.close();
    return 0;
}
