
#include <iostream>
using namespace std;

int main()
{
    int loan, months;
    cout << "This program calculates \"Monthly Loan Installment\"... \n";
    cout << "Please enter loan amount: \n";
    cin >> loan;
    cout << "\n";

    cout << "Please enter number of months: \n";
    cin >> months;
    cout << "\n";

    int monthlyPay = loan / months;

    cout << "Result: \n";
    cout << monthlyPay << " Monthly payments. \n";


    return 0;
}


