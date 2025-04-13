#include<iostream>
#include<string>
using namespace std;

class Complex{
	int real;
	int img;
	public:
		Complex(int r,int i){
			real=r;
			img=i;
		}
		void display(){
			if(img>=0){
				cout<<real<<"+"<<img<<"i"<<endl;
			}
			else{
				cout<<real<<img<<"i"<<endl;
			}
			
		}
		Complex operator +(const Complex &c1){
			Complex temp(0,0);
			temp.real=real+c1.real;
			temp.img=img+c1.img;
			return temp;
		}
		Complex operator -(const Complex &c1){
			Complex temp(0,0);
			temp.real=real-c1.real;
			temp.img=img-c1.img;
			return temp;
		}
		Complex operator *(const Complex &c1){
			Complex temp(0,0);
			temp.real=(real*c1.real)-(img*c1.img);
			temp.img=(real*c1.img)+(img*c1.real);
			return temp;
		}
		bool operator==(const Complex&c1){
			if (real==c1.real && img==c1.img){
				return true;
			}
			return false;
		}
		
};
int main(){
	Complex c1(3,4);
	Complex c2(1,4);
	Complex c3=c1+c2;
	cout<<"c1+c2=";
	c3.display();
	c3=c1-c2;
	cout<<"c1-c2=";
	c3.display();
	c3=c1*c2;
	cout<<"c1*c2=";
	c3.display();
	if(c1==c3){
		cout<<"c1 and c3 are equal";
	}
	else{
		cout<<"c1 an c3 are not equal";
	}
	
}