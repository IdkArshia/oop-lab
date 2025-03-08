#include<iostream>
#include<string>
using namespace std;

class Character{
	public:
	int health;
	int damage;
	
	Character(int h, int d): health(h), damage(d) {};
	 void display_c()
	 {
	 	cout<<"Health: "<<health<<"\nDamage: "<<damage;
	 }
};

class Enemy: public Character{
	public:
		Enemy(int h, int d): Character(h,d){
		};
		
		void display_e(){
			display_c();
		}
};

class Player: public Character{
	public:
		Player(int h, int d): Character(h,d){
		};
		
		void display_p(){
			display_c();
		}
};

class Wizard:public Player{
	public:
	string magicPower;
	string spells;
	
	Wizard(int h, int d, string mp, string s): Player(h,d){
		magicPower=mp;
		spells=s;
	};
	
	void display_w()
	{
		display_p();
		cout<<"\nMagic Power: "<<magicPower<<"\nSpells: "<<spells;
	}
};
int main()
{
	Wizard w1(80,20,"Water Bender","Abra ka Dabra");
	w1.display_w();
}