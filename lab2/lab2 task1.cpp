#include<iostream>
using namespace std;
typedef struct{
	string title;
	string author;
	int publication_year;
	string genre;
}book;
book arr[20];
int i=0;
void searchByTitle(string title_,book arr[],int i)
{
	for(int j=0;j<i;j++)
	{
		if (arr[j].title==title_)
		{
			cout<<"title: "<<arr[j].title<<endl;
			cout<<"author: "<<arr[j].author<<endl;
			cout<<"publication year: "<<arr[j].publication_year<<endl;
			cout<<"genre: "<<arr[j].genre<<endl;	
		}
	}
}
void searchByAuthor(string author_,book arr[],int i)
{
	for(int j=0;j<i;j++)
	{
		if (arr[j].author==author_)
		{
			cout<<"title: "<<arr[j].title<<endl;
			cout<<"author: "<<arr[j].author<<endl;
			cout<<"publication year: "<<arr[j].publication_year<<endl;
			cout<<"genre: "<<arr[j].genre<<endl;	
		}
	}
}
void addBook(book arr[],int i)
{
	cout<<"enter book title:";
	cin>>arr[i].title;
	cout<<"enter author:";
	cin>>arr[i].author;
	cout<<"enter publication year:";
	cin>>arr[i].publication_year;
	cout<<"enter genre:";
	cin>>arr[i].genre;	
}
void update(int i,string title_, book arr[])
{
	for(int j=0;j<i;j++)
	{
		if (arr[j].title==title_)
		{
			cout<<"enter updated title: ";
			cin>>arr[j].title;
			cout<<"enter updated author: ";
			cin>>arr[j].author;
			cout<<"enter updated publication year: ";
			cin>>arr[j].publication_year;
			cout<<"genre: ";
			cin>>arr[j].genre;	
		}
	}
	
}
int main()
{
	int choice;
	string author,title;
	while(1)
	{
		
	cout<<"enter 1 to add book, 2 to search by author, 3 to search by title, 4 to update a book and 5 to exit: ";
	cin>>choice;
	switch (choice)
	{
		case 1:
			addBook(arr,i);
			i=i+1;
			break;
		case 2:
			cout<<"enter author: ";
			cin>>author;
			searchByAuthor(author,arr,i);
			break;
		case 3:
			cout<<"enter title: ";
			cin>>title;
			searchByTitle(title,arr,i);
			break;
		case 4:
			cout<<"enter title of book you want to update: ";
			cin>>title;
			update(i,title,arr);
			break;
		case 5:
			return 0;
			
			
			
	}
}
	
}
