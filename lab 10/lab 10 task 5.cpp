#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream file;
	file.open("story.txt");
	string word;
	if(file.is_open()){
		while(file>>word){
			cout<<word<<endl;
		}
		file.close();
	}
	else{
		cout<<"file not found";
	}
	return 0;
}