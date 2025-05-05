#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main(){
	struct student{
		char name[50];
		int id;
		float gpa;
	};
	ofstream file("students.dat.txt",ios::binary);
	if(!file){
		cout<<"error:could not open file";
		return 0;
	}
		char name[50];
		int id;
		float gpa;
		student s1;
	cout<<"enter name for student 1: ";
	cin>>name;
	strcpy(s1.name,name);
	cout<<"enter id for student 1: ";
	cin>>id;
	s1.id=id;
	cout<<"enter gpa for student 1: ";
	cin>>gpa;
	s1.gpa=gpa;
	file.write((char*)&s1,sizeof(s1));
	
	student s2;
	cout<<"enter name for student 2: ";
	cin>>name;
	strcpy(s2.name,name);
	cout<<"enter id for student 2: ";
	cin>>id;
	s2.id=id;
	cout<<"enter gpa for student 2: ";
	cin>>gpa;
	s2.gpa=gpa;
	
	file.write((char*)&s2,sizeof(s2));
	file.close();
	
	student s1r;
	student s2r;
	ifstream ofile("students.dat.txt",ios::binary);
	if(!ofile){
		cout<<"error:could not open file";
		return 0;
	}
	ofile.read((char*)&s1r,sizeof(s1r));
	ofile.read((char*)&s2r,sizeof(s2r));
	cout<<"s1\n";
	cout<<"Name: "<<s1r.name<<"\nId: "<<s1r.id<<"\ngpa: "<<s1r.gpa<<endl;
	cout<<"s2\n";
	cout<<"Name: "<<s2r.name<<"\nId: "<<s2r.id<<"\ngpa: "<<s2r.gpa;
	ofile.close();
	return 0;
}