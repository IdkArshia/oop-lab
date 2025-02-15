#include<iostream>
using namespace std;
class circle{
	double radius;
	double pi=3.14159;
	public:
		void setRadius(int r)
		{
			radius=r;
		}
		void getRadius()
		{
			cout<<radius;
		}
		float getArea()
		{
			float area=pi*radius*radius;
			return area;
		}
		int getDiameter()
		{
			int dia=radius*2;
			return dia;
		}
		float getCircumference()
		{
			float circumf=2*pi*radius;
			return circumf;
		}
		
	
};
int main()
{
	int r;
	cout<<"enter radius: ";
	cin>>r;
	circle c1;
	c1.setRadius(r);
	cout<<"Area="<<c1.getArea()<<endl;
	cout<<"Diameter="<<c1.getDiameter()<<endl;
	cout<<"Circumference="<<c1.getCircumference()<<endl;
}