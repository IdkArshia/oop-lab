#include<iostream>
using namespace std;

class LoanHelper {
    float interestRate;
public:
    LoanHelper(float rate) {
        if (rate < 0 || rate > 0.5) {
            cout << "Invalid interest rate. Setting tof default 0.5%." << endl;
            interestRate = 0.005;
        } else {
            interestRate = rate / 100;
        }
    }
    void calculateMonthlyPayment(int loanAmount, int months) {
        if (months <= 0) {
            cout << "Invalid number of months." << endl;
            return;
        }
        float monthlyPayment = (loanAmount / months) + (loanAmount * interestRate);
        cout << "You have to pay Rs." << monthlyPayment << " every month for " << months << " months to repay your loan." << endl;
    }
};

int main() {
    float rate;
    int amount,months;
    cout << "Enter interest rate (between 0 and 0.5%): ";
    cin >> rate;
    LoanHelper loan(rate);
    cout<<"enter amount: ";
    cin>>amount;
    cout<<"enter no. of months:";
    cin>>months;
    loan.calculateMonthlyPayment(amount,months);
    return 0;
}
