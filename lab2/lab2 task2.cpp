#include<iostream>
#include<string>
using namespace std;
typedef struct{
	string name;
	int price;
	int quantity;
	int ID;
	
}product;
	product arr[20];
	int i=0;

void add(string n,int p,int q, int id,int i,product arr[])
{
	arr[i].name=n;
	arr[i].price=p;
	arr[i].quantity=q;
	arr[i].ID=id;
	
}
void info(int id,int i,product arr[])
{
	for(int j=0;j<i;j++)
	{
		if (arr[j].ID==id);
		{
			cout<<"name:"<<arr[j].name<<endl;
			cout<<"price: "<<arr[j].price<<endl;
			cout<<"quantity: "<<arr[j].quantity<<endl;
		}
		
	}
}

void update(int id,int p, int q, int i,product arr[])
{
	for( int j=0;j<i;j++)
	{
		if(arr[j].ID==id)
		{
			arr[j].price=p;
			arr[j].quantity=q;
		}
	}
}
void remove(int id,int i,product arr[])
{
	for(int j=0;j<i;j++)
	{
		if(arr[j].ID==id)
		{
			while(j<i)
			{
				arr[j]=arr[j+1];
				j+=1;
			}
			break;
		}
	}
}
int main()
{

	int i=0;
	int choice,price,quantity,id;
	string name;
	cout<<"enter 1 to add, 2 to display, 3 to update, 4 to remove and 5 to exit: ";
	cin>>choice;
	do{
	switch(choice)
	{
		case 1:
			cout<<"enter name of product: ";
			cin>> name;
			cout<<"enter id of product: ";
			cin>> id;
			cout<<"enter quantity of product: ";
			cin>>quantity;
			cout<<"enter price of product: ";
			cin>>price;
			
			add(name,price,quantity,id,i,arr);
			i=i+1;
			break;
		case 2:
			cout<<"enter id of product: ";
			cin>>id;
			info(id,i,arr);
			break;
		case 3:
			cout<<"enter id of product you want to update: ";
			cin>>id;
			cout<<"enter updated quantity of product: ";
			cin>>quantity;
			cout<<"enter updated price of product: ";
			cin>>price;
			update(id,price,quantity,i,arr);
			break;
		case 4:
			cout<<"enter id of product you want to remove: ";
			cin>>id;
			remove(id,i,arr);
			break;
			}
		cout<<"enter 1 to add, 2 to display, 3 to update, 4 to remove and 5 to exit: "<<endl;;
	cin>>choice;	
		}while(choice!=5);
	  
			
			
	 
}