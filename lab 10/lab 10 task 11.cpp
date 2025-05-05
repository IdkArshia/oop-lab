#include<iostream>
#include<fstream>
#include<cctype>
#include<sstream>
using namespace std;

int main() {
    ifstream in("article1.txt");
    if (!in) {
        cout<<"Couldn't open article.txt\n";
        return 1;
    }
    int chars=0, words=0, lines=0, punct=0;
    string word;
    string line;
    while (getline(in, line)) {
        lines++;
        chars += line.length();
        for (char c : line) {
            if (ispunct(c)) punct++;
        }
        istringstream iss(line);
        while (iss >> word) words++;
    }
    in.close();
    ofstream out("report.txt");
    if (!out) {
        cout<<"Couldn't create report.txt\n";
        return 1;
    }
    out<<"Article Quality Report\n";
    out<<"Total characters: "<<chars<<'\n';
    out<<"Total words: "<<words<<'\n';
    out<<"Total lines: "<<lines<<'\n';
    out<<"Punctuation marks: "<<punct<<'\n';
    out.close();
    cout<<"Analysis saved to report.txt\n";
    return 0;
}
