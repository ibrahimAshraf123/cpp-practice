using namespace std;

#include <iostream>

int ReadPositiveNumber(string Message)
{ 
	int N;
	do
	{
		cout << Message << endl;
		cin >> N;
	} while (N < 0);
	return N;
}

int CalculateLoanInstalmentMonths(int Loan, int MonthlyPayment)
{
	return Loan / MonthlyPayment;
}

int main()
{

	int Loan = ReadPositiveNumber("Please enter Loan amount: ");
	int MonthlyPayment = ReadPositiveNumber("Please enter Monthly Payment amount: ");

	cout << endl;
	cout << CalculateLoanInstalmentMonths(Loan, MonthlyPayment) << " Months" << endl;

	return 0;
}
