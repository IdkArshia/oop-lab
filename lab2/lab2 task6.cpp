#include <iostream>
using namespace std;

void append(int*& array, int& length, int& capacity, int value);
int* adjustSize(int* array, int& capacity, int newCapacity);
void minimize(int*& array, int& length, int& capacity);

int* adjustSize(int* array, int& capacity, int newCapacity) {
    int* tempArray = new int[newCapacity];
    for (int i = 0; i < capacity; i++) {
        tempArray[i] = array[i];
    }
    delete[] array;
    capacity = newCapacity;
    return tempArray;
}

void append(int*& array, int& length, int& capacity, int value) {
    if (length == capacity) {
        array = adjustSize(array, capacity, capacity * 2);
    }
    array[length++] = value;
}

void minimize(int*& array, int& length, int& capacity) {
    if (length < capacity) {
        array = adjustSize(array, capacity, length);
    }
}

int main() {
    int capacity = 5;
    int length = 0;
    int* array = new int[capacity];

    while (true) {
        string input;
        cout << "Enter a number (or 'e' to exit): ";
        cin >> input;

        if (input == "e") {
            break;
        }

        int value = stoi(input);
        append(array, length, capacity, value);
    }

    cout << "Array: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Size: " << length << ", Capacity before shrinking: " << capacity << endl;

    minimize(array, length, capacity);

    cout << "Size: " << length << ", Capacity after shrinking: " << capacity << endl;

    delete[] array;
    return 0;
}
