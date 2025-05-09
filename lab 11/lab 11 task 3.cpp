#include<iostream>
using namespace std;
template <typename T, typename U>
class pairx{
	private:
		T a;
		U b;
	public:
		pairx(T a, U b):a(a),b(b){
		};
		void display(){
			cout<<a<<endl<<b;
		}
};
int main(){
	int x=3;
	string y="hello";
	pairx<int,string> p1(x,y);
	p1.display();
}