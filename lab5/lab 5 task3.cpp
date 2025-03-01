#include<iostream>
#include<string>
using namespace std;

class MenuItems{
    string name;
    int price;
public:
    MenuItems(const string& name,int p): name(name), price(p) {};
    void display()
    {
        cout << name << "    Rs." << price << endl;
    }
    int getPrice()
    {
        return price;
    }
};

class Payment {
    int amount;
public:
    Payment() : amount(0) {}
    void calculateAmount(MenuItems *items[], int itemCount) {
        amount = 0;
        for (int i = 0; i < itemCount; i++) {
            amount=amount + items[i]->getPrice();
        }
        cout << "Total Bill: Rs." << amount << endl;
    }
};

class Order{
    MenuItems* menu_items[25];
    Payment payment;
    int itemCount;
public:
    Order(): itemCount(0) {}
    void addItem(MenuItems* m){
        if(itemCount >= 25) {
            cout << "Sorry, order is full" << endl;
        } else {
            menu_items[itemCount++] = m;
        }
    }
    void placeOrder()
    {
        cout << "---Order---" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". ";
            menu_items[i]->display();
        }
        payment.calculateAmount(menu_items, itemCount);
    }
};

class Menu{
    MenuItems* menu_items[25];
    static int count;
public:
    void addItem(MenuItems* m )
    {
        if (count < 25) {
            menu_items[count++] = m;
        }
    }
    void removeItem(const MenuItems* m)
    {
        for(int i = 0; i < count; i++) {
            if(menu_items[i] == m) {
                for(int j = i; j < count - 1; j++) {
                    menu_items[j] = menu_items[j + 1];
                }
                menu_items[count - 1] = nullptr;
                count--;
                return;
            }
        }
    }
    void displayItems()
    {
        cout << "------MENU------" << endl;
        for(int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            menu_items[i]->display();
        }
    }
};

int Menu::count = 0;

int main()
{
    Menu menu;
    MenuItems item1("Burger", 150);
    MenuItems item2("Pizza", 300);
    MenuItems item3("Pasta", 250);
    menu.addItem(&item1);
    menu.addItem(&item2);
    menu.addItem(&item3);
    menu.displayItems();
    Order order;
    order.addItem(&item1);
    order.addItem(&item3);
    order.placeOrder();
    return 0;
}
