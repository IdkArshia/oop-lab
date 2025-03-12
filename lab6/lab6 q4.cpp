#include<iostream>
#include<string>
using namespace std;

class Person{
	public:
		string name;
		int age;
};
 class Student: public Person{
 	public:
 		int studentId;
 		int gradeLevel;
 };
 class Teacher: public Person{
 	public:
 		string subject;
 		string roomNo;
 };
 class GraduateStudent: public Student, public Teacher{
 	public:
 		GraduateStudent(string n, int a,int id, int g, string s, string rn){
 			name=n;
 			age=a;
 			studentId=id;
 			gradeLevel=g;
 			subject=s;
 			roomNo=rn;
 			
		 }
 		void display(){
 			cout<<"Name: "<<Name;
 			cout<<"\nStudent ID: "<<studentId;
 			cout<<"\nGrade Level: "<<gradeLevel;
 			cout<<"\nSubject: "<<subject;
 			cout<<"\nRoom Number: "<<roomNo;
		 }
 };
 int main()
 {
 	GraduateStudent s1("Arshia",18,"24k-0012",10,"calculus","E-34");
 	s1.display();
 }