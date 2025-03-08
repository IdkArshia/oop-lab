#include<iostream>
#include<string>
using namespace std;

class Book{
	public:
		string title;
		string author;
		string publisher;
		
		Book(string ti,string au,string pu): title(ti),author(au),publisher(pu) {
		};
		 
		void display()
		{
			cout<<"Title: "<<title<<"\nAuthor: "<<author<<"\nPublisher: "<<publisher;
			
		}
};
class FictionBook:public Book{
	public:
		string genre;
		string protagonist;
		
		FictionBook(string ti,string au,string pu,string ge, string pr) : Book(ti,au,pu)
		{
			genre=ge;
			protagonist=pr;
		}
		
		void display(){
			Book::display();
			cout<<"\ngenre: "<<genre<<"\nprotagonist: "<<protagonist;
		}
};
int main()
{
	FictionBook b1("The cruel prince","Holly Black","Brown Books","fantasy fiction","Jude Duarte");
	b1.display();
}