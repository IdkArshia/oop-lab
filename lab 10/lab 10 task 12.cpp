#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file("debug.txt");
    if(!file){
        cout<<"Couldn't open the file.\n";
        return 1;
    }
    int offset;
    cout<<"Enter byte offset to jump to: ";
    cin>>offset;
    cout<<"Pointer before seekg(): "<<file.tellg()<<endl;
    file.seekg(offset);
    if (!file){
        cout<<"Invalid offset.\n";
        return 1;
    }
    cout<<"Pointer after seekg(): "<<file.tellg()<<endl;
    cout<<"Next 100 characters from that point:\n";
    for (int i = 0; i < 100 && file; i++) {
        char ch;
        file.get(ch);
        if(file) cout<<ch;
    }
    file.close();
    return 0;
}
