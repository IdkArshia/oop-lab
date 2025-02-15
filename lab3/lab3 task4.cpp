#include<iostream>
using namespace std;
class StationaryShop
{
	string *items= new string[20];
	double *prices =new double[20];
	int i=0;
	public:
		void addItem(string item, double price)
		{
			*(items+i)=item;
			*(prices+i)=price;
			i=i+1;
		}
		void viewItems()
		{
			for(int j=0;j<i;j++)
			{
				cout<<*(items+j)<<endl;
			}
		}
		void viewItemsAndPrices()
		{
			for(int j=0;j<i;j++)
			{
				cout<<*(items+j)<<"   "<<*(prices +j)<<endl;
			}
		}
		void editprice(string item)
		{
			double upd_p;
			for(int j=0;j<i;j++)
			{
				if(*(items+j)==item)
				{
					cout<<"enter updated price: ";
					cin>>upd_p;
					*(prices+j)=upd_p;
				}
			}
		}
	    void CreateReceipt()
	    {
	    	string items[20];
	    	int quans[20];
	    	int x=0;
	    	string item;
	    	int quan;
	    	int total=0;
	    	
	    	
	    	while(1)
	    	{
	    		cout<<"enter item or e to exit: ";
	    		cin>>item;
	    		if(item=="e")
	    		{
	    			break;
				}
	    		else{
	    			items[x]=item;
	    			cout<<"enter quantity: ";
	    			cin>>quan;
	    			quans[x]=quan;
	    			x+=1;
	    			
	    		for(int j=0;j<i;j++)
	    		{
	    			if (*(items+j)==item)
	    			{
	    				total=total+(*(prices+j)*quan);
					}
				}
			}
		
			} 
			cout<<"    RECIEPT    "<<endl;
			for(int j=0;j<x;j++)
			{
				cout<<items[j]<<"   "<<quans[j]<<endl;
			}
			cout<<"Total: Rs."<<total<<endl;
		}
	
};
int main()
{
	int price;
	string item;
	int choice;
	StationaryShop s1;
	cout<<"1. add Item "<<endl<<"2. view items"<<endl<<"3. view items with prices"<<endl<<"4. edit price"<<endl<<"5. create reciept"<<endl<<"6. exit"<<endl;
	while(1)
	{
		cout<<"enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"enter item: ";
				cin>>item;
				cout<<"enter price: ";
				cin>>price;
				s1.addItem(item,price);
				break;
			case 2:
				s1.viewItems();
				break;
			case 3:
				s1.viewItemsAndPrices();
				break;
			case 4:
				cout<<"enter item to change price: ";
				cin>>item;
				s1.editprice(item);
				break;
			case 5:
				s1.CreateReceipt();
				break;
			case 6:
				return 0;
				
		}
		
	}
}