using namespace std;

#include <iostream>

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int N;
	cout << "Enter Number:\n";
	cin >> N;

	return N;
}

enOddOrEven CheckOddOrEven(int N)
{
	if (N % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

int SumEvenNumbersFrom1ToN_UsingFor(int N)
{
	cout << "Sum of Even Numbers From 1 To " << N << " Using For statement:\n";
	int Sum = 0;
	int Counter = 0;

	for (Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingWhile(int N)
{
	cout << "Sum of Even Numbers From 1 To " << N << " Using While statement:\n";
	int Sum = 0;
	int Counter = 0;

	while (Counter <= N)
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingDoWhile(int N)
{
	cout << "Sum of Even Numbers From 1 To " << N << " Using Do While statement:\n";
	int Sum = 0;
	int Counter = 0;

	do
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	} while (Counter <= N);
	return Sum;
}

void PrintSum(int Sum)
{
	cout << Sum << endl;
}

int main()
{
	int N = ReadNumber();

	PrintSum(SumEvenNumbersFrom1ToN_UsingFor(N));
	PrintSum(SumEvenNumbersFrom1ToN_UsingWhile(N));
	PrintSum(SumEvenNumbersFrom1ToN_UsingDoWhile(N));

	return 0;
}
