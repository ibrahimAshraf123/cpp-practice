using namespace std;

#include <iostream>

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

int CalculateMonthlyPayment(int Loan, int Months)
{
	return Loan / Months;
}

int main()
{
	int LoanAmount = ReadPositiveNumber("Please enter Loan amount:");
	int HowManyMonths = ReadPositiveNumber("Please enter How Many Months:");

	cout << endl << "Monthly Payments = " << CalculateMonthlyPayment(LoanAmount, HowManyMonths) << endl;

	return 0;
}
