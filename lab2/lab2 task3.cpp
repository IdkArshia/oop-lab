#include <iostream>
using namespace std;
int* createArray(int size) {
    return new int[size]; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = createArray(n);
    return 0;
}
