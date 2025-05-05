#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream file;
	file.open("diary.txt",ios::app);
	if(!file){
		cout<<"error: cannot open file";
		return 1;
	}
	string line;
	cout<<"write your diary entry, type exit to end"<<endl;
	while(1){
		getline(cin,line);
		if(line=="exit") break;
		file<<line<<endl;
	}
	file.close();
	cout<<"entry successfully stored";
	return 0;
}