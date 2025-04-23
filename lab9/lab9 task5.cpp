#include<iostream>
#include<string>
using namespace std;

class Activity{
	public:
		virtual void CalculateCaloriesBurned()=0;
};
class running{
	double distance;
	double time;
	public:
		running(double d, double t){
	    	distance=d;
	    	time=t;
		}
		void CalculateCaloriesBurned(){
			cout<<"calories burned while walking:"<<(3.5*distance*time)/60<<endl;
		}
};
class cycling{
	double speed;
	double time;
	public:
		cycling(double s, double t){
			speed=s;
			time=t;
		}
		void CalculateCaloriesBurned(){
			cout<<"calories burned while cycling:"<< speed*30*time<<endl;
		}
};
int main(){
	cycling c1(10,2);
	running r1(5,120);
	c1.CalculateCaloriesBurned();
	r1.CalculateCaloriesBurned();
}
