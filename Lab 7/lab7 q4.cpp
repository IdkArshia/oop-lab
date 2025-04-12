#include<iostream>
#include<string>
using namespace std;

class Course;
class Professor;
class Student;
class person{
	string name;
	int id;
	string address;
	string phnNum;
	string email;
	public:
		person(string n,int id,string ad,string pn, string em):name(n),id(id),address(ad),phnNum(pn),email(em){
		};
		virtual void displayInfo(){
			cout<<"Name: "<<name<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"Address: "<<address<<endl;
			cout<<"Phone Number: "<<phnNum<<endl;
			cout<<"E-mail: "<<email<<endl;
		}
		void updateInfo(string n,int id, string ad, string pn,string e){
			name=n;
			this->id=id;
			address=ad;
			phnNum=pn;
			email=e;
		}
		
	
};
class Course{
	public:
		int courseId;
		string courseName;
		int credits;
		Professor *Instructor;
		string schedule;
		Student *students[3];
		int cnt=0;	
	
		Course(int id,string n,int c,Professor *p,string sch){
			courseId=id;
			courseName=n;
			credits=c;
			Instructor=p;
			schedule = sch;
		}
		string getCourseName() const {
	return courseName;
}
		
		void calculateGrade(int marks){
			if(marks>=90)cout<<"Grade:A"<<endl;
			else if(marks>=80)cout<<"Grade:B"<<endl;
			else if(marks>=70)cout<<"Grade:C"<<endl;
			else if(marks>=60)cout<<"Grade:D"<<endl;
			else cout<<"Grade:F"<<endl;
		}
		
};
class Student:public person{
	public:
	Course *coursesEnrolled[3];
	float GPA;
	int enrollmentYear;
	int count=0;
	
		Student(string n,int id,string ad,string pn,string em,float g,int ey):person(n,id,ad,pn,em){
			GPA=g;
			enrollmentYear=ey; 
			}
		void displayInfo() override{
			person::displayInfo();
			cout<<"GPA: "<<GPA<<endl;
			cout<<"Enrollment Year: "<<enrollmentYear<<endl;
			for (int i=0;i<count;i++){
				cout << "Course: " << coursesEnrolled[i]->getCourseName() << endl;
			}
		}
};

class Professor:public person{
	Course *coursesTaught[3];
	string department;
	int salary;
	public:
		Professor(string n,int id,string ad,string pn, string em,string dep,int sal):person(n,id,ad,pn,em){
			department=dep;
			salary=sal;
		}
		void displayInfo() override{
			person::displayInfo();
			cout<<"department: "<<department<<endl;
			cout<<"salary: "<<salary<<endl;
			
		}
};
class Staff:public person{
	string department;
	int salary;
	string position;
	public:
		Staff(string n,int id,string ad,string pn, string em,string dep,int sal,string pos):person(n,id,ad,pn,em){
			department=dep;
			salary=sal;
			position=pos;
		}
		void displayInfo() override{
			person::displayInfo();
			cout<<"department: "<<department<<endl;
			cout<<"salary: "<<salary<<endl;
			cout<<"position: "<<position<<endl;
			
		}
};
void registerStudent(Student &s, Course &c){
			s.coursesEnrolled[s.count++]=&c;
			c.students[c.cnt++]=&s;
			cout<<"student registered successfully";
		}

int main(){
	Student s1("Arshia",0012,"karachi","0323-2989698","arshia@gmail.com",3.5,2024);
	Professor p1("Sameer Faisal",0001,"Karachi","0312-3456234","sameer@gmail.com","AI",125000);
	Staff st1("Ahmed",0015,"karachi","0987-5678234","ahmed@gmail.com","Accounts",80000,"management");
	
	Course c1(0001,"PF",3,&p1,"2 classes Monday");
	
	registerStudent(s1,c1);
	s1.displayInfo();
	p1.displayInfo();
	st1.displayInfo();
	
	c1.calculateGrade(89);
}