

#include <iostream>
using namespace std;

int main()
{
    float loan, montlhyPayment;
    cout << "This program calculates \"Loan Instalment Months\" ... \n";
    cout << "Please enter loan amount = \n";
    cin >> loan;
    cout << "\n";

    cout << "Please enter monthly payment amount = \n";
    cin >> montlhyPayment;
    cout << "\n";

    int months = loan / montlhyPayment;

    cout << "Result: \n";
    cout << months << " Months. \n";



    return 0;
}


