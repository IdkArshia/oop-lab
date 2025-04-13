#include<iostream>
#include<string>
using namespace std;

class Speed{
	float speed;
	public:
		Speed(float s){
			speed=s;
		}
		friend class Distance;
};

class Time{
	float time;
	public:
		Time(float t){
			time=t;
		}
		friend class Distance;
};

class Distance{
	float dist;
	public:
		float getDistance(const Speed &s, const Time &t){
			return dist=s.speed* t.time;
		}
};

int main(){
	Speed s1(60);
	Time t1(1.5);
	Distance d;
	cout<<"distance: "<<d.getDistance(s1,t1)<<"km";
}