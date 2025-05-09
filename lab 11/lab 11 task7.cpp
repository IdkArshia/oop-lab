#include <iostream>
#include <string>
#include <exception>
using namespace std;

class OutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid index access attempted";
    }
};

template <typename T>
class SmartArray {
    T* data;
    int size;

public:
    SmartArray(int size) : size(size) {
        if (size <= 0) throw invalid_argument("Size must be positive");
        data = new T[size];
    }

    ~SmartArray() {
        delete[] data;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw OutOfBoundsException();
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        int size;
        cout << "Array size: ";
        cin >> size;

        SmartArray<int> intArray(size);
        cout << "Enter elements: ";
        for (int i = 0; i < size; ++i) cin >> intArray[i];

        cout << "Accessing index 2: " << intArray[2] << endl;
        cout << "Accessing index 5: " << endl;
        cout << intArray[5] << endl;
    } catch (const OutOfBoundsException& e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    try {
        SmartArray<string> strArray(3);
        strArray[0] = "Machine";
        strArray[1] = "Learning";
        strArray[2] = "Model";
        cout << "String at index 1: " << strArray[1] << endl;
        cout << "Accessing index 3: " << strArray[3] << endl;
    } catch (const OutOfBoundsException& e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    return 0;
}
