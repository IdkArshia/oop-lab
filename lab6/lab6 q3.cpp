#include<iostream>
#include<string>
using namespace std;

class Position{
	public:
	int x;
	int y;
	int z;
	
		void setPosition(int x, int y, int z){
			this->x=x;
			this->y=y;
			this->z=z;
		};
};

class Health{
	public:
	int health;
		void setHealth(int health){
			this->health=health;
		};
};

class Character: public Position, public Health{
	public:
		void display()
		{
			cout<<"--position--\nx: "<<x<<"\ny: "<<y<<"\nz: "<<z;		
			cout<<"\nHealth: "<<health;
		}
};
int main()
{
	Character c1;
	c1.setPosition(2,4,5);
	c1.setHealth(78);
	c1.display();
}