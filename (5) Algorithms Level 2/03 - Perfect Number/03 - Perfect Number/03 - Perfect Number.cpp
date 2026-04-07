#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

bool isPerfectNumber(int Num)
{
	int SumOfAllDivisors = 0;
	for (int i = 1; i < Num; i++)
	{
		if (Num % i == 0)
			SumOfAllDivisors += i;
	}

	if (Num == SumOfAllDivisors)
	{
		cout << "Sum Of All Divisors = " << SumOfAllDivisors << endl;
		return 1;
	}
	else
		return 0;
}

void PrintResults(int Num)
{
	if (isPerfectNumber(Num))
		cout << Num << " is Perfect\n";
	else
		cout << Num << " is Not Perfect\n";
}

int main()
{
	PrintResults(ReadPositiveNumber("Enter a positive number:"));

	return 0;
}