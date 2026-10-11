using namespace std;

#include <iostream>

float ReadPositiveNumber(string Message)
{
    float Number;
    cout << Message << endl;
    cin >> Number;

    return Number;
}

float CalculateRemainder(float TotalBill, float CashPaid)
{
    float Remainder = CashPaid - TotalBill;

    return Remainder;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Please Enter Total Bill:");
    float CashPaid = ReadPositiveNumber("Please Enter Cash Paid:");

    cout << endl;
    cout << "Total Bill: " << TotalBill << endl;
    cout << "Cash Paid: " << CashPaid << endl;

    cout << "*************************" << endl;
    cout << "Remainder: " << CalculateRemainder(TotalBill, CashPaid) << endl;

    return 0;
}
