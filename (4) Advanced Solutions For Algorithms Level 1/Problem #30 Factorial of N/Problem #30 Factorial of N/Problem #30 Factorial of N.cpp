using namespace std;

#include <iostream>

double ReadNumber()
{
	double N;
	cout << "Enter Number: ";
	cin >> N;

	return N;
}

bool CheckForPositiveNumber(double N)
{
	if (N >= 0)
		return true;
	else
		return false;
}

double FactorialOfNumber(double N)
{
	while (CheckForPositiveNumber(N) == false)
	{
		cout << "\n*** ERROR ***\nNumber must be positive\n";
		N = ReadNumber();
	}

	double Factorial = 1;
	double Counter = 0;

	for (Counter = N; Counter >= 1; Counter--)
	{
		Factorial *= Counter;
	}
	return Factorial;
}

void PrintFactorial(double Factorial)
{
	cout << "\nFactorial = " << Factorial << endl;
}

int main()
{
	PrintFactorial(FactorialOfNumber(ReadNumber()));

	return 0;
}
