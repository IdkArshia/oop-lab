#include<iostream>
using namespace std;
template <typename T>
	void swapFunction(T &a, T &b){
		T temp;
		temp=a;
		a=b;
		b=temp;
	}
int main(){
	int a=1, b=2;
	swapFunction(a,b);
	cout<<a;
	cout<<b;
	char c='c';
	char d='d';
	swapFunction(c,d);
	cout<<c;
	cout<<d;
}

