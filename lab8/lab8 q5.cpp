#include<iostream>
#include<string>
using namespace std;

class Student;
float calculateAverageGrade(const Student& s);
class Student{
private:
string name;
float grades[3];
public:
Student(string studentName,float g1,float g2,float g3){
name=studentName;
grades[0]=g1;grades[1]=g2;grades[2]=g3;
}
friend class Teacher;
friend float calculateAverageGrade(const Student& s);
void display()const{
cout<<"Student Name: "<<name<<endl;
cout<<"Grades: "<<grades[0]<<", "<<grades[1]<<", "<<grades[2]<<endl;
}
};

class Teacher{
public:
void update(Student& s,int index,float newGrade){
cout<<"grade updated "<<endl;
s.grades[index]=newGrade;
}
};
float calculateAverageGrade(const Student& s){
float sum=s.grades[0]+s.grades[1]+s.grades[2];
return sum/3;
}

int main(){
Student s1("Arshia",58.5,62.0,49.0);
cout<<"Initial Grades:\n";
s1.display();
float avg=calculateAverageGrade(s1);
cout<<"Initial Average: "<<avg<<endl<<endl;
Teacher SirSameer;
SirSameer.update(s1,2,65.0);
cout<<"\nUpdated Grades:\n";
s1.display();
float newAvg=calculateAverageGrade(s1);
cout<<"Updated Average: "<<newAvg<<endl;
return 0;
}
