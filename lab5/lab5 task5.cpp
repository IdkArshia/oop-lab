#include <iostream>
#include<string>
using namespace std;

class ValidateString{
	private:
		string word;
	public:
		ValidateString(string w){
			word=w;
		}
	bool check() const {
        for (char ch : word) {
            if ((ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z')) {
                return false;
            }
        }
        return true;
    }
    void show() const {
        if (check()) {
            cout << "\"" << word << "\" is valid \n";
        } else {
            cout << "\"" << word << "\" is invalid\n";
        }
    }

};


int main() {
    string Input;
    cout << "Enter a word: : ";
    cin >> Input;

    ValidateString w1(Input);
    w1.show();

    return 0;
}