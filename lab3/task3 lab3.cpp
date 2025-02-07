#include<iostream>
using namespace std;
class waterbottle{
	float capacity_l;
	float capacity_ml;
	public:
	string madeBy;
	string color;
	void setter(float c_l, float c_ml)
	{
		capacity_l=c_l;
		capacity_ml=c_ml;
	}
	void getter(){
		cout<<"capacity in l: "<<capacity_l;
		cout<<"capacity in ml: "<<capacity_ml;
		
	}
	void updatewater()
	{
		cout<<"enter ml drank: ";
		float x;
		cin>>x;
		capacity_ml=capacity_ml-x;
		capacity_l=capacity_l-(capacity_ml/1000);
		
		
	}
};
int main(){
	waterbottle w1;
	w1.setter()
}
