#include<iostream>
using namespace std;
class BoardMarker{
	
	bool refillable;
	bool inkStatus;

	public:
		string company;
		string color;	
		void setter(bool r, bool i){
			refillable=r;
			inkStatus=i;
		}
		void getter(){
			cout<<refillable<<endl;
			cout<<inkStatus<<endl;
		}
		void write()
		{
			if(inkStatus==false)
			{
				cout<<"writing is not possible"<<endl;
			}
			else{
				cout<<"proceed with writing"<<endl;
			}
		}
		void refill()
		{
			if(refillable==false)
			{
				cout<<"Ink cannot be refilled"<<endl;
			}
			else{
				cout<<"ink refilled"<<endl;
				refillable=false;
			}
		}
};
int main(){
	BoardMarker b1;
	BoardMarker b2;
	BoardMarker b3;
	b1.setter(true,false);
	b2.setter(false,false);
	b3.setter(true,true);
	b1.getter();
	b2.getter();
	b3.getter();
	b1.write();
	b2.write();
	b3.write();
	b1.refill();
	b2.refill();
	b3.refill();
	
	
}

