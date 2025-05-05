#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string name, msg;
	ofstream outfile;
	cout<<"enter the recipient's name: ";
	cin>>name;
	cin.ignore();
	cout<<"enter the short message: ";
	getline(cin,msg);
	outfile.open("greeting.txt",ios::app);
	if(!outfile){
		cout<<"error: file was not opened successfully ";
		return 0;
	}
	outfile<<"Dear "<<name<<","<<endl<<msg<<endl<<"Best Regads!";
	outfile.close();
	
}