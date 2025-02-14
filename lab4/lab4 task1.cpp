#include<iostream>
#include<string.h>
using namespace std;
class book{
	int *data;
	string title;
	string author;
	int price;
	public:
		book()
		{
			title="untitled";
			author="Anonymous";
			price=0;
		}
		book(string title, string author, int price)
		{
			this->title=title;
			this->author=author;
			this->price=price;
		}
		book(book &b)
		{
			title=b.title;
			author=b.author;
			price=b.price;
			data=b.data;
			
		}
		book(string t)
		{
			title=t;
			author="unknown";
			price=0;
		}
		void display()
		{
			cout<<"title: "<<title<<endl;
			cout<<"author: "<<author<<endl;
			cout<<"price: "<<price<<endl;
			cout<<"address"<<data<<endl;
		}
		
};
int main()
{
	book b1;
	b1.display();
	book b2("abc","arshia",123);
	b2.display();
	// copy b2 data into b3
	book b3(b2);
	b3.display();
	book b4("idk");
	b4.display();
	
}
