#include<iostream>
#include<stdexcept>
using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 1 and 119";
    }
};

class InvalidSalaryException : public exception {
public:
    const char* what() const noexcept override {
        return "Salary must be positive";
    }
};

class InvalidHeightException : public exception {
public:
    const char* what() const noexcept override {
        return "Height must be positive";
    }
};

int main() {
    int age;
    double salary, height;

    try {
        cout << "Enter age: ";
        cin >> age;
        if (age <= 0 || age >= 120) throw InvalidAgeException();
    } catch (InvalidAgeException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Enter salary: ";
        cin >> salary;
        if (salary <= 0) throw InvalidSalaryException();
    } catch (InvalidSalaryException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Enter height (in cm): ";
        cin >> height;
        if (height <= 0) throw InvalidHeightException();
    } catch (InvalidHeightException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
