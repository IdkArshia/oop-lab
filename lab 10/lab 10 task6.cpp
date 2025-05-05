#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main(){
	ifstream file("secret.txt");
	if(!file){
		cout<<"error:file not found";
		return 0;
	}
	char ch;
	int count;
	while(file.get(ch)){
		if(isupper(ch)){
			count++;
		}
	}
	file.close();
	cout<<"total signals: "<<count;
	return 0;
}