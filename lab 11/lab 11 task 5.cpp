#include<iostream>
using namespace std;
template< typename T>
T findMax(T array[], int size){
	T max=array[0];
	for(int i=1; i<size;i++){
		if(array[i]>max){
			max=array[i];
		}
		return max;
	}
}

int main(){
	int arr[5]={5,6,3,2,4};
	cout<<findMax(arr,sizeof(arr))<<endl;
	string arrs[3]={"cat", "panda","elephant"};
	cout<<findMax(arrs,sizeof(arrs));
}