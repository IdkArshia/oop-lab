#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream file;
	file.open("signup.txt",ios::app);
	if(!file){
		cout<<"error: cannot open file";
		return 1;
	}
	string name,em;
	int ch=1;
	do{
		cout<<"Name: ";
		getline(cin,name);
		cout<<"Email: ";
		cin>>em;
		file<<"Name: "<<name<<", Email: "<<em<<endl;
		cout<<"enter 1 to keep adding or 0 to exit: ";
		cin>>ch;
		cin.ignore();
	} while(ch!=0);
	file.close();
	return 0;
}
	